#include "point.hpp"
#include <string>
#include <vector>

#ifndef LINE_H_
#define LINE_H_

class Line {
public:
	Line(Point* startPoint, Point* endPoint);
	virtual ~Line();

	Point* getStartPoint();
	Point* getEndPoint();

	double getExpanseOverXLine();

	/**
	 * Berechnet ob sich die Strecke mit einer anderen gegebenen Strecke schneidet.
	 */
	bool cross(Line& line);

	/**
	 * Berechnet ob die Strecke den gegebenen Punkt enthält,
	 * mit der Vorraussetzung dass die Prüfung nur für Punkte funktioniert,
	 * die koolliniear (ccw=0) zu der Strecke liegen.
	 */
	bool contains(Point& point);

	/**
	 * Gibt an ob die Strecke den gegebenen Punkt enhält. (ohne Einschränkung im Vergleich zu contains)
	 */
	bool containsReal(Point* point);

	bool isPoint();
	std::string toString();
	double ccw(Point* pointToConsider);

private:
	Point* startPoint;
	Point* endPoint;

	Point* left;
	Point* right;

	Point* top;
	Point* bottom;

	bool pointsEqual;
};

#endif /* LINE_H_ */
