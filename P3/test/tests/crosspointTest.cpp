#include "gtest/gtest.h"
#include <crosspoint.hpp>

namespace {
	TEST(Crosspoint_Test, opEqual) {
		Crosspoint cp1(new Line(new Point(0, 0), new Point(1, 1)), new Line(new Point(0, 1), new Point(1, 0)));
		Crosspoint cp2(new Line(new Point(0, 0), new Point(1, 1)), new Line(new Point(0, 1), new Point(1, 0)));

		ASSERT_TRUE(cp1 == cp2);

		Crosspoint cp3(new Line(new Point(0, 0), new Point(2, 1)), new Line(new Point(0, 1), new Point(1, 0)));
		ASSERT_FALSE(cp1 == cp3);
	}

	TEST(Crosspoint_Test, Cross_Test1) {
		Point startPoint1(0, 0);
		Point endPoint1(1, 1);
		Line line1(&startPoint1, &endPoint1);

		Point startPoint2(0, 1);
		Point endPoint2(1, 0);
		Line line2(&startPoint2, &endPoint2);

		Crosspoint crosspoint(&line1, &line2);
		Point* cross = crosspoint.getPoint();

		ASSERT_DOUBLE_EQ(0.5, cross->getX());
		ASSERT_DOUBLE_EQ(0.5, cross->getY());
	}

	TEST(Crosspoint_Test, Cross_Test2) {
		Point startPoint1(1, 0);
		Point endPoint1(2, 1);
		Line line1(&startPoint1, &endPoint1);

		Point startPoint2(1, 1);
		Point endPoint2(2, 0);
		Line line2(&startPoint2, &endPoint2);

		Crosspoint crosspoint(&line1, &line2);
		Point* cross = crosspoint.getPoint();

		ASSERT_DOUBLE_EQ(1.5, cross->getX());
		ASSERT_DOUBLE_EQ(0.5, cross->getY());
	}

	TEST(Crosspoint_Test, Cross_Test3) {
		Point startPoint1(1, 1);
		Point endPoint1(2, 2);
		Line line1(&startPoint1, &endPoint1);

		Point startPoint2(1, 2);
		Point endPoint2(2, 1);
		Line line2(&startPoint2, &endPoint2);

		Crosspoint crosspoint(&line1, &line2);
		Point* cross = crosspoint.getPoint();

		ASSERT_DOUBLE_EQ(1.5, cross->getX());
		ASSERT_DOUBLE_EQ(1.5, cross->getY());
	}

	TEST(Crosspoint_Test, Cross_Test4) {
		Point startPoint1(1, 1);
		Point endPoint1(3, 3);
		Line line1(&startPoint1, &endPoint1);

		Point startPoint2(1, 3);
		Point endPoint2(3, 1);
		Line line2(&startPoint2, &endPoint2);

		Crosspoint crosspoint(&line1, &line2);
		Point* cross = crosspoint.getPoint();

		ASSERT_DOUBLE_EQ(2, cross->getX());
		ASSERT_DOUBLE_EQ(2, cross->getY());
	}

	TEST(Crosspoint_Test, Cross_Test5) {
		Point startPoint1(1, 1);
		Point endPoint1(5, 3);
		Line line1(&startPoint1, &endPoint1);

		Point startPoint2(1, 3);
		Point endPoint2(5, 1);
		Line line2(&startPoint2, &endPoint2);

		Crosspoint crosspoint(&line1, &line2);
		Point* cross = crosspoint.getPoint();

		ASSERT_DOUBLE_EQ(3, cross->getX());
		ASSERT_DOUBLE_EQ(2, cross->getY());
	}

	TEST(Crosspoint_Test, Cross_Test6) {
		Point startPoint1(1, 1);
		Point endPoint1(2, 2);
		Line line1(&startPoint1, &endPoint1);

		Point startPoint2(1, 2);
		Point endPoint2(4, 1);
		Line line2(&startPoint2, &endPoint2);

		Crosspoint crosspoint(&line1, &line2);
		Point* cross = crosspoint.getPoint();

		ASSERT_DOUBLE_EQ(1.75, cross->getX());
		ASSERT_DOUBLE_EQ(1.75, cross->getY());
	}
}
