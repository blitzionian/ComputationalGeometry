#include "event.hpp"

Event::Event(EventType eventType, Line* line) :
		eventType(eventType), line1(line), crosspoint(NULL) {
}

Event::Event(Crosspoint* crosspoint) :
		eventType(EventType::INTERSECTION), line1(NULL), crosspoint(crosspoint) {
}

Event::~Event() {
}

Point* Event::getPointToConsider(Event event) {
	if (event.eventType == EventType::SEGMENT_START) {
		return event.line1->getStartPoint();
	} else if (event.eventType == EventType::SEGMENT_END) {
		return event.line1->getEndPoint();
	} else {
		return event.crosspoint->getPoint();
	}
}

bool Event::isStartpoint() {
	return this->eventType == EventType::SEGMENT_START;
}

bool Event::isEndpoint() {
	return this->eventType == EventType::SEGMENT_END;
}

bool Event::isIntersection() {
	return this->eventType == EventType::INTERSECTION;
}

Point* Event::getPointToConsider() {
	return getPointToConsider(*this);
}

Line* Event::getSegment() {
	return this->line1;
}

bool Event::operator<(const Event& other) {
	Point* thisPoint = this->getPointToConsider();
	Point* otherPoint = getPointToConsider(other);

	return *thisPoint < *otherPoint;
}
