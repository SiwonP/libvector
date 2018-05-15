cmake_minimum_required(VERSION 3.6)

project(libmatheng VERSION 1.0.0)

enable_testing()

find_library(NAMES criterion)

add_subdirectory(src)
add_subdirectory(test)
