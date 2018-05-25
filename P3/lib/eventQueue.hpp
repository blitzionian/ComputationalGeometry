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
	void addEvent(Event eventToAdd);
	bool hasEvent();
	void removeNextEvent();

	void print();

private:
	list<Event> eventQueue;

	void addCrosspoint(Event event);
	void add(Event event);
	void initEventQueue(vector<Line*> lines);
};

#endif /* LIB_EVENTQUEUE_HPP_ */
