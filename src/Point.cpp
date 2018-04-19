#include "Point.h"

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
