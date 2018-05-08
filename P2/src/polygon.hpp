#ifndef SRC_POLYGON_HPP_
#define SRC_POLYGON_HPP_

#include <vector>
#include <string>
#include "line.hpp"

using namespace std;

class Polygon {
public:
	Polygon(string* id, vector<path_t>* edges);
	virtual ~Polygon();

	string* getId();

	double getExpanse();

private:
	string* id;
	vector<path_t>* edges;
};

#endif /* SRC_POLYGON_HPP_ */

