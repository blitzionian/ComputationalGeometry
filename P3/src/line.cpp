#include "line.hpp"
#include <iostream>

using namespace std;

Line::Line() = default;

Line::Line(Point* start, Point* end) {
    set_points(start,end);
}

Line::~Line() = default;

void Line::set_points(Point * start, Point * end)  {
    startPoint = start;
    endPoint = end;
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

Point* Line::getEndPoint() {
	return this->endPoint;
}

Point* Line::getStartPoint() {
	return this->startPoint;
}

std::string Line::toString() {
	return this->startPoint->toString() + " " + this->endPoint->toString();
}

bool Line::equals(Line & other) {
	return *(getStartPoint()) == *(other.getStartPoint()) && *(getEndPoint()) == *(other.getEndPoint());
}

Line::equation Line::eq() {
    double m = (right->getY() - left->getY()) / (right->getX() - left->getX());
    double b = left->getY() - (m * left->getY());
    return equation {m,b};
}

// see: https://de.wikipedia.org/wiki/Schnittpunkt
Point * Line::intersection_point(Line *other) {
    if(cross(*other)){
        double x1 = getStartPoint()->getX();
        double x2 = getEndPoint()->getX();
        double x3 = other->getStartPoint()->getX();
        double x4 = other->getEndPoint()->getX();
        double y1 = getStartPoint()->getY();
        double y2 = getEndPoint()->getY();
        double y3 = other->getStartPoint()->getY();
        double y4 = other->getEndPoint()->getY();
        double xsn = ((y4 - y3) * (x2 - x1)) - ((y2 - y1) * (x4 - x3));
        if(0 == xsn) {
            return nullptr;
        }
        double ysn = ((y4 - y3) * (x2 - x1)) - ((y2 - y1) * (x4 - x3));
        if(0 == ysn) {
            return nullptr;
        }
        double xsz = ((x4 - x3)*((x2*y1) - (x1*y2))) - ((x2-x1)*((x4*y3)-(x3*y4)));
        double ysz = ((y1 - y2) * ((x4 * y3) - (x3 * y4))) - ((y3 - y4) * ((x2 * y1) - (x1 * y2)));
        double xs = xsz / xsn;
        double ys = ysz / ysn;
        return new Point(xs,ys);
    } else {
        return nullptr;
    }
}

Line* Line::segment(Point *start, Point *end) {
    Line * result = new Line();
    if(start->getY() <= end->getX()){
        result->set_points(start,end);
    } else {
        result->set_points(end,start);
    }
    return result;
}
