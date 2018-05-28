#include "point.hpp"
#include <string>
#include <vector>

#ifndef LINE_H_
#define LINE_H_

class Line {
public:

    struct equation {
        double m;
        double b;
    };

    Line();
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

	/**
	 * Gibt an ob die Strecke eigentlich nur ein Punkt ist. (Start und Endpunkt der Strecke sind identisch)
	 */
	bool isPoint();

	std::string toString();

	bool equals(Line & other);

	/**
	 * Berechnet den ccw Wert der Strecke zu einem gegebenen Punkt.
	 */
	double ccw(Point* pointToConsider);

    virtual void set_points(Point * start, Point * end);
    equation eq();
    Point * intersection_point(Line * other);

    static Line* segment(Point * start, Point * end);

private:
	Point* startPoint;
	Point* endPoint;

	// Speichert den Punkt mit der kleinsten x Koordinate
	Point* left;
	// Speichert den Punkt mit der größten x Koordinate
	Point* right;

	// Speichert den Punkt mit der größten y Koordinate
	Point* top;
	// Speichert den Punkt mit der kleinsten y Koordinate
	Point* bottom;

	// Speichert ob start und enpunkt identisch sind.
	bool pointsEqual;
};

#endif /* LINE_H_ */
