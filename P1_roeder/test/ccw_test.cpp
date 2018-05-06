/*
 * ccw_test.cpp
 *
 *  Created on: 21.04.2018
 *      Author: mroeder
 */


#include "gtest/gtest.h"
#include <lines.hpp>


namespace {

	TEST (Ccw_Test, Positive) {
		lines::point p = {1, 1};
		lines::point q = {2, 1};
		lines::point r = {1.5, 2};
		double have = lines::ccw(p,q,r);
		ASSERT_GT(have,0.0);
	}

	TEST (Ccw_Test, Negative) {
		lines::point p = {1, 1};
		lines::point q = {2, 1};
		lines::point r = {1.5, 0};
		double have = lines::ccw(p,q,r);
		ASSERT_LT(have,0.0);
	}

	TEST (Ccw_Test, Zero) {
		lines::point p = {1, 1};
		lines::point q = {2, 1};
		lines::point r = {1.5, 1};
		double have = lines::ccw(p,q,r);
		ASSERT_DOUBLE_EQ(have,0.0);
	}
}

