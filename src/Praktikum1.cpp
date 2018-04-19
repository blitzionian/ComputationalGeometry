#include <iostream>
#include <fstream>
#include <list>
#include "Line.h"

using namespace std;

const string FILE_1 = "input/s_1000_1.dat";

int main() {
	ifstream inStream;
	inStream.open(FILE_1);

	std::list<Line*> lines;

	while (!inStream.eof()) {
		double x1;
		inStream >> x1;

		double y1;
		inStream >> y1;

		double x2;
		inStream >> x2;

		double y2;
		inStream >> y2;

		Point *p1 = new Point(x1, y1);
		Point *p2 = new Point(x2, y2);

		Line *line = new Line(*p1, *p2);

		lines.push_back(line);
	}

	for (Line* line : lines) {
		cout << line->toString() << "\n";
	}

	return 0;
}
