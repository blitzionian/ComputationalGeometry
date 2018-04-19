#ifndef POINT_H_
#define POINT_H_

class Point {
public:
	Point(double x, double y);
	virtual ~Point();

	double getX();
	double getY();

private:
	double x;
	double y;
};

#endif /* POINT_H_ */
