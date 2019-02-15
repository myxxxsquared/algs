cmake_minimum_required(VERSION 3.13)
project(algs)

set(CMAKE_CXX_STANDARD 14)

add_executable(algs main.cpp SORT/INSERTION-SORT.h SORT/SORT-test.cpp SORT/MERGE-SORT.h SORT/FIND_INVERSION.h)