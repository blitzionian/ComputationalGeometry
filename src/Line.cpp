#include "Line.h"
#include <iostream>

using namespace std;

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

bool Line::crosses(Line& lineToCheck) {
	double r1 = this->ccw(lineToCheck.getStartPoint());
	double r2 = this->ccw(lineToCheck.getEndPoint());

	if (r1 == 0 && r2 == 0) {
		cout << "Parallel: " << this->toString() << " : " << lineToCheck.toString() << "\n";

		if (this->contains(lineToCheck.getStartPoint()) || this->contains(lineToCheck.getEndPoint())) {
			cout << lineToCheck.toString() << " : " << this->toString() << "\n";
//			std::cout << "Line schneidet kollinear mit Linie\n";
			return true;
		}
	}

	double resultOtherLine = r1 * r2;

	if (resultOtherLine <= 0) {
		double resultThisLIne = lineToCheck.ccw(this->getStartPoint()) * lineToCheck.ccw(this->getEndPoint());

		if (resultThisLIne <= 0) {
			return true;
			//					cout << "Line " << i << " kreuzt Line " << j << "\n";
		}
	}

	return false;
}

bool Line::isPoint() {
	return this->p1.equals(this->p2);
}

bool Line::contains(Point& point) {
	double px = point.getX();
	double lx = (px - this->p1.getX()) / (this->p2.getX() - this->p1.getX());

	double py = point.getY();
	double ly = (py - this->p1.getY()) / (this->p2.getY() - this->p1.getY());

	if (ly == lx) {
		if (this->left->getX() > px || this->right->getX() < px) {
			return false;
		}

		if (this->top->getY() < py || this->bottom->getY() > py) {
			return false;
		}

		cout << point.toString() << " inside " << this->toString() << "\n";
		return true;
	}

	return false;
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

