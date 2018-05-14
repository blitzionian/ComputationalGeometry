#include "gtest/gtest.h"
#include <polygon.hpp>

#include <vector>

using namespace std;

namespace {
	TEST(Polygon_Expanse_Test, Square) {
		vector<Point*> polygonKnots;
		polygonKnots.push_back(new Point(0, 1));
		polygonKnots.push_back(new Point(0, 0));
		polygonKnots.push_back(new Point(1, 0));
		polygonKnots.push_back(new Point(1, 1));
		polygonKnots.push_back(new Point(0, 1));

		Polygon polygon(&polygonKnots);
		ASSERT_EQ(1.0, polygon.getExpanse());
	}

	TEST(Polygon_Expanse_Test, Square_With_Triangle) {
		vector<Point*> polygonKnots;
		polygonKnots.push_back(new Point(0, 1));
		polygonKnots.push_back(new Point(0, 0));
		polygonKnots.push_back(new Point(1, 0));
		polygonKnots.push_back(new Point(0.5, 0.5));
		polygonKnots.push_back(new Point(1, 1));
		polygonKnots.push_back(new Point(0, 1));

		Polygon polygon(&polygonKnots);
		ASSERT_EQ(0.75, polygon.getExpanse());
	}

	TEST(Polygon_Expanse_Test, Square_With_2_Triangles) {
		vector<Point*> polygonKnots;
		polygonKnots.push_back(new Point(0, 1));
		polygonKnots.push_back(new Point(0.5, 0.5));
		polygonKnots.push_back(new Point(0, 0));
		polygonKnots.push_back(new Point(1, 0));
		polygonKnots.push_back(new Point(0.5, 0.5));
		polygonKnots.push_back(new Point(1, 1));
		polygonKnots.push_back(new Point(0, 1));

		Polygon polygon(&polygonKnots);
		ASSERT_EQ(0.5, polygon.getExpanse());
	}

	TEST(Polygon_Expanse_Test, Triangle) {
		vector<Point*> polygonKnots;
		polygonKnots.push_back(new Point(0, 1));
		polygonKnots.push_back(new Point(0, 0));
		polygonKnots.push_back(new Point(1, 0));
		polygonKnots.push_back(new Point(0, 1));

		Polygon polygon(&polygonKnots);
		ASSERT_EQ(0.5, polygon.getExpanse());
	}
}
