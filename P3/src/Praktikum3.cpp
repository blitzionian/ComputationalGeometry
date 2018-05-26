#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <chrono>
#include <algorithm>

#include <line.hpp>
#include <sweepLine.hpp>

using namespace std;
using namespace std::chrono;

const string FILE_1 = "input/s_1000_1.dat";
const string FILE_2 = "input/s_10000_1.dat";
const string FILE_3 = "input/s_100000_1.dat";
const string FILE_4 = "input/s_1000_10.dat";

void readInputFile(string file, vector<Line*>* lines);
void calculateFile(string file);
int64_t currentTime(void);
bool isSpecialCase(Line lineToCheck);
void searchAndFilterForDoublePoints(vector<Line*>* lines);

int main() {
	calculateFile(FILE_1);
	cout << endl;
//	calculateFile(FILE_2);
	cout << endl;
//	calculateFile(FILE_3);
	cout << endl;
//	calculateFile(FILE_4);

	return 0;
}

void calculateFile(string file) {
	cout << "Starte mit Berechnung File: " << file << endl;

	vector<Line*>* lines = new vector<Line*>();
	readInputFile(file, lines);
	searchAndFilterForDoublePoints(lines);

	int64_t start = currentTime();

	SweepLine sweepline(*lines);
	sweepline.calculateResult();
//	sweepline.printEventQueue();

	int64_t duration = currentTime() - start;
	cout << "Duration: " << duration << endl;
	cout << "Count: " << sweepline.getCrossCount() << endl;
}

vector<Point>::iterator searchInVector(vector<Point> data, Point pointToSearch) {
	return find(data.begin(), data.end(), pointToSearch);
}

bool vectorContains(vector<Point> data, Point pointToSearch) {
	vector<Point>::iterator foundStartPoint = searchInVector(data, pointToSearch);

	return foundStartPoint != data.end();
}

void searchAndFilterForDoublePoints(vector<Line*>* lines) {
	vector<Point> pointList;

	vector<Line*>::iterator lineIter;
	for (lineIter = lines->begin(); lineIter != lines->end(); lineIter++) {
		Line* line = *lineIter;

		bool containsStart = vectorContains(pointList, *line->getStartPoint());
		bool containsEnd = vectorContains(pointList, *line->getEndPoint());

		if (containsStart || containsEnd) {
			lines->erase(lineIter);
		} else {
			pointList.push_back(*line->getStartPoint());
			pointList.push_back(*line->getEndPoint());
		}
	}
}

bool isSpecialCase(Line lineToCheck) {
	if (lineToCheck.isPoint()) {
		return true;
	}

	Point* startPoint = lineToCheck.getStartPoint();
	Point* endPoit = lineToCheck.getEndPoint();

	if (startPoint->getY() == endPoit->getY()) {
		return true;
	}

	return false;
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

		Line *line = new Line(p1, p2);

		if (!isSpecialCase(*line)) {
			lines->push_back(line);
		}
	}

	inStream.close();
}

int64_t currentTime() {
	return duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
}
