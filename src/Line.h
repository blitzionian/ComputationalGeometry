#include "Point.h"
#include <string>

#ifndef LINE_H_
#define LINE_H_

class Line {
public:
	Line(Point& startPoint, Point& endPoint);
	virtual ~Line();

	Point& getStartPoint();
	Point& getEndPoint();
	bool contains(Point& point);

	std::string toString();

	double ccw(Point& pointToConsider);

private:
	Point& p1;
	Point& p2;

	Point* left;
	Point* right;

	Point* top;
	Point* bottom;

	Point* getNormalForm();
};

#endif /* LINE_H_ */
