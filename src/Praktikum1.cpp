#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include "Line.h"

using namespace std;
using namespace std::chrono;

const string FILE_1 = "input/s_1000_1.dat";
const string FILE_2 = "input/s_10000_1.dat";
const string FILE_3 = "input/s_100000_1.dat";

void readInputFile(string file, vector<Line*>* lines);
void calculateFile(string file);
int64_t currentTime(void);

int main() {
	calculateFile(FILE_1);
	calculateFile(FILE_2);
//	calculateFile(FILE_3);

	return 0;
}

void calculateFile(string file) {
	cout << "\nStarte mit Berechnung File: " << file << "\n\n";
	int count = 0;

	int64_t start = currentTime();

	std::vector<Line*> lines;
	readInputFile(file, &lines);

	for (size_t i = 0; i < lines.size(); i++) {
		Line *lineToConsider = lines.at(i);

		bool isPoint = lineToConsider->isPoint();

		for (size_t j = i + 1; j < lines.size(); j++) {
			Line *otherLine = lines.at(j);

			if (isPoint) {
				if (otherLine->contains(lineToConsider->getStartPoint())) {
					count++;
				}
			} else if (otherLine->isPoint()) {
				if (lineToConsider->contains(otherLine->getStartPoint())) {
					count++;
				}
			} else if (lineToConsider->crosses(*otherLine)) {
				count++;
			}
		}
	}

	int64_t duration = currentTime() - start;
	cout << "Duration: " << duration << "\n";
	cout << "Count: " << count << "\n";
}

void readInputFile(string file, vector<Line*>* lines) {
	ifstream inStream;
	inStream.open(file);

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

int64_t currentTime() {
	return duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
}
