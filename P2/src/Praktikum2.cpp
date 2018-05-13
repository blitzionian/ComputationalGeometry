#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <chrono>
#include <iterator>
#include <map>
#include <stdio.h>
#include <string.h>
#include <math.h>

#include <point.hpp>
#include <line.hpp>
#include <polygon.hpp>
#include <country.hpp>
#include <parse_cities.hpp>

#define NANOSVG_IMPLEMENTATION
#include "nanosvg.h"

using namespace std;

const char* FILE_1 = "input/DeutschlandMitStaedten.svg";

vector<Country*>* readPolygonsFromSvg(const char* svgFile);

int main() {
	vector<Country*>* countries = readPolygonsFromSvg(FILE_1);

	vector<Country*>::iterator itr;
	for (itr = countries->begin(); itr != countries->end(); ++itr) {
		Country country = *(*itr);
		cout << "Fläche von " << *country.getName() << ": " << country.getExpanse();
		cout << " (Anzahl Pfade: " << country.getPathCount() << ")";
		cout << endl;
	}

	cout << endl;
	city_parser::city_list cities = city_parser::from_file(FILE_1);
	for (city_parser::city_itr it = cities.begin(); it != cities.end(); ++it) {
		city_parser::city c = *it;
		cout << "{'name': '" << c.name << "', 'x': " << c.coordinate.getX() << ", 'y': " << c.coordinate.getY() << "}"
				<< endl;
	}
}

/**
 * Liest alle Polygone aus der gegebenen SVG Datei.(In unserem Fall die Liste der Bundesländer)
 * Jedes Polygon besteht aus einer Liste von Strecken (siehe line.hpp). Der Anfangspunkt einer Strecke entspricht dem
 * Endpunkt der vorhergehenden Strecke. Das Polygon ist geschlosse, dass heißt der Letzte Punkt entspricht dem ersten Punkt.
 */
vector<Country*>* readPolygonsFromSvg(const char* svgFile) {
	struct NSVGimage* image;
	image = nsvgParseFromFile(FILE_1, "px", 96);

	vector<Country*>* countries = new vector<Country*>();

	// Lese alle Shapes (Bundesländer)
	NSVGshape* shape;
	for (shape = image->shapes; shape != NULL; shape = shape->next) {
		vector<Polygon*>* polygonsOfCountry = new vector<Polygon*>();

		Country* newCountry = new Country(new string(shape->id), polygonsOfCountry);
		countries->push_back(newCountry);

//		// Lese alle Pfade des aktuellen Bundeslandes (alle Polygone, Inseln, Löcher etc)
		NSVGpath* path;
		for (path = shape->paths; path != NULL; path = path->next) {
			vector<Line*>* edges = new vector<Line*>();

			Polygon* newPolygon = new Polygon(edges);
			polygonsOfCountry->push_back(newPolygon);

			Point* firstPoint = NULL;
			Point* lastPoint = NULL;

//			// Lese alle Edges des akutellen Pfades (Polygons)
			for (int i = 0; i < path->npts - 1; i += 3) {
				float* points = &path->pts[i * 2];
				Point* nextPoint = new Point(points[0], points[1]);

				if (firstPoint == NULL) {
					firstPoint = nextPoint;
				}

				if (lastPoint != NULL) {
					Line* newEdge = new Line(*lastPoint, *nextPoint);
					edges->push_back(newEdge);
				}

				lastPoint = nextPoint;
			}
		}
	}

	return countries;
}
