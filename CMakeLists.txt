cmake_minimum_required (VERSION 3.22.0)

project (
  sort
  VERSION 0.0.1
  DESCRIPTION "Sorting algorithm implementations in C++"
  HOMEPAGE_URL "https://github.com/syntaxonly/sort"
  LANGUAGES CXX)

include (CTest)
enable_testing ()

set (CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake")
include (add_sort_algorithm)
include (add_sort_test)

find_package (doctest QUIET REQUIRED CONFIG)

add_sort_algorithm (insertion)
add_sort_test (insertion_test tests/insertion_test.cpp)

add_sort_algorithm (selection)
