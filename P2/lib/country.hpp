#ifndef SRC_POLYGON_HPP_
#define SRC_POLYGON_HPP_

#include <vector>
#include <string>
#include "line.hpp"

using namespace std;

class Country {
public:

	typedef Point* vertex;

	Country(string* id, vector<path_t>* paths);
	virtual ~Country();

	string* getId();

	int getPathCount();

	double getExpanse();

	std::vector<vertex> vertices();

	Point maxCoordinates();

	bool includesPoint(Point & point);

private:
	/**
	 * Der Name der Polygons (z.B. Bayern)
	 */
	string* id;

	/**
	 * Alle Pfade die zum Polygon gehören. Es kann davon ausgegenagen werden, dass jeder Pfad geschlossen ist
	 * und damit Prinzipiell ein eigenes Polygon darstellt.
	 */
	vector<path_t>* paths;
};

#endif /* SRC_POLYGON_HPP_ */

