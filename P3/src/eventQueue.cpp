#include <eventQueue.hpp>
#include <iostream>
#include <algorithm>

EventQueue::EventQueue(vector<Line*> lines) {
	initEventQueue(lines);
}

EventQueue::~EventQueue() {
}

Event EventQueue::getNextEvent() {
	return this->eventQueue.front();
}

void EventQueue::addEvent(Event eventToAdd, bool sort) {
	if (eventToAdd.isIntersection()) {
		addCrosspoint(eventToAdd);
	} else {
		add(eventToAdd, sort);
	}
}

void EventQueue::addCrosspoint(Event eventToAdd) {
	list<Event>::iterator foundIterInQueue = find(this->eventQueue.begin(), this->eventQueue.end(), eventToAdd);

	if (foundIterInQueue == this->eventQueue.end()) {

		list<Event>::iterator foundIterInOldIntersections = find(this->removedEvents.begin(),
				this->removedEvents.end(), eventToAdd);

		if (foundIterInOldIntersections == this->removedEvents.end()) {
			this->add(eventToAdd);
		}
	}
}

int EventQueue::size() {
	return this->eventQueue.size();
}

void EventQueue::add(Event event, bool sort) {
	this->eventQueue.push_back(event);

	if (sort) {
		this->eventQueue.sort();
	}
}

bool EventQueue::hasEvent() {
	return this->eventQueue.size() > 0;
}

void EventQueue::removeNextEvent() {
	this->removedEvents.push_back(this->eventQueue.front());
	this->eventQueue.pop_front();
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

	this->eventQueue.sort();

	cout << "Ende init event queue" << endl;
}

void EventQueue::print() {
	list<Event>::iterator eventIterator;

	for (eventIterator = this->eventQueue.begin(); eventIterator != this->eventQueue.end(); eventIterator++) {
		Event event = *eventIterator;
		Point* point = event.getPointToConsider();
		cout << point->toString() << endl;
	}
}
