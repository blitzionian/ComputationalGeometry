#include <sweepLine.hpp>

SweepLine::SweepLine(vector<Line*> lines) :
		lines(lines) {
}

SweepLine::~SweepLine() {
}

void SweepLine::calculateResult() {
	this->initEventQueue();

}

void SweepLine::initEventQueue() {
	vector<Line*>::iterator lineIterator;

	for (lineIterator = this->lines.begin(); lineIterator != this->lines.end(); lineIterator++) {
		Line line = *(*lineIterator);

		Event eventStart(EventType::SEGMENT_START, &line);
		Event eventEnd(EventType::SEGMENT_END, &line);

		this->eventQueue.push_back(eventStart);
		this->eventQueue.push_back(eventEnd);
	}
}

int SweepLine::getCrossCount() {
	return this->crossCount;
}
