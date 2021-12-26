cmake_minimum_required(VERSION 3.5)

project(Dirstat LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#Main target
add_executable(
    Dirstat
    src/main.cpp
    src/main.h
)

#Test target
add_executable(
    test_list
    test/test_list.cpp)

#Add src to the include directories in test_list.cpp
target_include_directories(
    test_list PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/src"
    )
