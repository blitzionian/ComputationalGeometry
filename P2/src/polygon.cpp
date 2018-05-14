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

bool Polygon::includesPoint(Point* point) {
	bool includesPoint = false;
	Point max = maxCoordinates();
	Point outer(max.getX() + 10, max.getY() + 10);

	Line ref(&outer, point);

	vector<Point*>::iterator current = this->knots->begin();
	while (current != this->knots->end() && 0.0 == ref.ccw(*current)) {
		++current;
	}

	if (current != this->knots->end()) {
		unsigned int count = 0;
		short int outer_signum = signum(ref.ccw(*current));

		for (vector<Point*>::iterator it(current); it != this->knots->end(); ++it) {
			short int inner_signum = signum(ref.ccw(*it));

			if (2 == abs(inner_signum - outer_signum)) {
				outer_signum = inner_signum;
				vector<Point*>::iterator cpy(it);
				--cpy;
				Line inner_ref(*cpy, *it);
				double ccws = inner_ref.ccw(&outer) * inner_ref.ccw(point);
				if (ccws <= 0) {
					++count;
				}
			}
		}

		includesPoint = (0 != count % 2);
	}

	return includesPoint;
}

vector<Point*>* Polygon::getKnots() {
	return this->knots;
}

inline short int signum(double val) {
	short int answer = 0;
	if (val < 0.0) {
		answer = -1;
	}
	if (val > 0.0) {
		answer = 1;
	}
	return answer;
}
