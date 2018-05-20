#include "event.hpp"

Event::Event(EventType eventType, Line* line) :
		eventType(eventType), line(line) {
}

Event::~Event() {
}

