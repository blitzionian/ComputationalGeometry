#include "event.hpp"
#include "gtest/gtest.h"

namespace {

	TEST(Event, TestLessThan) {
		Line* line = new Line(new Point(1, 1), new Point(2, 2));

		Event e1(EventType::SEGMENT_START, line);
		Event e2(EventType::SEGMENT_END, line);

		ASSERT_TRUE(e1 < e2);
	}

	TEST(Event, TestLessThan2) {
		Line* line = new Line(new Point(2, 2), new Point(1, 1));

		Event e1(EventType::SEGMENT_START, line);
		Event e2(EventType::SEGMENT_END, line);

		ASSERT_TRUE(e1 < e2);
	}

	TEST(Event, TestLessThan3) {
		Line* line = new Line(new Point(2, 1), new Point(2, 2));

		Event e1(EventType::SEGMENT_START, line);
		Event e2(EventType::SEGMENT_END, line);

		ASSERT_TRUE(e1 < e2);
	}

	TEST(Event, TestLessThan4) {
		Line* line = new Line(new Point(2, 2), new Point(2, 1));

		Event e1(EventType::SEGMENT_START, line);
		Event e2(EventType::SEGMENT_END, line);

		ASSERT_TRUE(e1 < e2);
	}
}
