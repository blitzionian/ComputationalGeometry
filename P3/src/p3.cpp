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
	lines = searchAndFilterForDoublePoints(lines);
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

bool vectorContains(vector<Point> data, Point pointToSearch) {
	vector<Point>::iterator foundStartPoint = find(data.begin(), data.end(), pointToSearch);

	return foundStartPoint != data.end();
}

bool setContains(set<Point> data, Point pointToSearch) {
	set<Point>::iterator foundStartPoint = data.find(pointToSearch);
	return foundStartPoint != data.end();
}

vector<Line*>* searchAndFilterForDoublePoints(vector<Line*>* lines) {
	cout << "Start filter" << endl;
	set<Point> pointSet;

	vector<Line*>* filteredLines = new vector<Line*>();

	vector<Line*>::iterator lineIter;
	vector<Line*>::iterator end = lines->end();

	for (lineIter = lines->begin(); lineIter != end; ++lineIter) {
		Line* line = *lineIter;

		Point startPoint = *line->getStartPoint();

		bool containsStart = setContains(pointSet, startPoint);
		if (!containsStart) {
			Point endPoint = *line->getEndPoint();
			bool containsEnd = setContains(pointSet, endPoint);

			if (!containsEnd) {
				pointSet.insert(startPoint);
				pointSet.insert(endPoint);

				filteredLines->push_back(line);
			}
		}
	}

	cout << "End filter, Size: " << filteredLines->size() << endl;
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
