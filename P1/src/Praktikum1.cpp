#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <chrono>
#include "line.hpp"

using namespace std;
using namespace std::chrono;

const string FILE_1 = "input/s_1000_1.dat";
const string FILE_2 = "input/s_10000_1.dat";
const string FILE_3 = "input/s_100000_1.dat";
const string FILE_4 = "input/s_1000_10.dat";

void readInputFile(string file, vector<Line*>* lines);
void calculateFile(string file);
int64_t currentTime(void);

int main() {
	calculateFile(FILE_1);
	calculateFile(FILE_2);
	calculateFile(FILE_3);
	calculateFile(FILE_4);

	return 0;
}

void calculateFile(string file) {
	cout << endl << "Starte mit Berechnung File: " << file << endl << endl;
	int count = 0;

	std::vector<Line*> lines;
	readInputFile(file, &lines);

	int64_t start = currentTime();

	for (size_t i = 0; i < lines.size(); i++) {
		Line *lineToConsider = lines.at(i);
		bool isPoint = lineToConsider->isPoint();

		for (size_t j = i + 1; j < lines.size(); j++) {
			Line *otherLine = lines.at(j);

			if (isPoint) {
				if (otherLine->isPoint()) {
					if (lineToConsider->getStartPoint() == otherLine->getStartPoint()) {
//						cout << i << " : " << j << endl;
						count++;
					}
				} else {
					if (otherLine->cross(*lineToConsider)) {
//						cout << i << " : " << j << endl;
						count++;
					}
				}
			} else {
				if (lineToConsider->cross(*otherLine)) {
//					cout << i << " : " << j << endl;
					count++;
				}
			}
		}
	}

	int64_t duration = currentTime() - start;
	cout << "Duration: " << duration << endl;
	cout << "Count: " << count << endl;
}

void readInputFile(string file, vector<Line*>* lines) {
	ifstream inStream;
	inStream.open(file);

	while (!inStream.eof()) {
		string lineFromFile;
		getline(inStream, lineFromFile);

		if (lineFromFile.empty()) {
			continue;
		}

		istringstream tmp(lineFromFile);

		double x1;
		tmp >> x1;

		double y1;
		tmp >> y1;

		double x2;
		tmp >> x2;

		double y2;
		tmp >> y2;

		Point *p1 = new Point(x1, y1);
		Point *p2 = new Point(x2, y2);

		Line *line = new Line(*p1, *p2);

		lines->push_back(line);
	}

//	cout << "readed: " << lines->size() << endl;

	inStream.close();
}

int64_t currentTime() {
	return duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
}
