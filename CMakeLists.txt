cmake_minimum_required(VERSION 3.0)
project(math_lib)

enable_testing()

find_library(NAMES criterion)

file(
    GLOB_RECURSE
    source_files
    src/*
)

add_executable(
    testing
    ${source_files}
    ./test/test.c
)

target_link_libraries(
    testing
    criterion
)
