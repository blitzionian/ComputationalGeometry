#include "gtest/gtest.h"
#include <sweepLine.hpp>

namespace {

	TEST(SweepLine, TestTriangle) {
		Line line1(new Point(1, 1), new Point(4, 4));
		Line line2(new Point(3.1, 4), new Point(6.1, 1));
		Line line3(new Point(1.1, 2), new Point(6, 2.1));

		vector<Line*> lines;
		lines.push_back(&line1);
		lines.push_back(&line2);
		lines.push_back(&line3);

		SweepLine sl(lines);
		Crosspoints* cps = sl.calculateResult();

		ASSERT_EQ(sl.getCrossCount(), 3);

		ASSERT_TRUE(cps->contains(Crosspoint(&line1, &line2)));
		ASSERT_TRUE(cps->contains(Crosspoint(&line1, &line3)));
		ASSERT_TRUE(cps->contains(Crosspoint(&line3, &line2)));
	}

	TEST(SweepLine, Test2Triangles) {
		// Triangle 1
		Line line1(new Point(1, 1), new Point(4, 4));
		Line line2(new Point(3.1, 4), new Point(6.1, 1));
		Line line3(new Point(1.1, 2), new Point(6, 2.1));

		// Triangle 2
		Line line4 = Line(new Point(1.2, 11), new Point(4.1, 14));
		Line line5 = Line(new Point(3.2, 14), new Point(6.2, 11));
		Line line6 = Line(new Point(1.3, 12), new Point(6.3, 12.1));

		vector<Line*> lines;
		lines.push_back(&line1);
		lines.push_back(&line2);
		lines.push_back(&line3);

		lines.push_back(&line4);
		lines.push_back(&line5);
		lines.push_back(&line6);

		SweepLine sl(lines);
		Crosspoints* cps = sl.calculateResult();

		ASSERT_EQ(sl.getCrossCount(), 6);

		ASSERT_TRUE(cps->contains(Crosspoint(&line1, &line2)));
		ASSERT_TRUE(cps->contains(Crosspoint(&line1, &line3)));
		ASSERT_TRUE(cps->contains(Crosspoint(&line3, &line2)));

		ASSERT_TRUE(cps->contains(Crosspoint(&line4, &line5)));
		ASSERT_TRUE(cps->contains(Crosspoint(&line5, &line6)));
		ASSERT_TRUE(cps->contains(Crosspoint(&line6, &line4)));

		ASSERT_FALSE(cps->contains(Crosspoint(&line1, &line4)));
	}

	TEST(SweepLine, TestTriangle2) {
		// Triangle 2
		Line line4 = Line(new Point(1.2, 11), new Point(4.1, 14));
		Line line5 = Line(new Point(3.2, 14), new Point(6.2, 11));
		Line line6 = Line(new Point(1.3, 12), new Point(6.3, 12.1));

		vector<Line*> lines;
		lines.push_back(&line4);
		lines.push_back(&line5);
		lines.push_back(&line6);

		SweepLine sl(lines);
		Crosspoints* cps = sl.calculateResult();

		ASSERT_EQ(sl.getCrossCount(), 3);

		ASSERT_TRUE(cps->contains(Crosspoint(&line4, &line5)));
		ASSERT_TRUE(cps->contains(Crosspoint(&line5, &line6)));
		ASSERT_TRUE(cps->contains(Crosspoint(&line6, &line4)));
	}
}
