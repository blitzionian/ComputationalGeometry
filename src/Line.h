/*
 * Line.h
 *
 *  Created on: Apr 15, 2018
 *      Author: markus
 */

#include "Point.h"

#ifndef LINE_H_
#define LINE_H_

class Line {
public:
	Line();
	virtual ~Line();

	void setStartPoint(Point startPoint);
	void setEndPoint(Point endPoint);

private:
	Point p1;
	Point p2;
};

#endif /* LINE_H_ */
