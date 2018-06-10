#include "event.hpp"

Event::Event(EventType eventType, Line* line) :
		eventType(eventType), line(line), crosspoint(NULL) {
}

Event::Event(Crosspoint* crosspoint) :
		eventType(EventType::INTERSECTION), line(NULL), crosspoint(crosspoint) {
}

Event::~Event() {
}

Point* Event::getPointToConsider(Event event) {
	if (event.eventType == EventType::SEGMENT_START) {
		return event.line->getLeftLowerPoint();
	} else if (event.eventType == EventType::SEGMENT_END) {
		return event.line->getRightUpperPoint();
	} else {
		return event.crosspoint->getPoint();
	}
}

Crosspoint* Event::getCrosspoint() {
	return this->crosspoint;
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
	return this->line;
}

bool Event::operator==(const Event& other) {
	if (this->eventType != other.eventType) {
		return false;
	}

	if (this->isIntersection()) {
		return *this->crosspoint == *other.crosspoint;
	} else {
		return *this->getPointToConsider() == *getPointToConsider(other);
	}
}

bool Event::operator<(const Event& other) const {
	Point* thisPoint = getPointToConsider(*this);
	Point* otherPoint = getPointToConsider(other);

	return *thisPoint < *otherPoint;
}
