#ifndef LIB_EVENTQUEUE_HPP_
#define LIB_EVENTQUEUE_HPP_

#include<list>
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
	list<Event> eventQueue;
	list<Event> removedIntersections;

	void addCrosspoint(Event event);
	void add(Event event, bool sort = true);
	void initEventQueue(vector<Line*> lines);
};

#endif /* LIB_EVENTQUEUE_HPP_ */
