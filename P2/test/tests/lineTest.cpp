#include "gtest/gtest.h"
#include <line.hpp>

namespace {
	TEST(Line_Test, Expanse1) {
		Point startPoint(0, 0);
		Point endPoint(1, 0);
		Line line(startPoint, endPoint);

		ASSERT_DOUBLE_EQ(0, line.getExpanseOverXLine());
	}

	TEST(Line_Test, Expanse2) {
		Point startPoint(0, 1);
		Point endPoint(1, 1);
		Line line(startPoint, endPoint);

		ASSERT_DOUBLE_EQ(-1, line.getExpanseOverXLine());
	}

	TEST(Line_Test, Expanse3) {
		Point startPoint(1, 1);
		Point endPoint(0, 1);
		Line line(startPoint, endPoint);

		ASSERT_DOUBLE_EQ(1, line.getExpanseOverXLine());
	}

	TEST(Line_Test, Expanse4) {
		Point startPoint(0, 1);
		Point endPoint(0.5, 0.5);
		Line line(startPoint, endPoint);

		ASSERT_DOUBLE_EQ(-0.375, line.getExpanseOverXLine());
	}

	TEST(Line_Test, Expanse5) {
		Point startPoint(0.5, 0.5);
		Point endPoint(0, 0);
		Line line(startPoint, endPoint);

		ASSERT_DOUBLE_EQ(0.125, line.getExpanseOverXLine());
	}

	TEST(Line_Test, Expanse6) {
		Point startPoint(0.5, 0.5);
		Point endPoint(1, 1);
		Line line(startPoint, endPoint);

		ASSERT_DOUBLE_EQ(-0.375, line.getExpanseOverXLine());
	}

	TEST(Line_Test, Expanse7) {
		Point startPoint(1, 1);
		Point endPoint(0, 1);
		Line line(startPoint, endPoint);

		ASSERT_DOUBLE_EQ(1, line.getExpanseOverXLine());
	}

	TEST(Line_Test, Getter) {
		Point expectedStartPoint(1, 2);
		Point expectedEndPoint(3, 4);
		Line line(expectedStartPoint, expectedEndPoint);

		Point actualStartPoint = line.getStartPoint();
		ASSERT_DOUBLE_EQ(expectedStartPoint.getX(), actualStartPoint.getX());
		ASSERT_DOUBLE_EQ(expectedStartPoint.getY(), actualStartPoint.getY());

		Point actualEndPoint = line.getEndPoint();
		ASSERT_DOUBLE_EQ(expectedEndPoint.getX(), actualEndPoint.getX());
		ASSERT_DOUBLE_EQ(expectedEndPoint.getY(), actualEndPoint.getY());
	}
}
