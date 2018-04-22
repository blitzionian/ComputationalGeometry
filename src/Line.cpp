#include "Line.h"

Line::Line(Point& startPoint, Point& endPoint) :
		p1(startPoint), p2(endPoint) {
	if (p1.getX() <= p2.getX()) {
		this->left = &p1;
		this->right = &p2;
	} else {
		this->left = &p1;
		this->right = &p2;
	}

	if (p1.getY() <= p2.getY()) {
		this->bottom = &p1;
		this->top = &p2;
	} else {
		this->bottom = &p2;
		this->top = &p1;
	}
}

Line::~Line() {
}

bool Line::contains(Point& point) {
	double px = point.getX();
	if (this->left->getX() > px || this->right->getX() < px) {
		return false;
	}

	double py = point.getY();
	if (this->top->getY() < py || this->bottom->getY() > py) {
		return false;
	}

	return true;
}

double Line::ccw(Point& pointToConsider) {
	double ax = p2.getX() - p1.getX();
	double ay = p2.getY() - p1.getY();

	double bx = pointToConsider.getX() - p1.getX();
	double by = pointToConsider.getY() - p1.getY();
	double result = ax * by - ay * bx;

	return result;
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

