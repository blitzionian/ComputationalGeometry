#include <polygon.hpp>

#include <algorithm>
#include <stdlib.h>

inline short int signum(double val);

Polygon::Polygon(vector<Line*> *edges) :
		edges(edges) {
}

Polygon::~Polygon() {
}

double Polygon::getExpanse() {
	double expanse = 0.0;

	for (size_t edgeIndex = 0; edgeIndex < this->edges->size(); edgeIndex++) {
		Line* edge = this->edges->at(edgeIndex);
		expanse += edge->getExpanseOverXLine();
	}

	return expanse;
}

std::vector<Polygon::vertex> Polygon::vertices() {
	std::vector<vertex> result;

	// for each Line
	for (std::vector<Line*>::iterator outer = edges->begin(); outer != edges->end(); ++outer) {
		Line* l = *outer;
		result.push_back(&l->getStartPoint());
	}

	return result;
}

Point Polygon::maxCoordinates() {
	std::vector<double> x;
	std::vector<double> y;
	std::vector<vertex> v = vertices();

	for (std::vector<vertex>::iterator it = v.begin(); it != v.end(); ++it) {
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
	std::vector<vertex> v = vertices();
	Line ref(outer, point);
	std::vector<vertex>::iterator current = v.begin();
	while (current != v.end() && 0.0 == ref.ccw(*(*current))) {
		++current;
	}
	if (current != v.end()) {
		unsigned int count = 0;
		short int outer_signum = signum(ref.ccw(*(*current)));
		for (std::vector<vertex>::iterator it(current); it != v.end(); ++it) {
			short int inner_signum = signum(ref.ccw(*(*it)));
			if (2 == abs(inner_signum - outer_signum)) {
				outer_signum = inner_signum;
				std::vector<vertex>::iterator cpy(it);
				--cpy;
				Line inner_ref(*(*cpy), *(*it));
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
