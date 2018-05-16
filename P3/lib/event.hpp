#ifndef EVENT_HPP_
#define EVENT_HPP_

enum EventType {
	SEGMENT_START, SEGMENT_END, CROSSPOINT
};

class Event {
public:
	Event(EventType eventType);
	virtual ~Event();

private:
	EventType eventType;
};

#endif /* EVENT_HPP_ */
