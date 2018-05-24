#include "crosspoints.hpp"
#include <algorithm>

Crosspoints::Crosspoints() {
}

Crosspoints::~Crosspoints() {
}

bool Crosspoints::contains(Crosspoint crosspoint) {
	vector<Crosspoint*>::iterator foundCrosspoint = find_if(this->crosspoints.begin(), this->crosspoints.end(),
			[crosspoint](Crosspoint* toCheck) {
				return *toCheck == crosspoint;
			});

	return foundCrosspoint != this->crosspoints.end();
}

void Crosspoints::add(Crosspoint* crosspoint) {
	if (contains(*crosspoint)) {
		this->crosspoints.push_back(crosspoint);
	}
}

int Crosspoints::size() {
	return this->crosspoints.size();
}
