#ifndef SRC_POLYGON_HPP_
#define SRC_POLYGON_HPP_

#include <vector>
#include <string>
#include "line.hpp"

using namespace std;

/**
 * Diese Klasse repräsentiert ein komplettes Bundesland.
 */
class Country {
public:

	typedef Point* vertex;

	Country(string* name, vector<path_t>* paths);
	virtual ~Country();

	string* getName();

	int getPathCount();

	double getExpanse();

	std::vector<vertex> vertices();

	Point maxCoordinates();

	bool includesPoint(Point & point);

private:
	/**
	 * Der Name der Polygons (z.B. Bayern)
	 */
	string* name;

	/**
	 * Alle Polygone die zum Bundesland gehören. Hier sind alle Polygone enthalten,
	 * egal ob sie ein Loch oder eine Exklave darstellen.
	 */
	vector<path_t>* polygons;
};

#endif /* SRC_POLYGON_HPP_ */

