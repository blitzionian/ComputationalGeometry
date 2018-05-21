#include "crosspoints.hpp"

Crosspoints::Crosspoints() {
}

Crosspoints::~Crosspoints() {
}

void Crosspoints::add(Crosspoint* crosspoint) {
	this->crosspoints.push_back(crosspoint);
}

