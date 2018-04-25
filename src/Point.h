#ifndef POINT_H_
#define POINT_H_

#include <string>

class Point {
public:
	Point(double x, double y);
	virtual ~Point();

	double getX();
	double getY();

	std::string toString();
	bool equals(Point& point);

private:
	double x;
	double y;
};

#endif /* POINT_H_ */
