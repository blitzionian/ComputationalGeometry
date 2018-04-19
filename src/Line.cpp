#include "Line.h"

Line::Line(Point& startPoint, Point& endPoint) :
		p1(startPoint), p2(endPoint) {
}

Line::~Line() {
}

void Line::setStartPoint(Point& startPoint) {
	this->p1 = startPoint;
}

void Line::setEndPoint(Point& endPoint) {
	this->p2 = endPoint;
}

Point& Line::getEndPoint() {
	return this->p1;
}

Point& Line::getStartPoint() {
	return this->p2;
}

std::string Line::toString() {
	return this->p1.toString() + " " + this->p2.toString();
}

