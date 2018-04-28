#include "point.hpp"
#include <string>

#ifndef LINE_H_
#define LINE_H_

class Line {
public:
	Line(Point& startPoint, Point& endPoint);
	virtual ~Line();

	Point& getStartPoint();
	Point& getEndPoint();
	bool cross(Line& line);
	bool contains(Point& point);
	bool isPoint();

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
