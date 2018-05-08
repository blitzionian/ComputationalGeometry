#include "polygon.hpp"

#include <iostream>

Polygon::Polygon(string* id, vector<path_t>* paths) :
		id(id), paths(paths) {
}

Polygon::~Polygon() {
}

double Polygon::getExpanse() {
	double expanse = 0.0;
//	Point zero(0, 0);

//	cout << *this->id << this->paths->size() << endl;

	for (size_t i = 0; i < this->paths->size(); i++) {
		path_t path = this->paths->at(i);

		for (size_t pathIndex = 0; pathIndex < path->size(); pathIndex++) {
			Line l = *(path->at(i));
			expanse += l.getExpanseOverXLine();
		}
	}

	return expanse;
}

string* Polygon::getId() {
	return this->id;
}
