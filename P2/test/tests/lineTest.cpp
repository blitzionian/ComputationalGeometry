#include "gtest/gtest.h"
#include <line.hpp>

namespace {
	TEST(Line_Test, Getter) {
		Point expectedStartPoint(1, 2);
		Point expectedEndPoint(3, 4);
		Line line(expectedStartPoint, expectedEndPoint);

		Point actualStartPoint = line.getStartPoint();
		ASSERT_EQ(expectedStartPoint.getX(), actualStartPoint.getX());
		ASSERT_EQ(expectedStartPoint.getY(), actualStartPoint.getY());

		Point actualEndPoint = line.getEndPoint();
		ASSERT_EQ(expectedEndPoint.getX(), actualEndPoint.getX());
		ASSERT_EQ(expectedEndPoint.getY(), actualEndPoint.getY());
	}
}
