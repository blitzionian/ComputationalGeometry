#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <chrono>
#include <iterator>
#include <map>

#include "point.hpp"
#include "line.hpp"
#include "polygon.hpp"
#include <parse_cities.hpp>

#include <stdio.h>
#include <string.h>
#include <math.h>

#define NANOSVG_IMPLEMENTATION
#include "nanosvg.h"

using namespace std;

const char* FILE_1 = "input/DeutschlandMitStaedten.svg";

vector<Polygon*>* readPolygonsFromSvg(const char* svgFile);

int main() {
	/*vector<Polygon*>* polygons = readPolygonsFromSvg(FILE_1);

	vector<Polygon*>::iterator itr;
	for (itr = polygons->begin(); itr != polygons->end(); ++itr) {
		Polygon polygon = *(*itr);
		cout << "Fläche von " << *polygon.getId() << ": " << polygon.getExpanse();
		cout << " (Anzahl Pfade: " << polygon.getPathCount() << ")";
		cout << endl;
	}

	cout << endl;*/
	city_parser::city_list cities = city_parser::from_file(FILE_1);
	for(city_parser::city_itr it = cities.begin(); it != cities.end(); ++it){
		city_parser::city c = *it;
		cout << "{'name': '" << c.name << "', 'x': " << c.coordinate.getX() << ", 'y': " << c.coordinate.getY() << "}" << endl;
	}
}

/**
 * Liest alle Pfade aus der gegebenen SVG Datei. Es wird eine Liste auf Polygon erstellt. Jedes Polygon representiert
 * einen Pfad. (In unserem Fall ein Bundesland)
 */
vector<Polygon*>* readPolygonsFromSvg(const char* svgFile) {
	struct NSVGimage* image;
	image = nsvgParseFromFile(FILE_1, "px", 96);

	vector<Polygon*>* polygons = new vector<Polygon*>();

	NSVGshape* shape;
	for (shape = image->shapes; shape != NULL; shape = shape->next) {
		NSVGpath* path;

		vector<path_t>* edges = new vector<path_t>();
		Polygon* polygon = new Polygon(new string(shape->id), edges);
		polygons->push_back(polygon);

		int count = 0;
		for (path = shape->paths; path != NULL; path = path->next) {
			count++;

			path_t newPath = new vector<Line*>();
			edges->push_back(newPath);

			Point* firstPoint = NULL;
			Point* lastPoint = NULL;

			for (int i = 0; i < path->npts - 1; i += 3) {
				float* points = &path->pts[i * 2];
				Point* nextPoint = new Point(points[0], points[1]);

				if (firstPoint == NULL) {
					firstPoint = nextPoint;
//					cout << "First Point: " << firstPoint->toString() << shape->id << endl;
				}

				if (lastPoint != NULL) {
					Line* newLine = new Line(*lastPoint, *nextPoint);

					if (*polygon->getId() == "Bayern") {
//						cout << newLine->toString() << endl;
//						cout << nextPoint->toString() << endl;
					}
					newPath->push_back(newLine);
				}

				lastPoint = nextPoint;
			}

//			newPath->push_back(new Line(*lastPoint, *firstPoint));
		}
	}

	return polygons;
}

