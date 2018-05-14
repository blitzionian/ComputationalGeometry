#include <country.hpp>

#include <iostream>
#include <math.h>

Country::Country(string* name, vector<Polygon*> *polygons) :
		name(name) {
	for (size_t polygonIndex = 0; polygonIndex < polygons->size(); polygonIndex++) {
		Polygon* polygon = polygons->at(polygonIndex);

		int polygonType = Polygon::AREA;

		for (size_t innerPolygonIndex = 0; innerPolygonIndex < polygons->size(); innerPolygonIndex++) {
			if (polygonIndex == innerPolygonIndex) {
				continue;
			}

			Polygon* innerPolygon = polygons->at(innerPolygonIndex);
			Point* firstPoint = innerPolygon->getKnots()->at(0);

			if (polygon->includesPoint(firstPoint)) {
				polygonType = Polygon::HOLE;
				break;
			}
		}

		if (polygonType == Polygon::AREA) {
			this->areas.push_back(polygon);
		} else {
			this->holes.push_back(polygon);
		}
	}

	if (*name == "Niedersachsen") {
		cout << "Holes: " << this->holes.size() << endl;
		cout << "Areas: " << this->areas.size() << endl;
	}
}

Country::~Country() {
}

double Country::getExpanse() {
	double expanse = 0.0;

	for (size_t areaIndex = 0; areaIndex < this->areas.size(); areaIndex++) {
		Polygon* area = this->areas.at(areaIndex);
		expanse += abs(area->getExpanse());
	}

	for (size_t holeIndex = 0; holeIndex < this->holes.size(); holeIndex++) {
		Polygon* hole = this->holes.at(holeIndex);
		expanse += abs(hole->getExpanse());
	}

	return expanse;
}

bool Country::contains(Point* point) {
	for (size_t polygonIndex = 0; polygonIndex < this->areas.size(); polygonIndex++) {
		Polygon polygon = *this->areas.at(polygonIndex);

		if (polygon.includesPoint(point)) {

			for (size_t holeIndex = 0; holeIndex < this->holes.size(); holeIndex++) {
				Polygon hole = *this->holes.at(holeIndex);

				if (hole.includesPoint(point)) {
					return false;
				}
			}

			return true;
		}
	}

	return false;
}

int Country::getPathCount() {
	return this->areas.size() + this->holes.size();
}

string * Country::getName() {
	return this->name;
}
