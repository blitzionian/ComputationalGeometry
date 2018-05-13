#include <country.hpp>
#include <iostream>
#include <algorithm>
#include <stdlib.h>

inline short int signum(double val);

Country::Country(string* name, vector<path_t>* polygons) :
		name(name), polygons(polygons) {
}

Country::~Country() {
}

double Country::getExpanse() {
	double expanse = 0.0;

	for (size_t polygonIndex = 0; polygonIndex < this->polygons->size(); polygonIndex++) {
		path_t path = this->polygons->at(polygonIndex);

		for (size_t lineIndex = 0; lineIndex < path->size(); lineIndex++) {
			Line l = *(path->at(lineIndex));
			expanse += l.getExpanseOverXLine();
		}
	}

	return expanse;
}

int Country::getPathCount() {
	return this->polygons->size();
}

string* Country::getName() {
	return this->name;
}

std::vector<Country::vertex> Country::vertices() {
	std::vector<vertex> result;
	// for each path
	for (std::vector<path_t>::iterator outer = polygons->begin(); outer != polygons->end(); ++outer) {
		std::vector<Line*> path = *(*outer);
		// for each line
		for (std::vector<Line*>::iterator inner = path.begin(); inner != path.end(); ++inner) {
			Line l = *(*inner);
			result.push_back(&l.getStartPoint());
		}
	}
	return result;
}

Point Country::maxCoordinates() {
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

bool Country::includesPoint(Point & point) {
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