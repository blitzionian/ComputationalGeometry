#include <crosspoint.hpp>
#include <math.h>

Crosspoint::Crosspoint(Line* line1, Line* line2) :
		line1(line1), line2(line2), crosspoint(calculateCrossPoint()) {
}

Crosspoint::~Crosspoint() {
}

Point* Crosspoint::getPoint() {
	return &crosspoint;
}

Line* Crosspoint::getLine1() {
	return this->line1;
}

Line* Crosspoint::getLine2() {
	return this->line2;
}

Point Crosspoint::calculateCrossPoint() {
	double diffx3x1 = line2->getLeftPoint()->getX() - line1->getLeftPoint()->getX();
	double diffx4x3 = line2->getRightPoint()->getX() - line2->getLeftPoint()->getX();
	double diffx2x1 = line1->getRightPoint()->getX() - line1->getLeftPoint()->getX();

	double diffy3y1 = line2->getLeftPoint()->getY() - line1->getLeftPoint()->getY();
	double diffy4y3 = line2->getRightPoint()->getY() - line2->getLeftPoint()->getY();
	double diffy2y1 = line1->getRightPoint()->getY() - line1->getLeftPoint()->getY();

	double t = ((diffx3x1 * diffy2y1) / diffx2x1 - diffy3y1) / (diffy4y3 - (diffy2y1 * diffx4x3) / diffx2x1);

	double coordX;
	if (line1->getLeftPoint()->getX() < line2->getLeftPoint()->getX()) {
		coordX = line1->getLeftPoint()->getX() + abs(t) * line1->getWidth();
	} else {
		coordX = line2->getLeftPoint()->getX() + abs(t) * line2->getWidth();
	}

	double coordY = line1->getYAt(coordX);
	return Point(coordX, coordY);
}

bool Crosspoint::operator==(Crosspoint& other) {
	Line ol1 = *other.line1;
	Line ol2 = *other.line2;

	Line thL1 = *this->line1;
	Line thL2 = *this->line2;

	return ol1 == thL1 || ol1 == thL2 || ol2 == thL1 || ol2 == thL2;
}

bool Crosspoint::operator==(const Crosspoint& other) {
	Line ol1 = *other.line1;
	Line ol2 = *other.line2;

	Line thL1 = *this->line1;
	Line thL2 = *this->line2;

	return ol1 == thL1 || ol1 == thL2 || ol2 == thL1 || ol2 == thL2;
}
