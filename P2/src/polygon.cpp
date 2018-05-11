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

	for (size_t pathNumber = 0; pathNumber < this->paths->size(); pathNumber++) {
		path_t path = this->paths->at(pathNumber);

		if (*this->id == "Bayern") {
			Line first = *path->at(0);
			Line second = *path->at(1);
//			cout << "First: " << first.toString() << endl;
//			cout << "Second: " << second.toString() << endl;
		}

		double tmp = expanse;

		for (size_t lineIndex = 0; lineIndex < path->size(); lineIndex++) {
			Line l = *(path->at(lineIndex));
			expanse += l.getExpanseOverXLine();
		}

		if (*this->id == "Bremen") {
//			cout << "Fläche " << pathNumber << ": " << (expanse - tmp) << endl;
		}
	}

	return expanse;
}

int Polygon::getPathCount() {
	return this->paths->size();
}

string* Polygon::getId() {
	return this->id;
}
