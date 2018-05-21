#include <sweepLine.hpp>
#include <iostream>

SweepLine::SweepLine(vector<Line*> lines) :
		lines(lines) {
}

SweepLine::~SweepLine() {
}

void SweepLine::handleStartPoint(Event eventToHandle) {
	Line* segment = eventToHandle.getSegment();

	this->sweepLine.push_back(segment);

}

void SweepLine::handleEndPoint(Event eventToHandle) {

}

void SweepLine::handleIntersection(Event eventToHandle) {

}

Crosspoints* SweepLine::calculateResult() {
	this->initEventQueue();

	list<Event>::iterator eventIterator;

	while (!this->eventQueue.empty()) {
		Event nextEvent = this->eventQueue.front();

		if (nextEvent.isStartpoint()) {
			handleStartPoint(nextEvent);
		} else if (nextEvent.isEndpoint()) {
			handleEndPoint(nextEvent);
		} else {
			handleIntersection(nextEvent);
		}

		this->eventQueue.pop_front();
	}

	return &this->crosspoints;
}

void SweepLine::initEventQueue() {
	vector<Line*>::iterator lineIterator;

	for (lineIterator = this->lines.begin(); lineIterator != this->lines.end(); lineIterator++) {
		Line* line = *lineIterator;

		Event* eventStart = new Event(EventType::SEGMENT_START, line);
		Event* eventEnd = new Event(EventType::SEGMENT_END, line);

		this->eventQueue.push_back(*eventStart);
		this->eventQueue.push_back(*eventEnd);
	}

	this->eventQueue.sort();
}

int SweepLine::getCrossCount() {
	return this->crossCount;
}

void SweepLine::printEventQueue() {
	list<Event>::iterator eventIterator;

	for (eventIterator = this->eventQueue.begin(); eventIterator != this->eventQueue.end(); eventIterator++) {
		Event event = *eventIterator;

		Point* point = event.getPointToConsider();

		cout << point->toString() << endl;
	}
}
