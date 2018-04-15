/*
 * Line.cpp
 *
 *  Created on: Apr 15, 2018
 *      Author: markus
 */

#include "Line.h"

Line::Line() {
}

Line::~Line() {
}

void Line::setStartPoint(Point startPoint) {
	this->p1 = startPoint;
}

void Line::setEndPoint(Point endPoint) {
	this->p2 = endPoint;
}

