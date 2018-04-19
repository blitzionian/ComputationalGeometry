//============================================================================
// Name        : Praktikum1.cpp
// Author      : Markus Hüttner
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <vector>
#include "Line.h"

using namespace std;

const string FILE_1 = "input/s_1000_1.dat";

int main() {
	ifstream inStream;
	inStream.open(FILE_1);

	std::vector<Line> lines;

	while (!inStream.eof()) {
		double x1;
		inStream >> x1;

		double y1;
		inStream >> y1;

		double x2;
		inStream >> x2;

		double y2;
		inStream >> y2;

		Point p1 = Point(x1, y1);
		Point p2 = Point(x2, y2);

		Line line = Line(p1, p2);

		printf("%f %f %f %f\n", p1.getX(), p1.getY(), x2, y2);
	}

	return 0;
}
