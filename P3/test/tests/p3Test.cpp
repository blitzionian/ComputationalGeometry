#include <p3.hpp>
#include "gtest/gtest.h"

using namespace std;

namespace {
	TEST(Praktikum3Main, vectorContainsPointTest1) {
		vector<Point>* vec = new vector<Point>();

		Point p1(1, 2);
		vec->push_back(p1);
		vec->push_back(Point(2, 3));
		vec->push_back(Point(4, 5));

		ASSERT_TRUE(vectorContains(*vec, p1));
		ASSERT_FALSE(vectorContains(*vec, Point(6, 7)));
	}

	TEST(Praktikum3Main, filterOverlappingLinesTest) {
		vector<Line*>* vec = new vector<Line*>();

		vec->push_back(new Line(new Point(1, 0), new Point(5, 0)));
		vec->push_back(new Line(new Point(4, 0), new Point(10, 0)));
		vec->push_back(new Line(new Point(1, 1), new Point(2, 1)));

		vector<Line*>* filteredVector = filterOverlappingLines(vec);

		ASSERT_EQ(filteredVector->size(), (size_t )2);
	}
}
