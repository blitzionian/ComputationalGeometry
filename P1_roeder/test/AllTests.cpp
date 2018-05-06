/*
 * AllTests.cpp
 *
 *  Created on: 21.04.2018
 *      Author: mroeder
 */

#include "gtest/gtest.h"
#include "from_file_test.cpp"
#include "ccw_test.cpp"
#include "intersection_test.cpp"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}


