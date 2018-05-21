#ifndef LIB_SWEEPLINE_HPP_
#define LIB_SWEEPLINE_HPP_

#include <vector>
#include <list>
#include <line.hpp>
#include <event.hpp>
#include <crosspoints.hpp>

using namespace std;

class SweepLine {
public:
	SweepLine(vector<Line*> lines);
	virtual ~SweepLine();

	Crosspoints* calculateResult();
	int getCrossCount();

	void printEventQueue();

private:
	vector<Line*> lines;
	int crossCount = 0;

	Crosspoints crosspoints;
	list<Line*> sweepLine;
	list<Event> eventQueue;

	void initEventQueue();

	void handleStartPoint(Event eventToHandle);
	void handleEndPoint(Event eventToHandle);
	void handleIntersection(Event eventToHandle);

	list<Line*>::iterator insertIntoSweepLine(Line* segment);

	void printSweepLine();
};

#endif /* LIB_SWEEPLINE_HPP_ */
