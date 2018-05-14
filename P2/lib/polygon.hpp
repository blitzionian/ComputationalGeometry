#ifndef SRC_POLYGON_HPP_
#define SRC_POLYGON_HPP_

#include <vector>
#include <point.hpp>
#include <line.hpp>

using namespace std;

/**
 * Diese Klasse stellt ein einzelnes Polygon ohne Löcher, Inseln oder sonstige Besonderheiten dar.
 */
class Polygon {
public:
	typedef Point* vertex;

	Polygon(vector<Point*> *knots);
	virtual ~Polygon();

	/**
	 * Berechnet die Fläche des Polygons.
	 */
	double getExpanse();

	std::vector<vertex> vertices();
	vector<Point*>* getKnots();

	Point maxCoordinates();

	bool includesPoint(Point &point);

private:
	/**
	 * Die Kanten des Polygons.
	 */
	vector<Line*> edges;

	vector<Point*> *knots;
};

#endif /* SRC_POLYGON_HPP_ */
