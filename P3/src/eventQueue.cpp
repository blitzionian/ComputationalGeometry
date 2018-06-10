#include <eventQueue.hpp>
#include <iostream>
#include <algorithm>

EventQueue::EventQueue(vector<Line*> lines) {
	initEventQueue(lines);
}

EventQueue::~EventQueue() {
}

Event EventQueue::getNextEvent() {
	return *this->eventQueue.begin();
}

void EventQueue::addEvent(Event eventToAdd, bool sort) {
	if (eventToAdd.isIntersection()) {
		addCrosspoint(eventToAdd);
	} else {
		add(eventToAdd, sort);
	}
}

void EventQueue::addCrosspoint(Event eventToAdd) {
	set<Event>::iterator foundIterInQueue = this->eventQueue.find(eventToAdd);

	if (foundIterInQueue == this->eventQueue.end()) {
		this->add(eventToAdd);
	}
}

int EventQueue::size() {
	return this->eventQueue.size();
}

void EventQueue::add(Event event, bool sort) {
	this->eventQueue.insert(event);
}

bool EventQueue::hasEvent() {
	return this->eventQueue.size() > 0;
}

void EventQueue::removeNextEvent() {
	this->eventQueue.erase(this->eventQueue.begin());
}

void EventQueue::initEventQueue(vector<Line*> lines) {
	cout << "Start init event queue, Size: " << lines.size() << endl;
	vector<Line*>::iterator lineIterator;

	for (lineIterator = lines.begin(); lineIterator != lines.end(); lineIterator++) {
		Line* line = *lineIterator;

		Event* eventStart = new Event(EventType::SEGMENT_START, line);
		Event* eventEnd = new Event(EventType::SEGMENT_END, line);

		this->addEvent(*eventStart, false);
		this->addEvent(*eventEnd, false);
	}

	cout << "Ende init event queue" << endl;
}

void EventQueue::print() {
	set<Event>::iterator eventIterator;

	for (eventIterator = this->eventQueue.begin(); eventIterator != this->eventQueue.end(); eventIterator++) {
		Event event = *eventIterator;
		Point* point = event.getPointToConsider();
		cout << point->toString() << endl;
	}
}
