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
//	std::sprintf("%f %f %f %f", p1->x, p1->y, p2->x, p2->y);
	return "";
}

