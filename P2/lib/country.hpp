#ifndef SRC_COUNTRY_HPP_
#define SRC_COUNTRY_HPP_

#include <vector>
#include <string>

#include <line.hpp>
#include <polygon.hpp>

using namespace std;

/**
 * Diese Klasse repräsentiert ein komplettes Bundesland.
 */
class Country {
public:

	Country(string* name, vector<Polygon*> *polygons);
	virtual ~Country();

	string* getName();

	/**
	 * Gibt die Anzahl der Enthaltenen Polygone an.
	 */
	int getPathCount();

	/**
	 * Berechnet die Fläche des Landes.
	 */
	double getExpanse();

	bool contains(Point point);

private:
	/**
	 * Der Name der Polygons (z.B. Bayern)
	 */
	string* name;

	/**
	 * Alle Polygone die zum Bundesland gehören. Hier sind alle Polygone enthalten,
	 * egal ob sie ein Loch oder eine Exklave darstellen.
	 */
	vector<Polygon*>* polygons;
};

#endif /* SRC_COUNTRY_HPP_ */
