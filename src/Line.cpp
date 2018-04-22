#include "Line.h"

Line::Line(Point& startPoint, Point& endPoint) :
		p1(startPoint), p2(endPoint) {
}

Line::~Line() {
}

double Line::ccw(Point& pointToConsider) {
	double ax = p2.getX() - p1.getX();
	double ay = p2.getY() - p1.getY();

	double bx = pointToConsider.getX() - p1.getX();
	double by = pointToConsider.getY() - p1.getY();
	double result = ax * by - ay * bx;

	return result;
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

Point* Line::getNormalForm() {

	return new Point(0, 0);
}

std::string Line::toString() {
	return this->p1.toString() + " " + this->p2.toString();
}

