#include "line.hpp"
#include <iostream>
#include <math.h>

using namespace std;

Line::Line(Point* startPoint, Point* endPoint) :
		startPoint(startPoint), endPoint(endPoint) {
	if (startPoint->getX() <= endPoint->getX()) {
		this->left = startPoint;
		this->right = endPoint;
	} else {
		this->left = endPoint;
		this->right = startPoint;
	}

	if (startPoint->getY() <= endPoint->getY()) {
		this->bottom = startPoint;
		this->top = endPoint;
	} else {
		this->bottom = endPoint;
		this->top = startPoint;
	}

	this->pointsEqual = startPoint == endPoint;

	steigung = calculateSteigung();
}

Line::~Line() {
}

double Line::calculateSteigung() {
	double diffY = this->right->getY() - this->left->getY();
	double diffX = this->right->getX() - this->left->getX();
	return diffY / diffX;
}

double Line::getWidth() {
	return this->right->getX() - this->left->getX();
}

double Line::getLength() {
	double diffX = getWidth();
	double diffY = this->right->getY() - this->left->getY();

	return hypot(diffX, diffY);
}

double Line::getYAt(double x) {
	if (x < this->left->getX() || x > this->right->getX()) {
		return 0;
	}

	double distanceToStartPoint = x - this->left->getX();
	return this->left->getY() + this->steigung * distanceToStartPoint;
}

double Line::getSteigung() {
	return steigung;
}

double Line::getExpanseOverXLine() {
	double height = (this->startPoint->getY() + this->endPoint->getY()) / 2;
	double width = this->startPoint->getX() - this->endPoint->getX();
	return height * width;
}

bool Line::cross(Line& lineToCheck) {
	if (pointsEqual) {
		if (!lineToCheck.isPoint()) {
			return lineToCheck.cross(*this);
		} else {
			return this->startPoint == lineToCheck.startPoint;
		}
	}

	double ccwThis1 = this->ccw(lineToCheck.getStartPoint());
	double ccwThis2 = this->ccw(lineToCheck.getEndPoint());

	if (ccwThis1 == 0 && ccwThis2 == 0) {
		if (this->contains(*lineToCheck.getStartPoint()) || this->contains(*lineToCheck.getEndPoint())) {
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

bool Line::containsReal(Point* point) {
	double ccw = this->ccw(point);

	if (ccw == 0) {
		return this->contains(*point);
	}

	return false;
}

bool Line::contains(Point& point) {
	bool test = this->left->getX() <= point.getX() && this->right->getX() >= point.getX()
			&& this->top->getY() >= point.getY() && this->bottom->getY() <= point.getY();

	return test;
}

double Line::ccw(Point* pointToConsider) {
	double ax = endPoint->getX() - startPoint->getX();
	double ay = endPoint->getY() - startPoint->getY();

	double bx = pointToConsider->getX() - startPoint->getX();
	double by = pointToConsider->getY() - startPoint->getY();
	double result = ax * by - ay * bx;

	return result;
}

Point* Line::getLeftPoint() {
	return this->left;
}

Point* Line::getRightPoint() {
	return this->right;
}

Point* Line::getEndPoint() {
	return this->endPoint;
}

Point* Line::getStartPoint() {
	return this->startPoint;
}

bool Line::operator==(Line& other) {
	Point* thisLeft = this->left;
	Point* otherLeft = other.getLeftPoint();

	if (*thisLeft == *otherLeft) {
		Point thisRight = *this->right;
		Point otherRight = *other.getRightPoint();

		if (thisRight == otherRight) {
			return true;
		}
	}

	return false;
}

std::string Line::toString() {
	return this->startPoint->toString() + " " + this->endPoint->toString();
}

