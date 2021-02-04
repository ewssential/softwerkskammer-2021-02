cmake_minimum_required(VERSION 3.10)
project(kata)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(googletest)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(kata_tests_run mars_rover.test.cpp mars_rover.test.support.cpp mars_rover.cpp mars_rover.h)
target_link_libraries(kata_tests_run gtest gtest_main)
