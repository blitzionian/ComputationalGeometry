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

int main() {
	struct NSVGimage* image;
	image = nsvgParseFromFile(FILE_1, "px", 96);
	printf("size: %f x %f\n", image->width, image->height);

	map<char*, vector<Line>> polygonMap;

	NSVGshape* shape;
	for (shape = image->shapes; shape != NULL; shape = shape->next) {
		NSVGpath* path;

		vector<Line> newBundesland;
		polygonMap.insert(pair<char*, vector<Line>>(shape->id, newBundesland));

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
					Line newLine(*lastPoint, nextPoint);
					newBundesland.push_back(newLine);
				}

				lastPoint = &nextPoint;
			}

			newBundesland.push_back(Line(*lastPoint, *firstPoint));
		}
	}

	map<char*, vector<Line>>::iterator itr;
	for (itr = polygonMap.begin(); itr != polygonMap.end(); ++itr) {
		cout << itr->first << '\n';
	}
	cout << endl;

//	nsvgDelete(image);
}

