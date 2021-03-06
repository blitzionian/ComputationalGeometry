#ifndef LIB_EVENTQUEUE_HPP_
#define LIB_EVENTQUEUE_HPP_

#include<list>
#include<set>
#include<event.hpp>

using namespace std;

class EventQueue {

public:
	EventQueue(vector<Line*> lines);
	virtual ~EventQueue();

	Event getNextEvent();
	void addEvent(Event eventToAdd, bool sort = true);
	bool hasEvent();
	void removeNextEvent();

	int size();
	void print();

private:
	set<Event> eventQueue;

	void addCrosspoint(Event event);
	void add(Event event, bool sort = true);
	void initEventQueue(vector<Line*> lines);
};

#endif /* LIB_EVENTQUEUE_HPP_ */
