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

	cout << "Anzahl Edges: " << this->edges.size() << endl;

	for (size_t edgeIndex = 0; edgeIndex < this->edges.size(); edgeIndex++) {
		Line* edge = this->edges.at(edgeIndex);
		expanse += edge->getExpanseOverXLine();
	}

	return expanse;
}

vector<Polygon::vertex> Polygon::vertices() {
	vector<vertex> result;

	// for each Line
	for (vector<Line*>::iterator outer = edges.begin(); outer != edges.end(); ++outer) {
		Line* l = *outer;
		result.push_back(l->getStartPoint());
	}

	return result;
}

Point Polygon::maxCoordinates() {
	vector<double> x;
	vector<double> y;
	vector<vertex> v = vertices();

	for (vector<vertex>::iterator it = v.begin(); it != v.end(); ++it) {
		Point p = *(*it);
		x.push_back(p.getX());
		y.push_back(p.getY());
	}

	std::sort(x.begin(), x.end(), [](double first, double second) {return (first < second);});
	std::sort(x.begin(), x.end(), [](double first, double second) {return (first < second);});
	return Point(x.back(), y.back());
}

bool Polygon::includesPoint(Point & point) {
	bool answer = false;
	Point max = maxCoordinates();
	Point outer(max.getX() + 10, max.getY() + 10);
	vector<vertex> v = vertices();
	Line ref(&outer, &point);
	vector<vertex>::iterator current = v.begin();
	while (current != v.end() && 0.0 == ref.ccw(*(*current))) {
		++current;
	}
	if (current != v.end()) {
		unsigned int count = 0;
		short int outer_signum = signum(ref.ccw(*(*current)));
		for (vector<vertex>::iterator it(current); it != v.end(); ++it) {
			short int inner_signum = signum(ref.ccw(*(*it)));
			if (2 == abs(inner_signum - outer_signum)) {
				outer_signum = inner_signum;
				vector<vertex>::iterator cpy(it);
				--cpy;
				Line inner_ref(*cpy, *it);
				double ccws = inner_ref.ccw(outer) * inner_ref.ccw(point);
				if (ccws <= 0) {
					++count;
				}
			}
		}
		answer = (0 != count % 2);
	}
	return answer;
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
