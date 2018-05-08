#include "polygon.hpp"

#include <iostream>

Polygon::Polygon(string* id, vector<path_t>* edges) :
		id(id), edges(edges) {
}

Polygon::~Polygon() {
}

double Polygon::getExpanse() {
	double expanse = 0.0;
	Point zero(0, 0);

//	for (size_t i = 0; i < this->edges->size(); i++) {
//		Line l = *(this->edges->at(i));
//		expanse += l.getExpanseOverXLine();
//	}

	return expanse;
}

string* Polygon::getId() {
	return this->id;
}
