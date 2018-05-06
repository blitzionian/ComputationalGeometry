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

#include <stdio.h>
#include <string.h>
#include <math.h>

#define NANOSVG_IMPLEMENTATION
#include "nanosvg.h"

using namespace std;

const char* FILE_1 = "input/DeutschlandMitStaedten.svg";

vector<Polygon*>* readPolygonsFromSvg(const char* svgFile);

int main() {
	vector<Polygon*>* polygons = readPolygonsFromSvg(FILE_1);

	vector<Polygon*>::iterator itr;
	for (itr = polygons->begin(); itr != polygons->end(); ++itr) {
		cout << *(*itr)->getId() << '\n';
	}

	cout << endl;
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

		vector<Line*>* edges = new vector<Line*>();
		Polygon* polygon = new Polygon(new string(shape->id), edges);
		polygons->push_back(polygon);

		int count = 0;
		for (path = shape->paths; path != NULL; path = path->next) {
			count++;

			Point* firstPoint = NULL;
			Point* lastPoint = NULL;

			for (int i = 0; i < path->npts - 1; i += 6) {
				Point* nextPoint = new Point(path->pts[i], path->pts[i + 1]);

				if (firstPoint == NULL) {
					firstPoint = nextPoint;
				}

				if (lastPoint != NULL) {
					Line* newLine = new Line(*lastPoint, *nextPoint);
					edges->push_back(newLine);
				}

				lastPoint = nextPoint;
			}

			edges->push_back(new Line(*lastPoint, *firstPoint));
		}
	}

	return polygons;
}

