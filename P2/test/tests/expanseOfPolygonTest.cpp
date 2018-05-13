#include "gtest/gtest.h"
#include <polygon.hpp>

#include <vector>

using namespace std;

namespace {
	TEST(Polygon_Expanse_Test, Square) {
		Line l1(*new Point(0, 1), *new Point(0, 0));
		Line l2(*new Point(0, 0), *new Point(1, 0));
		Line l3(*new Point(1, 0), *new Point(1, 1));
		Line l4(*new Point(1, 1), *new Point(0, 1));

		vector<Line> polygonLines;

		path_t paths = new vector<Line*>();
		paths->push_back(&l1);
		paths->push_back(&l2);
		paths->push_back(&l3);
		paths->push_back(&l4);

		vector<path_t> allPaths;
		allPaths.push_back(paths);

		Polygon polygon(new string(""), &allPaths);

		ASSERT_EQ(1.0, polygon.getExpanse());

//		cout << "Area: " << polygon.getExpanse() << endl;
	}
}
