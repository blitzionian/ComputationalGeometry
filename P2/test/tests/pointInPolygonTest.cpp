#include "gtest/gtest.h"
#include <polygon.hpp>

namespace {
	TEST(Polygon_In_Polygon_Test, Triangle_Kollinear_Edge) {
		vector<Point*> polygonKnots;
		polygonKnots.push_back(new Point(1, 1));
		polygonKnots.push_back(new Point(0, 0));
		polygonKnots.push_back(new Point(1, 0));
		polygonKnots.push_back(new Point(1, 1));

		Point pointToCheck(-1, -1);

		Polygon polygon(&polygonKnots);
		ASSERT_FALSE(polygon.includesPoint(&pointToCheck));
	}

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

	TEST(Polygon_In_Polygon_Test, Square_Inside_Middle) {
		vector<Point*> polygonKnots;
		polygonKnots.push_back(new Point(0, 1));
		polygonKnots.push_back(new Point(0, 0));
		polygonKnots.push_back(new Point(1, 0));
		polygonKnots.push_back(new Point(1, 1));
		polygonKnots.push_back(new Point(0, 1));

		Point pointToCheck(0.5, 0.5);

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

		Point pointToCheck(0.7, 0.3);

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

	TEST(Polygon_In_Polygon_Test, Seitenwechsel) {
		vector<Point*> polygonKnots;
		polygonKnots.push_back(new Point(0, 0));
		polygonKnots.push_back(new Point(1, 0));
		polygonKnots.push_back(new Point(1, 1));
		polygonKnots.push_back(new Point(2, 1));
		polygonKnots.push_back(new Point(3, 2));
		polygonKnots.push_back(new Point(0, 2));
		polygonKnots.push_back(new Point(0, 0));

		Point pointToCheck(1.5, 0.5);

		Polygon polygon(&polygonKnots);
		ASSERT_FALSE(polygon.includesPoint(&pointToCheck));
	}

	TEST(Polygon_In_Polygon_Test, Seitenwechsel2_In) {
		vector<Point*> polygonKnots;
		polygonKnots.push_back(new Point(0, 0));
		polygonKnots.push_back(new Point(5, 0));
		polygonKnots.push_back(new Point(5, 5));
		polygonKnots.push_back(new Point(3, 3));
		polygonKnots.push_back(new Point(0, 3));
		polygonKnots.push_back(new Point(0, 0));

		Point pointToCheck(2, 2);

		Polygon polygon(&polygonKnots);
		ASSERT_TRUE(polygon.includesPoint(&pointToCheck));
	}

	TEST(Polygon_In_Polygon_Test, Seitenwechsel2_Out) {
		vector<Point*> polygonKnots;
		polygonKnots.push_back(new Point(0, 0));
		polygonKnots.push_back(new Point(5, 0));
		polygonKnots.push_back(new Point(5, 5));
		polygonKnots.push_back(new Point(3, 3));
		polygonKnots.push_back(new Point(0, 3));
		polygonKnots.push_back(new Point(0, 0));

		Point pointToCheck(-1, -1);

		Polygon polygon(&polygonKnots);
		ASSERT_FALSE(polygon.includesPoint(&pointToCheck));
	}
}
