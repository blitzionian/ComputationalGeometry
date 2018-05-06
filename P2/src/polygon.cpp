#include "polygon.hpp"

Polygon::Polygon(string* id, vector<Line*>* edges) :
		id(id), edges(edges) {
}

Polygon::~Polygon() {
}

string* Polygon::getId() {
	return this->id;
}
