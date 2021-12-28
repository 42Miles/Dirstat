cmake_minimum_required(VERSION 3.9)
project(Dirstat CXX)

set(CMAKE_CXX_STANDARD 17)

set(SOURCES src/dirstat.cpp)
set(INCLUDES src/dirstat.hpp)

find_package(GTest REQUIRED)

add_executable(dirstat src/main.cpp ${SOURCES})
target_include_directories(dirstat PRIVATE ${INCLUDES})

add_executable(test_list test/test_list.cpp ${SOURCES})
target_include_directories(test_list PRIVATE ${INCLUDES})
target_link_libraries(test_list GTest::GTest GTest::Main)

enable_testing()
include(GoogleTest)
gtest_add_tests(TARGET test_list AUTO)