#ifndef EVENT_HPP_
#define EVENT_HPP_

#include <line.hpp>
#include <crosspoint.hpp>

enum EventType {
	SEGMENT_START, SEGMENT_END, INTERSECTION
};

class Event {
public:
	Event(EventType eventType, Line* line);
	Event(Crosspoint* crosspoint);
	virtual ~Event();

	static Point* getPointToConsider(Event event);
	Point* getPointToConsider();
	Line* getSegment();
	Crosspoint* getCrosspoint();

	bool isStartpoint();
	bool isEndpoint();
	bool isIntersection();

	bool operator<(const Event& other);

private:
	EventType eventType;
	Line* line1;
	Crosspoint* crosspoint;
};

#endif /* EVENT_HPP_ */
