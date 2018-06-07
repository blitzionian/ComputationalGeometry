#ifndef LIB_SWEEPLINE_HPP_
#define LIB_SWEEPLINE_HPP_

#include <vector>
#include <list>
#include <line.hpp>
#include <event.hpp>
#include <crosspoints.hpp>
#include <eventQueue.hpp>

using namespace std;

class SweepLine {
public:
	SweepLine(vector<Line*> lines);
	virtual ~SweepLine();

	Crosspoints* calculateResult();
	int getCrossCount();

private:
	vector<Line*> lines;

	Crosspoints crosspoints;
	list<Line*> sweepLine;
	EventQueue eventQueue;

	void handleStartPoint(Event eventToHandle);
	void handleEndPoint(Event eventToHandle);
	void handleIntersection(Event eventToHandle);

	void insertIntoEventQueueIfCross(Line* seg1, Line* seg2);
	list<Line*>::iterator insertIntoSweepLine(Line* segment);

	void printSweepLine();
};

#endif /* LIB_SWEEPLINE_HPP_ */
