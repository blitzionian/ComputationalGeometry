#include <polygon.hpp>

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
