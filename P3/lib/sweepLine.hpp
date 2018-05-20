#ifndef LIB_SWEEPLINE_HPP_
#define LIB_SWEEPLINE_HPP_

#include <vector>
#include <line.hpp>
#include <event.hpp>

using namespace std;

class SweepLine {
public:
	SweepLine(vector<Line*> lines);
	virtual ~SweepLine();

	void calculateResult();
	int getCrossCount();

private:
	vector<Line*> lines;
	int crossCount = -1;

	vector<Event> eventQueue;

	void initEventQueue();
};

#endif /* LIB_SWEEPLINE_HPP_ */
