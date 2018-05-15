find_library(NAMES criterion)

add_executable(unittest
    test.c
    ../src/complex.c
    ../src/vector.c
    ../src/matrix.c
    )

add_test(NAME UnitTest COMMAND unittest)

target_link_libraries(unittest criterion)
target_link_libraries(unittest m)
