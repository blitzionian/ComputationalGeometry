#include "crosspoints.hpp"
#include <algorithm>
#include <iostream>

Crosspoints::Crosspoints() {
}

Crosspoints::~Crosspoints() {
}

bool Crosspoints::contains(Crosspoint crosspoint) {
	vector<Crosspoint*>::iterator last = this->crosspoints.end();
	vector<Crosspoint*>::iterator foundCrosspoint = find_if(this->crosspoints.begin(), last,
			[crosspoint](Crosspoint* toCheck) {
				return *toCheck == crosspoint;
			});

	return foundCrosspoint != last;
}

bool Crosspoints::add(Crosspoint* crosspoint) {
	if (!contains(*crosspoint)) {
		this->crosspoints.push_back(crosspoint);
		return true;
	}

	return false;
}

int Crosspoints::size() {
	return this->crosspoints.size();
}

vector<Crosspoint*>* Crosspoints::getCrosspoints() {
	return &this->crosspoints;
}
