#ifndef SRC_CROSSPOINT_HPP_
#define SRC_CROSSPOINT_HPP_

#include <line.hpp>

class Crosspoint {
public:
	Crosspoint(Line* line1, Line* line2);
	virtual ~Crosspoint();

private:
	Line* line1;
	Line* line2;
};

#endif /* SRC_CROSSPOINT_HPP_ */
