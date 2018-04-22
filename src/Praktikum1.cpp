#include <iostream>
#include <fstream>
#include <vector>
#include "Line.h"

using namespace std;

const string FILE_1 = "input/s_1000_1.dat";

void readInputFile(string file, vector<Line*>* lines);

int main() {
	std::vector<Line*> lines;
	readInputFile(FILE_1, &lines);

	for (size_t i = 0; i < lines.size(); i++) {
		Line *lineToConsider = lines.at(i);

		for (size_t j = i + 1; j < lines.size(); j++) {
			Line *otherLine = lines.at(j);

			double r1 = lineToConsider->ccw(otherLine->getStartPoint());
			double r2 = lineToConsider->ccw(otherLine->getEndPoint());

			if (r1 == 0 && r2 == 0) {
				cout << "Line " << i << " kollinear mit Linie " << j << "\n";
				continue;
			}

//			cout << "Line " << i << ":" << j << "; P1: " << r1 << "; P2: " << r2 << "\n";

			double product = r1 * r2;

			if (product <= 0) {
				cout << "Line " << i << " kreuzt Line " << j << "\n";
			}
		}

		break;
	}

//	for (Line* line : lines) {
//
//		cout << line->toString() << "\n";
//	}

	return 0;
}

void readInputFile(string file, vector<Line*>* lines) {
	ifstream inStream;
	inStream.open(FILE_1);

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

		lines->push_back(line);
	}

	inStream.close();
}
