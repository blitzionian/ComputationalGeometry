#ifndef SRC_CROSSPOINT_HPP_
#define SRC_CROSSPOINT_HPP_

#include <line.hpp>

class Crosspoint {
public:
	Crosspoint(Line* line1, Line* line2);
	virtual ~Crosspoint();

	Point* getPoint();
private:
	Line* line1;
	Line* line2;

	Point crosspoint;

	Point calculateCrossPoint();
};

#endif /* SRC_CROSSPOINT_HPP_ */
