#ifndef EVENT_HPP_
#define EVENT_HPP_

#include <line.hpp>

enum EventType {
	SEGMENT_START, SEGMENT_END, CROSSPOINT
};

class Event {
public:
	Event(EventType eventType, Line* line);
	virtual ~Event();

private:
	EventType eventType;
	Line* line;
};

#endif /* EVENT_HPP_ */
