#include "point.hpp"
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

bool Point::operator<(const Point& other) const {
	if (this->x < other.x) {
		return true;
	}

	if (this->x == other.x) {
		if (this->y < other.y) {
			return true;
		}
	}

	return false;
}

bool Point::operator ==(Point const& other) const {
	return this->x == other.x && this->y == other.y;
}

bool Point::operator ==(Point& other) const {
	return this->x == other.x && this->y == other.y;
}
