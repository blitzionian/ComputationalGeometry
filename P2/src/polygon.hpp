#ifndef SRC_POLYGON_HPP_
#define SRC_POLYGON_HPP_

#include <vector>
#include <string>
#include "line.hpp"

using namespace std;

class Polygon {
public:
	Polygon(string* id, vector<Line*>* edges);
	virtual ~Polygon();

	string* getId();

private:
	string* id;
	vector<Line*>* edges;
};

#endif /* SRC_POLYGON_HPP_ */

