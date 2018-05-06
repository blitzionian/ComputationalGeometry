#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <chrono>
#include <iterator>
#include <map>

#include "point.hpp"
#include "line.hpp"

#include <stdio.h>
#include <string.h>
#include <math.h>

#define NANOSVG_IMPLEMENTATION
#include "nanosvg.h"

using namespace std;

const char* FILE_1 = "input/DeutschlandMitStaedten.svg";

map<string*, vector<Line*>*>* readPolygonFromSvg(const char* svgFile);

int main() {
	map<string*, vector<Line*>*>* polygonMap = readPolygonFromSvg(FILE_1);

	map<string*, vector<Line*>*>::iterator itr;
	for (itr = polygonMap->begin(); itr != polygonMap->end(); ++itr) {
		cout << *itr->first << '\n';
	}

	cout << endl;
}

/**
 * Liest alle Pfade aus der gegebenen SVG Datei. Die Pfade sind in der zurückgegebenen Map enthalten.
 * Der Key der Map ist die id des Pfades. (In unserem Fall der Name des Bundeslandes)
 */
map<string*, vector<Line*>*>* readPolygonFromSvg(const char* svgFile) {
	struct NSVGimage* image;
	image = nsvgParseFromFile(FILE_1, "px", 96);

	map<string*, vector<Line*>*>* polygonMap = new map<string*, vector<Line*>*>();

	NSVGshape* shape;
	for (shape = image->shapes; shape != NULL; shape = shape->next) {
		NSVGpath* path;

		vector<Line*>* newBundesland = new vector<Line*>();
		string* name = new string(shape->id, 63);
		polygonMap->insert(pair<string*, vector<Line*>*>(name, newBundesland));

		int count = 0;
		for (path = shape->paths; path != NULL; path = path->next) {
			count++;

			Point* firstPoint;
			Point* lastPoint;

			for (int i = 0; i < path->npts - 1; i += 6) {
				Point nextPoint(path->pts[i], path->pts[i + 1]);

				if (firstPoint == NULL) {
					firstPoint = &nextPoint;
				}

				if (lastPoint != NULL) {
					Line* newLine = new Line(*lastPoint, nextPoint);
					newBundesland->push_back(newLine);
				}

				lastPoint = &nextPoint;
			}

			newBundesland->push_back(new Line(*lastPoint, *firstPoint));
		}
	}

	return polygonMap;
}

