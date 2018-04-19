#include "Point.h"
#include <sstream>

Point::Point(double x, double y) {
	this->x = x;
	this->y = y;
}

Point::~Point() {
}

double Point::getX() {
	return this->x;
}

double Point::getY() {
	return this->y;
}

std::string Point::toString() {
	std::ostringstream strs;
	strs << this->x << " " << this->y;
	return strs.str();
}
