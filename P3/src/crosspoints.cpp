#include "crosspoints.hpp"
#include <algorithm>

Crosspoints::Crosspoints() {
}

Crosspoints::~Crosspoints() {
}

void Crosspoints::add(Crosspoint* crosspoint) {
	find_if(this->crosspoints.begin(), this->crosspoints.end(), [crosspoint](Crosspoint* toCheck) {
		return *toCheck == *crosspoint;
	});

	this->crosspoints.push_back(crosspoint);
}

int Crosspoints::size() {
	return this->crosspoints.size();
}
