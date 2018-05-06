/*
 * from_file_test.cpp
 *
 *  Created on: 21.04.2018
 *      Author: mroeder
 */

#include "gtest/gtest.h"
#include <lines.hpp>

const std::string DUMMY_FILE = "/home/mroeder/workspace/cpp/CompGem1/test/dummy.dat";

namespace {

	TEST (FromFileTest, ReadFileSize) {
		line_list have = lines::from_file(DUMMY_FILE.c_str());
		ASSERT_EQ(2,have.size());
	}

	TEST (FromFileTest, ReadFileContent) {
		line_list have = lines::from_file(DUMMY_FILE.c_str());
		line_it it = have.begin();
		lines::line first = *it;
		++it;
		lines::line second = *it;
		ASSERT_DOUBLE_EQ(0.0,first.first.x);
		ASSERT_DOUBLE_EQ(0.0,first.first.y);
		ASSERT_DOUBLE_EQ(0.0,first.second.x);
		ASSERT_DOUBLE_EQ(0.0,first.second.y);
		ASSERT_DOUBLE_EQ(1.5,second.first.x);
		ASSERT_DOUBLE_EQ(1.5,second.first.y);
		ASSERT_DOUBLE_EQ(1.5,second.second.x);
		ASSERT_DOUBLE_EQ(1.5,second.second.y);
	}
}





