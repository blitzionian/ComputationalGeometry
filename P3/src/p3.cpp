#include <p3.hpp>

#include <iostream>
#include <sstream>
#include <fstream>
#include <chrono>
#include <algorithm>
#include <set>

#include <sweepLine.hpp>

using namespace std::chrono;

void calculateFile(string file) {
	cout << "Starte mit Berechnung File: " << file << endl;

	vector<Line*>* lines = new vector<Line*>();
	readInputFile(file, lines);
	lines = filterOverlappingLines(lines);

	int64_t start = currentTime();

	SweepLine sweepline(*lines);
	sweepline.calculateResult();
//	sweepline.printEventQueue();

	int64_t duration = currentTime() - start;
	cout << "Duration: " << duration << endl;
	cout << "Count: " << sweepline.getCrossCount() << endl;
}

vector<Line*>* filterOverlappingLines(vector<Line*>* lines) {
	vector<Line*>* filteredLines = new vector<Line*>();

	for (size_t outerIndex = 0; outerIndex < lines->size(); outerIndex++) {
		Line* outerLine = lines->at(outerIndex);
		bool overlap = false;

		for (size_t innerIndex = outerIndex + 1; innerIndex < lines->size(); innerIndex++) {
			Line* innerLine = lines->at(innerIndex);
			Point* p1 = innerLine->getStartPoint();
			Point* p2 = innerLine->getEndPoint();

			if (outerLine->containsReal(p1) || outerLine->containsReal(p2)) {
				overlap = true;
				cout << "contains" << endl;
				break;
			}
		}

		if (!overlap) {
			filteredLines->push_back(outerLine);
		}
	}

	return filteredLines;
}

bool isParallelToYAxis(Line lineToCheck) {
	Point* startPoint = lineToCheck.getStartPoint();
	Point* endPoit = lineToCheck.getEndPoint();

	if (startPoint->getY() == endPoit->getY()) {
		return true;
	}

	return false;
}

bool isSpecialCase(Line lineToCheck) {
	if (lineToCheck.isPoint()) {
		return true;
	}

	return isParallelToYAxis(lineToCheck);
}

void readInputFile(string file, vector<Line*>* lines) {
	ifstream inStream;
	inStream.open(file);

	set<double> xCoordSet;

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
			set<double>::iterator end = xCoordSet.end();
			set<double>::iterator foundX1 = xCoordSet.find(x1);
			if (foundX1 == end) {
				set<double>::iterator foundX2 = xCoordSet.find(x2);
				if (foundX2 == end) {
					xCoordSet.insert(x1);
					xCoordSet.insert(x2);
					lines->push_back(line);
				}
			}
		}
	}

	inStream.close();
}

int64_t currentTime() {
	return duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
}
