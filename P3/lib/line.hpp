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

	Point* getLeftPoint();
	Point* getRightPoint();

	double getYAt(double x);
	double getSteigung();
	double getLength();
	double getWidth();

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

	bool operator==(Line& other);

private:
	Point* startPoint;
	Point* endPoint;

	Point* left;
	Point* right;

	Point* top;
	Point* bottom;

	bool pointsEqual;

	double steigung;

	double calculateSteigung();
};

#endif /* LINE_H_ */
