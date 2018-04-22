#include <iostream>
#include <fstream>
#include <vector>
#include "Line.h"

using namespace std;

const string FILE_1 = "input/s_1000_1.dat";
const string FILE_2 = "input/s_10000_1.dat";
const string FILE_3 = "input/s_100000_1.dat";

void readInputFile(string file, vector<Line*>* lines);
void calculateFile(string file);

int main() {
	calculateFile(FILE_1);
	calculateFile(FILE_2);
	calculateFile(FILE_3);

	return 0;
}

void calculateFile(string file) {
	cout << "\nStarte mit Berechnung File: " << file << "\n\n";

	std::vector<Line*> lines;
	readInputFile(file, &lines);

	for (size_t i = 0; i < lines.size(); i++) {
		Line *lineToConsider = lines.at(i);

		for (size_t j = i + 1; j < lines.size(); j++) {
			Line *otherLine = lines.at(j);

			double r1 = lineToConsider->ccw(otherLine->getStartPoint());
			double r2 = lineToConsider->ccw(otherLine->getEndPoint());

			if (r1 == 0 && r2 == 0) {
				if (lineToConsider->contains(otherLine->getStartPoint())
						|| lineToConsider->contains(otherLine->getStartPoint())) {
					cout << "Line " << i << " schneidet kollinear mit Linie " << j << "\n";
				}

				continue;
			}

			double product = r1 * r2;
			if (product <= 0) {
				cout << "Line " << i << " kreuzt Line " << j << "\n";
			}
		}
	}
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
