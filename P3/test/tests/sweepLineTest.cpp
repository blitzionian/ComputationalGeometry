#include "gtest/gtest.h"
#include <sweepLine.hpp>

namespace {

	TEST(SweepLine, TestBeliebig1) {
		Line line1(new Point(140, 270), new Point(230, 240));
		Line line2(new Point(80, 330), new Point(420, 180));
		Line line3(new Point(170, 200), new Point(450, 320));
		Line line4(new Point(240, 330), new Point(370, 170));

		vector<Line*> lines;
		lines.push_back(&line1);
		lines.push_back(&line2);
		lines.push_back(&line3);
		lines.push_back(&line4);

		SweepLine sl(lines);
		Crosspoints* cps = sl.calculateResult();

		ASSERT_EQ(sl.getCrossCount(), 3);

		ASSERT_TRUE(cps->contains(Crosspoint(&line2, &line3)));
		ASSERT_TRUE(cps->contains(Crosspoint(&line3, &line4)));
		ASSERT_TRUE(cps->contains(Crosspoint(&line4, &line2)));
	}

	TEST(SweepLine, TestBeliebig2) {
		Line line1(new Point(140, 270), new Point(230, 240));
		Line line2(new Point(80, 330), new Point(420, 180));
		Line line3(new Point(170, 200), new Point(450, 320));
		Line line4(new Point(240, 330), new Point(370, 170));
		Line line5(new Point(280, 180), new Point(290, 340));

		vector<Line*> lines;
		lines.push_back(&line1);
		lines.push_back(&line2);
		lines.push_back(&line3);
		lines.push_back(&line4);
		lines.push_back(&line5);

		SweepLine sl(lines);
		Crosspoints* cps = sl.calculateResult();

		ASSERT_EQ(sl.getCrossCount(), 6);

		ASSERT_TRUE(cps->contains(Crosspoint(&line2, &line3)));
		ASSERT_TRUE(cps->contains(Crosspoint(&line3, &line4)));
		ASSERT_TRUE(cps->contains(Crosspoint(&line4, &line2)));

		ASSERT_TRUE(cps->contains(Crosspoint(&line5, &line2)));
		ASSERT_TRUE(cps->contains(Crosspoint(&line5, &line3)));
		ASSERT_TRUE(cps->contains(Crosspoint(&line5, &line4)));

		ASSERT_FALSE(cps->contains(Crosspoint(&line1, &line2)));
		ASSERT_FALSE(cps->contains(Crosspoint(&line1, &line3)));
		ASSERT_FALSE(cps->contains(Crosspoint(&line1, &line4)));
		ASSERT_FALSE(cps->contains(Crosspoint(&line1, &line5)));
	}

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

	TEST(SweepLine, Test2Triangles2) {
		Line line1(new Point(100, 360), new Point(190, 260));
		Line line2(new Point(90, 340), new Point(250, 330));
		Line line3(new Point(240, 360), new Point(160, 260));
		Line line4(new Point(80, 230), new Point(240, 220));
		Line line5(new Point(91, 250), new Point(180, 150));
		Line line6(new Point(230, 250), new Point(150, 150));

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

//	TEST(SweepLine, Test2Triangles3) {
//		// Triangle 1
//		Line line1(new Point(100, 100), new Point(400, 400));
//		Line line2(new Point(310, 400), new Point(610, 100));
//		Line line3(new Point(110, 200), new Point(600, 2100));
//
//		// Triangle 2
//		Line line4 = Line(new Point(120, 1100), new Point(410, 1400));
//		Line line5 = Line(new Point(320, 1400), new Point(620, 1100));
//		Line line6 = Line(new Point(130, 1200), new Point(630, 1210));
//
//		vector<Line*> lines;
//		lines.push_back(&line1);
//		lines.push_back(&line2);
//		lines.push_back(&line3);
//
//		lines.push_back(&line4);
//		lines.push_back(&line5);
//		lines.push_back(&line6);
//
//		SweepLine sl(lines);
//		Crosspoints* cps = sl.calculateResult();
//
//		ASSERT_EQ(sl.getCrossCount(), 6);
//
//		ASSERT_TRUE(cps->contains(Crosspoint(&line1, &line2)));
//		ASSERT_TRUE(cps->contains(Crosspoint(&line1, &line3)));
//		ASSERT_TRUE(cps->contains(Crosspoint(&line3, &line2)));
//
//		ASSERT_TRUE(cps->contains(Crosspoint(&line4, &line5)));
//		ASSERT_TRUE(cps->contains(Crosspoint(&line5, &line6)));
//		ASSERT_TRUE(cps->contains(Crosspoint(&line6, &line4)));
//
//		ASSERT_FALSE(cps->contains(Crosspoint(&line1, &line4)));
//	}
}
