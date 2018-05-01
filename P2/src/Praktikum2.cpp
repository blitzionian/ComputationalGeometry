#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <chrono>

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
	// Use...
	NSVGshape* shape;
	for (shape = image->shapes; shape != NULL; shape = shape->next) {
		NSVGpath* path;
		for (path = shape->paths; path != NULL; path = path->next) {
			for (int i = 0; i < path->npts - 1; i += 3) {
				float* p = &path->pts[i * 2];

				cout << p[0] << " " << p[1] << endl;
			}
		}
	}
	// Delete
	nsvgDelete(image);
}

