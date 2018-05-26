#include "gtest/gtest.h"
#include <crosspoints.hpp>

namespace {
	TEST(Crosspoints, contains) {
		Crosspoints cps;

		Crosspoint cp1(new Line(new Point(0, 0), new Point(1, 1)), new Line(new Point(0, 1), new Point(1, 0)));
		cps.add(&cp1);

		ASSERT_TRUE(cps.contains(cp1));

		Crosspoint cp2(new Line(new Point(0, 0), new Point(1, 1)), new Line(new Point(0, 1), new Point(1, 0)));
		ASSERT_TRUE(cps.contains(cp2));

		Crosspoint cp3(new Line(new Point(1, 1), new Point(1, 1)), new Line(new Point(0, 1), new Point(1, 0)));
		ASSERT_FALSE(cps.contains(cp3));
	}

}
