cmake_minimum_required(VERSION 3.6)

project(libvector VERSION 1.0.0)

enable_testing()
enable_language(C)
set(CMAKE_C_STANDARD 11)

find_library(NAMES criterion)

add_subdirectory(src)
add_subdirectory(test)
