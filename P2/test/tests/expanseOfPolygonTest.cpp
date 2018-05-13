#include "gtest/gtest.h"
#include <polygon.hpp>

#include <vector>

using namespace std;

namespace {
	TEST(Polygon_Expanse_Test, Square) {
		Line l1(*new Point(0, 1), *new Point(0, 0));
		Line l2(l1.getEndPoint(), *new Point(1, 0));
		Line l3(l2.getEndPoint(), *new Point(1, 1));
		Line l4(l3.getEndPoint(), l1.getStartPoint());

		vector<Line*> polygonEdges;
		polygonEdges.push_back(&l1);
		polygonEdges.push_back(&l2);
		polygonEdges.push_back(&l3);
		polygonEdges.push_back(&l4);

		Polygon polygon(&polygonEdges);
		ASSERT_EQ(1.0, polygon.getExpanse());
	}

	TEST(Polygon_Expanse_Test, Square_With_Triangle) {
		Line l1(*new Point(0, 1), *new Point(0, 0));
		Line l2(l1.getEndPoint(), *new Point(1, 0));
		Line l3(l2.getEndPoint(), *new Point(0.5, 0.5));
		Line l4(l3.getEndPoint(), *new Point(1, 1));
		Line l5(l4.getEndPoint(), l1.getStartPoint());

		vector<Line*> polygonEdges;
		polygonEdges.push_back(&l1);
		polygonEdges.push_back(&l2);
		polygonEdges.push_back(&l3);
		polygonEdges.push_back(&l4);
		polygonEdges.push_back(&l5);

		Polygon polygon(&polygonEdges);
		ASSERT_EQ(0.75, polygon.getExpanse());
	}

	TEST(Polygon_Expanse_Test, Square_With_2_Triangles) {
		Line l1(*new Point(0, 1), *new Point(0.5, 0.5));
		Line l2(l1.getEndPoint(), *new Point(0, 0));
		Line l3(l2.getEndPoint(), *new Point(1, 0));
		Line l4(l3.getEndPoint(), *new Point(0.5, 0.5));
		Line l5(l4.getEndPoint(), *new Point(1, 1));
		Line l6(l5.getEndPoint(), l1.getStartPoint());

		vector<Line*> polygonEdges;
		polygonEdges.push_back(&l1);
		polygonEdges.push_back(&l2);
		polygonEdges.push_back(&l3);
		polygonEdges.push_back(&l4);
		polygonEdges.push_back(&l5);
		polygonEdges.push_back(&l6);

		Polygon polygon(&polygonEdges);
		ASSERT_EQ(0.5, polygon.getExpanse());
	}

	TEST(Polygon_Expanse_Test, Triangle) {
		Line l1(*new Point(0, 1), *new Point(0, 0));
		Line l2(l1.getEndPoint(), *new Point(1, 0));
		Line l3(l2.getEndPoint(), l1.getStartPoint());

		vector<Line*> polygonEdges;
		polygonEdges.push_back(&l1);
		polygonEdges.push_back(&l2);
		polygonEdges.push_back(&l3);

		Polygon polygon(&polygonEdges);
		ASSERT_EQ(0.5, polygon.getExpanse());
	}
}
