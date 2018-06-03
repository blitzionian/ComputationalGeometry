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
}
