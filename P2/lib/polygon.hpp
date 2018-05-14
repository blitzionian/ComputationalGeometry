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
	static const int HOLE = -1;
	static const int AREA = 1;

	Polygon(vector<Point*> *knots);
	virtual ~Polygon();

	/**
	 * Berechnet die Fläche des Polygons.
	 */
	double getExpanse();

	vector<Point*>* getKnots();

	Point maxCoordinates();

	bool includesPoint(Point* point);

private:
	/**
	 * Die Kanten des Polygons.
	 */
	vector<Line*> edges;

	vector<Point*> *knots;
};

#endif /* SRC_POLYGON_HPP_ */
