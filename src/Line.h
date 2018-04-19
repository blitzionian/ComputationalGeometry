#include "Point.h"
#include <string>

#ifndef LINE_H_
#define LINE_H_

class Line {
public:
	Line(Point& startPoint, Point& endPoint);
	virtual ~Line();

	void setStartPoint(Point& startPoint);
	Point& getStartPoint();

	void setEndPoint(Point& endPoint);
	Point& getEndPoint();

	std::string toString();

	double ccw(Point& pointToConsider);

private:
	Point& p1;
	Point& p2;
};

#endif /* LINE_H_ */
