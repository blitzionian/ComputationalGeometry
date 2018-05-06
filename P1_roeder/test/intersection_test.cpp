#include "gtest/gtest.h"
#include <lines.hpp>

namespace {
	TEST (Intersection_Test, Out_Of_Bounds_Inline) {
		lines::point p1 = {1, 1};
		lines::point q1 = {2, 1};
		lines::line l1 = {p1, q1};
		lines::point p2 = {3, 1};
		lines::point q2 = {4, 1};
		lines::line l2 = {p2, q2};
		bool have = lines::intersecting(l1,l2);
		ASSERT_FALSE(have);
	}

	TEST (Intersection_Test, Out_Of_Bounds_Parallel) {
		lines::point p1 = {1, 1};
		lines::point q1 = {2, 1};
		lines::line l1 = {p1, q1};
		lines::point p2 = {1, 2};
		lines::point q2 = {2, 2};
		lines::line l2 = {p2, q2};
		bool have = lines::intersecting(l1,l2);
		ASSERT_FALSE(have);
	}

	TEST (Intersection_Test, Out_Of_Bounds_No_CCW) {
		lines::point p1 = {1, 1};
		lines::point q1 = {2, 1};
		lines::line l1 = {p1, q1};
		lines::point p2 = {3, 5};
		lines::point q2 = {4, 6};
		lines::line l2 = {p2, q2};
		bool have = lines::intersecting(l1,l2);
		ASSERT_FALSE(have);
	}

	TEST (Intersection_Test, Out_Of_Bounds_With_CCW) {
		lines::point p1 = {1, 1};
		lines::point q1 = {2, 1};
		lines::line l1 = {p1, q1};
		lines::point p2 = {3, 0.5};
		lines::point q2 = {3, 1.5};
		lines::line l2 = {p2, q2};
		bool have = lines::intersecting(l1,l2);
		ASSERT_FALSE(have);
	}

	TEST (Intersection_Test, One_Point_On_Line) {
		lines::point p1 = {1, 1};
		lines::point q1 = {2, 1};
		lines::line l1 = {p1, q1};
		lines::point p2 = {1.5, 1};
		lines::point q2 = {4, 2};
		lines::line l2 = {p2, q2};
		bool have = lines::intersecting(l1,l2);
		ASSERT_TRUE(have);
	}

	TEST (Intersection_Test, First_In_Second) {
		lines::point p1 = {1, 1};
		lines::point q1 = {2, 1};
		lines::line l1 = {p1, q1};
		lines::point p2 = {0.5, 1};
		lines::point q2 = {2.5, 1};
		lines::line l2 = {p2, q2};
		bool have = lines::intersecting(l1,l2);
		ASSERT_TRUE(have);
	}

	TEST (Intersection_Test, Second_In_First) {
		lines::point p1 = {1, 1};
		lines::point q1 = {4, 1};
		lines::line l1 = {p1, q1};
		lines::point p2 = {2, 1};
		lines::point q2 = {3, 1};
		lines::line l2 = {p2, q2};
		bool have = lines::intersecting(l1,l2);
		ASSERT_TRUE(have);
	}

	TEST (Intersection_Test, Both_In_Bounds_With_CCW) {
		lines::point p1 = {1, 1};
		lines::point q1 = {2, 1};
		lines::line l1 = {p1, q1};
		lines::point p2 = {1.5, 0.5};
		lines::point q2 = {1.5, 1.5};
		lines::line l2 = {p2, q2};
		bool have = lines::intersecting(l1,l2);
		ASSERT_TRUE(have);
	}

	TEST (Intersection_Test, One_Shared_Point) {
		lines::point p1 = {1, 1};
		lines::point q1 = {2, 1};
		lines::line l1 = {p1, q1};
		lines::point p2 = {2, 1};
		lines::point q2 = {4, 2};
		lines::line l2 = {p2, q2};
		bool have = lines::intersecting(l1,l2);
		ASSERT_TRUE(have);
	}

	TEST (Intersection_Test, Diagonal_Match_Out_Of_Bounds) {
		lines::point p1 = {1, 1};
		lines::point q1 = {2, 1};
		lines::line l1 = {p1, q1};
		lines::point p2 = {0, 0};
		lines::point q2 = {3, 2};
		lines::line l2 = {p2, q2};
		bool have = lines::intersecting(l1,l2);
		ASSERT_TRUE(have);
	}

	TEST (Intersection_Test, Diagonal_No_Match_Right_Corner) {
		lines::point p1 = {1, 1};
		lines::point q1 = {2, 1};
		lines::line l1 = {p1, q1};
		lines::point p2 = {2, 2};
		lines::point q2 = {3, 1};
		lines::line l2 = {p2, q2};
		bool have = lines::intersecting(l1,l2);
		ASSERT_FALSE(have);
	}

	TEST (Intersection_Test, Diagonal_No_Match_Center) {
		lines::point p1 = {1, 1};
		lines::point q1 = {2, 1};
		lines::line l1 = {p1, q1};
		lines::point p2 = {1.5, 2};
		lines::point q2 = {10, 1};
		lines::line l2 = {p2, q2};
		bool have = lines::intersecting(l1,l2);
		ASSERT_FALSE(have);
	}

	TEST (Intersection_Test, Diagonal_No_Match_Left_Corner) {
		lines::point p1 = {1, 1};
		lines::point q1 = {2, 1};
		lines::line l1 = {p1, q1};
		lines::point p2 = {1, 5};
		lines::point q2 = {5, 0};
		lines::line l2 = {p2, q2};
		bool have = lines::intersecting(l1,l2);
		ASSERT_FALSE(have);
	}
}


