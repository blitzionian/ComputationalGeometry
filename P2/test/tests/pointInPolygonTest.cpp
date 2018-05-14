#include "gtest/gtest.h"
#include <polygon.hpp>

namespace {
	TEST(Polygon_In_Polygon_Test, Triangle_On_Top) {
		vector<Point*> polygonKnots;
		polygonKnots.push_back(new Point(0, 0));
		polygonKnots.push_back(new Point(1, 0));
		polygonKnots.push_back(new Point(0.5, 1));
		polygonKnots.push_back(new Point(0, 0));

		Point pointToCheck(0.5, 1);

		Polygon polygon(&polygonKnots);
		ASSERT_TRUE(polygon.includesPoint(&pointToCheck));
	}

	TEST(Polygon_In_Polygon_Test, Triangle_Inside) {
		vector<Point*> polygonKnots;
		polygonKnots.push_back(new Point(0, 0));
		polygonKnots.push_back(new Point(1, 0));
		polygonKnots.push_back(new Point(0.5, 1));
		polygonKnots.push_back(new Point(0, 0));

		Point pointToCheck(0.5, 0.5);

		Polygon polygon(&polygonKnots);
		ASSERT_TRUE(polygon.includesPoint(&pointToCheck));
	}

	TEST(Polygon_In_Polygon_Test, Triangle_Outside) {
		vector<Point*> polygonKnots;
		polygonKnots.push_back(new Point(0, 0));
		polygonKnots.push_back(new Point(1, 0));
		polygonKnots.push_back(new Point(0.5, 1));
		polygonKnots.push_back(new Point(0, 0));

		Point pointToCheck(0.5, 1.5);

		Polygon polygon(&polygonKnots);
		ASSERT_FALSE(polygon.includesPoint(&pointToCheck));
	}

	TEST(Polygon_In_Polygon_Test, Square_On_Knot) {
		vector<Point*> polygonKnots;
		polygonKnots.push_back(new Point(0, 1));
		polygonKnots.push_back(new Point(0, 0));
		polygonKnots.push_back(new Point(1, 0));
		polygonKnots.push_back(new Point(1, 1));
		polygonKnots.push_back(new Point(0, 1));

		Point pointToCheck(0, 0);

		Polygon polygon(&polygonKnots);
		ASSERT_TRUE(polygon.includesPoint(&pointToCheck));
	}

	TEST(Polygon_In_Polygon_Test, Square_Inside) {
		vector<Point*> polygonKnots;
		polygonKnots.push_back(new Point(0, 1));
		polygonKnots.push_back(new Point(0, 0));
		polygonKnots.push_back(new Point(1, 0));
		polygonKnots.push_back(new Point(1, 1));
		polygonKnots.push_back(new Point(0, 1));

		Point pointToCheck(0.75, 0.75);

		Polygon polygon(&polygonKnots);
		ASSERT_TRUE(polygon.includesPoint(&pointToCheck));
	}

	TEST(Polygon_In_Polygon_Test, Square_Outside) {
		vector<Point*> polygonKnots;
		polygonKnots.push_back(new Point(0, 1));
		polygonKnots.push_back(new Point(0, 0));
		polygonKnots.push_back(new Point(1, 0));
		polygonKnots.push_back(new Point(1, 1));
		polygonKnots.push_back(new Point(0, 1));

		Point pointToCheck(1.5, 1.5);

		Polygon polygon(&polygonKnots);
		ASSERT_FALSE(polygon.includesPoint(&pointToCheck));
	}

	TEST(Polygon_In_Polygon_Test, Square_On_Edge) {
		vector<Point*> polygonKnots;
		polygonKnots.push_back(new Point(0, 1));
		polygonKnots.push_back(new Point(0, 0));
		polygonKnots.push_back(new Point(1, 0));
		polygonKnots.push_back(new Point(1, 1));
		polygonKnots.push_back(new Point(0, 1));

		Point pointToCheck(0.5, 0);

		Polygon polygon(&polygonKnots);
		ASSERT_TRUE(polygon.includesPoint(&pointToCheck));
	}
}
