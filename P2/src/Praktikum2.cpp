#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <chrono>

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

	NSVGshape* shape;
	for (shape = image->shapes; shape != NULL; shape = shape->next) {
		NSVGpath* path;
		cout << shape->id << endl;

		int count = 0;
		for (path = shape->paths; path != NULL; path = path->next) {
			count++;

			Point* lastPoint;

			for (int i = 0; i < path->npts - 1; i += 6) {

				Point nextPoint(path->pts[i], path->pts[i + 1]);

				if (strcmp(shape->id, "Berlin") == 0) {
					cout << nextPoint.toString() << endl;
				}

				lastPoint = &nextPoint;
			}
		}
	}

//	nsvgDelete(image);
}

