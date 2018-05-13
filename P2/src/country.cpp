#include <country.hpp>

#include <iostream>

Country::Country(string* name, vector<Polygon*> *polygons) :
		name(name), polygons(polygons) {
}

Country::~Country() {
}

double Country::getExpanse() {
	double expanse = 0.0;

	for (size_t polygonIndex = 0; polygonIndex < this->polygons->size(); polygonIndex++) {
		Polygon* polygon = this->polygons->at(polygonIndex);

		expanse += polygon->getExpanse();
	}

	return expanse;
}

int Country::getPathCount() {
	return this->polygons->size();
}

string* Country::getName() {
	return this->name;
}
