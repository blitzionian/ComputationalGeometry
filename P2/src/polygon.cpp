#include <polygon.hpp>

#include <algorithm>
#include <stdlib.h>

#include <iostream>

inline short int signum(double val);

using namespace std;

Polygon::Polygon(vector<Point*> *knots) :
		knots(knots) {

	for (size_t index = 0; index < knots->size() - 1; index++) {
		Point* startPoint = knots->at(index);
		Point* endPoint = knots->at(index + 1);

		Line* newEdge = new Line(startPoint, endPoint);
		this->edges.push_back(newEdge);
	}
}

Polygon::~Polygon() {
}

double Polygon::getExpanse() {
	double expanse = 0.0;

	for (size_t edgeIndex = 0; edgeIndex < this->edges.size(); edgeIndex++) {
		Line* edge = this->edges.at(edgeIndex);
		expanse += edge->getExpanseOverXLine();
	}

	return expanse;
}

Point Polygon::maxCoordinates() {
	vector<double> x;
	vector<double> y;

	for (vector<Point*>::iterator pointIterator = this->knots->begin(); pointIterator != this->knots->end();
			++pointIterator) {
		Point p = *(*pointIterator);
		x.push_back(p.getX());
		y.push_back(p.getY());
	}

	std::sort(x.begin(), x.end(), [](double first, double second) {return (first < second);});
	std::sort(x.begin(), x.end(), [](double first, double second) {return (first < second);});
	return Point(x.back(), y.back());
}

bool Polygon::includesPoint(Point* pointToCheck) {
	Point max = maxCoordinates();
	Point outer(max.getX() + 10, max.getY() + 10);

	Line toCheck(&outer, pointToCheck);

	size_t knotIndex = 0;

	while (knotIndex < this->knots->size()) {
		Point* firstPointToConsider = this->knots->at(knotIndex);
		double ccw = toCheck.ccw(firstPointToConsider);

		if (ccw != 0) {
			break;
		}

		knotIndex++;
	}

	int lastSignum = signum(toCheck.ccw(this->knots->at(knotIndex)));
	int crossCount = 0;

	for (knotIndex++; knotIndex < this->knots->size() - 1; knotIndex++) {
		Point* nextPoint = this->knots->at(knotIndex);

		double ccwNext = toCheck.ccw(nextPoint);
		int nextSignum = signum(ccwNext);

		// Wenn Knoten geschnitten wird
		if (ccwNext == 0 && toCheck.contains(*nextPoint)) {
			crossCount++;
			continue;
		}

		if (abs(nextSignum - lastSignum) == 2) {
			lastSignum = nextSignum;

			Point* previousPoint = this->knots->at(knotIndex - 1);
			Line edge(previousPoint, nextPoint);

			double ccwOuter = edge.ccw(&outer);
			double ccwPointToCheck = edge.ccw(pointToCheck);

			// Gesuchter Punkt liegt auf Kante
			if (ccwPointToCheck == 0 && edge.contains(*pointToCheck)) {
				return true;
			}

			// Schnittpunkt
			if (ccwOuter * ccwPointToCheck <= 0) {
				crossCount++;
			}
		}
	}

	return crossCount % 2 != 0;
}

vector<Point*>* Polygon::getKnots() {
	return this->knots;
}

inline short int signum(double val) {
	if (val < 0.0) {
		return -1;
	}
	if (val > 0.0) {
		return 1;
	}
	return 0;
}
