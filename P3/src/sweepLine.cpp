#include <sweepLine.hpp>
#include <iostream>
#include <algorithm>

SweepLine::SweepLine(vector<Line*> lines) :
		lines(lines), eventQueue(lines) {
}

SweepLine::~SweepLine() {
}

void SweepLine::handleStartPoint(Event eventToHandle) {
	Line* segment = eventToHandle.getSegment();
	list<Line*>::iterator insertedElementIt = this->insertIntoSweepLine(segment);

	list<Line*>::iterator below(insertedElementIt);
	below--;

	list<Line*>::iterator above(insertedElementIt);
	above++;

	Line* segmentAbove = *above;
	Line* segmentBelow = *below;

	if (above != this->sweepLine.end() && segment->cross(*segmentAbove)) {
		Crosspoint* crosspoint = new Crosspoint(segment, segmentAbove);
		Event* ev = new Event(crosspoint);
		this->eventQueue.addEvent(*ev);
	}

	if (insertedElementIt != this->sweepLine.begin() && segment->cross(*segmentBelow)) {
		Crosspoint* crosspoint = new Crosspoint(segment, segmentBelow);
		Event* ev = new Event(crosspoint);
		this->eventQueue.addEvent(*ev);
	}
}

void SweepLine::handleEndPoint(Event eventToHandle) {
	Line* segment = eventToHandle.getSegment();

	list<Line*>::iterator slIter;
	for (slIter = this->sweepLine.begin(); slIter != this->sweepLine.end(); slIter++) {
		Line* line = *slIter;

		if (*line == *segment) {
			break;
		}
	}

	list<Line*>::iterator above(slIter);
	above++;

	if (above != sweepLine.end() && slIter != sweepLine.begin()) {
		list<Line*>::iterator below(slIter);
		below--;

		Line* lineAbove = *above;
		Line* lineBelow = *below;

		if (lineAbove->cross(*lineBelow)) {
			this->eventQueue.addEvent(*new Event(new Crosspoint(lineAbove, lineBelow)));
		}
	}

	this->sweepLine.remove(*slIter);
}

void SweepLine::handleIntersection(Event eventToHandle) {
	Crosspoint* intersection = eventToHandle.getCrosspoint();
	this->crosspoints.add(intersection);

	Line* segment1 = intersection->getLine1();
	Line* segment2 = intersection->getLine2();

	list<Line*>::iterator iterBelow = find_if(this->sweepLine.begin(), this->sweepLine.end(),
			[segment1,segment2](Line* other) {
				return other == segment1 || other == segment2;
			});

	list<Line*>::iterator iterAbove(iterBelow);
	++iterAbove;

	Line* segE1 = *iterAbove;
	Line* segE2 = *iterBelow;

	swap(*iterBelow, *iterAbove);

	if (iterAbove != this->sweepLine.end()) {
		list<Line*>::iterator above(iterAbove);
		++above;

		if (above != this->sweepLine.end()) {
			Line *segA = *above;

			if (segE2->cross(*segA)) {
				this->eventQueue.addEvent(*new Event(new Crosspoint(segE2, segA)));
			}
		}
	}

	if (iterBelow != this->sweepLine.begin()) {
		list<Line*>::iterator below(iterBelow);
		--below;

		Line *segB = *below;

		if (segE1->cross(*segB)) {
			this->eventQueue.addEvent(*new Event(new Crosspoint(segE1, segB)));
		}
	}
}

list<Line*>::iterator SweepLine::insertIntoSweepLine(Line* segment) {
	Point* startPoint = segment->getLeftLowerPoint();
	double xPosition = startPoint->getX();
	double yValue = startPoint->getY();

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
	cout << "Anzahl Start Events: " << this->eventQueue.size() << endl;

	list<Event>::iterator eventIterator;

	while (this->eventQueue.hasEvent()) {
		Event nextEvent = this->eventQueue.getNextEvent();

		if (nextEvent.isStartpoint()) {
			handleStartPoint(nextEvent);
		} else if (nextEvent.isEndpoint()) {
			handleEndPoint(nextEvent);
		} else {
			handleIntersection(nextEvent);
		}

		this->eventQueue.removeNextEvent();
	}

	return &this->crosspoints;
}

int SweepLine::getCrossCount() {
	return this->crosspoints.size();
}

void SweepLine::printSweepLine() {
	list<Line*>::iterator slIter;

	for (slIter = this->sweepLine.begin(); slIter != this->sweepLine.end(); slIter++) {
		Line* line = *slIter;
		cout << line->toString() << endl;
	}
}
