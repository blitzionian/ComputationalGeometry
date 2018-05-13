#ifndef SRC_POLYGON_HPP_
#define SRC_POLYGON_HPP_

#include <vector>
#include <line.hpp>

using namespace std;

/**
 * Diese Klasse stellt ein einzelnes Polygon ohne Löcher, Inseln oder sonstige Besonderheiten dar.
 */
class Polygon {
public:
	Polygon(vector<Line*> *edges);
	virtual ~Polygon();

	/**
	 * Berechnet die Fläche des Polygons.
	 */
	double getExpanse();

private:
	/**
	 * Die Kanten des Polygons.
	 */
	vector<Line*> *edges;
};

#endif /* SRC_POLYGON_HPP_ */
