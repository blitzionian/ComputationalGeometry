#include <sweepLine.hpp>
#include <iostream>

SweepLine::SweepLine(vector<Line*> lines) :
		lines(lines) {
}

SweepLine::~SweepLine() {
}

void SweepLine::handleStartPoint(Event eventToHandle) {
	Line* segment = eventToHandle.getSegment();
	list<Line*>::iterator insertedElementIt = this->insertIntoSweepLine(segment);
	//	cout << "Sweep Line after insert: " << endl;
	//	this->printSweepLine();

	list<Line*>::iterator previous(insertedElementIt);

	Line* segmentAbove = *(insertedElementIt++);
	Line* segmentBelow = *(previous--);

	if (segment->cross(*segmentAbove)) {
		Crosspoint* crosspoint = new Crosspoint(segment, segmentAbove);
		this->crosspoints.add(crosspoint);

		Event* ev = new Event(crosspoint);
		this->eventQueue.push_back(*ev);
	}

	if (segment->cross(*segmentBelow)) {
		Crosspoint* crosspoint = new Crosspoint(segment, segmentBelow);
		this->crosspoints.add(crosspoint);

		Event* ev = new Event(crosspoint);
		this->eventQueue.push_back(*ev);
	}

	this->eventQueue.sort();
}

void SweepLine::handleEndPoint(Event eventToHandle) {

}

void SweepLine::handleIntersection(Event eventToHandle) {

}

list<Line*>::iterator SweepLine::insertIntoSweepLine(Line* segment) {
	double xPosition = segment->getStartPoint()->getX();
	double yValue = segment->getStartPoint()->getY();

	list<Line*>::iterator slIter;
	for (slIter = this->sweepLine.begin(); slIter != this->sweepLine.end(); slIter++) {
		Line* currentLine = *slIter;
		double otherYValue = currentLine->getYAt(xPosition);

		if (otherYValue > yValue) {
			break;
		}
	}

	return this->sweepLine.insert(slIter, segment);
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

void SweepLine::printSweepLine() {
	list<Line*>::iterator slIter;

	for (slIter = this->sweepLine.begin(); slIter != this->sweepLine.end(); slIter++) {
		Line* line = *slIter;
		cout << line->toString() << endl;
	}
}
