cmake_minimum_required(VERSION 3.10)
project(P3)

# set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")

include_directories(input)
include_directories(lib)
include_directories(test/contrib/)
include_directories(test/contrib/gtest)

add_executable(P3
        input/s_100000_1.dat
        input/s_10000_1.dat
        input/s_1000_1.dat
        input/s_1000_10.dat
        lib/event.hpp
        lib/line.hpp
        lib/point.hpp
        lib/line_sweep.hpp
        src/line.cpp
        src/point.cpp
        src/Praktikum3.cpp
        src/line_sweep.cpp lib/event_queue.hpp src/event_queue.cpp lib/sweep_line_data.hpp src/sweep_line_data.cpp)

add_executable(P3_Test
        input/s_100000_1.dat
        input/s_10000_1.dat
        input/s_1000_1.dat
        input/s_1000_10.dat
        lib/event.hpp
        lib/line.hpp
        lib/point.hpp
        lib/line_sweep.hpp
        src/line.cpp
        src/point.cpp
        test/contrib/gtest/gtest-all.cc
        test/contrib/gtest/gtest.h
        test/tests/AllTests.cpp
        test/tests/event_test.cpp
        test/tests/lineTest.cpp
        src/line_sweep.cpp lib/event_queue.hpp src/event_queue.cpp lib/sweep_line_data.hpp src/sweep_line_data.cpp)