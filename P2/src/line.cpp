#include "line.hpp"
#include <iostream>

using namespace std;

Line::Line(Point& startPoint, Point& endPoint) :
		p1(startPoint), p2(endPoint) {
	if (p1.getX() <= p2.getX()) {
		this->left = &p1;
		this->right = &p2;
	} else {
		this->left = &p2;
		this->right = &p1;
	}

	if (p1.getY() <= p2.getY()) {
		this->bottom = &p1;
		this->top = &p2;
	} else {
		this->bottom = &p2;
		this->top = &p1;
	}

	this->pointsEqual = startPoint == endPoint;
}

Line::~Line() {
}

bool Line::cross(Line& lineToCheck) {
	if (pointsEqual) {
		if (!lineToCheck.isPoint()) {
			return lineToCheck.cross(*this);
		} else {
			return this->p1 == lineToCheck.p1;
		}
	}

	double ccwThis1 = this->ccw(lineToCheck.getStartPoint());
	double ccwThis2 = this->ccw(lineToCheck.getEndPoint());

	if (ccwThis1 == 0 && ccwThis2 == 0) {
		if (this->contains(lineToCheck.getStartPoint()) || this->contains(lineToCheck.getEndPoint())) {
			return true;
		}

		return false;
	}

	double resultOtherLine = ccwThis1 * ccwThis2;

	if (resultOtherLine <= 0) {
		double resultThisLIne = lineToCheck.ccw(this->getStartPoint()) * lineToCheck.ccw(this->getEndPoint());

		if (resultThisLIne <= 0) {
			return true;
		}
	}

	return false;
}

bool Line::isPoint() {
	return pointsEqual;
}

bool Line::contains(Point& point) {
	bool test = this->left->getX() <= point.getX() && this->right->getX() >= point.getX()
			&& this->top->getY() >= point.getY() && this->bottom->getY() <= point.getY();

	return test;
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

std::string Line::toString() {
	return this->p1.toString() + " " + this->p2.toString();
}

