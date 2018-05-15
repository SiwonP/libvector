find_library(NAMES criterion)

add_executable(unit_test_vector_basics
    test_vector_basics.c
    ../src/complex.c
    ../src/vector.c
    ../src/matrix.c
    )

add_executable(unit_test_complex_basics
    test_complex_basics.c
    ../src/complex.c
    ../src/vector.c
    ../src/matrix.c
    )

add_executable(unit_test_matrix_basics
    test_matrix_basics.c
    ../src/complex.c
    ../src/vector.c
    ../src/matrix.c
    )

add_test(NAME unit_test_vector_basics COMMAND unit_test_vector_basics) 

add_test(NAME unit_test_complex_basics COMMAND unit_test_complex_basics) 

add_test(NAME unit_test_matrix_basics COMMAND unit_test_matrix_basics) 

target_link_libraries(unit_test_vector_basics criterion)
target_link_libraries(unit_test_complex_basics criterion)
target_link_libraries(unit_test_matrix_basics criterion)

target_link_libraries(unit_test_vector_basics m)
target_link_libraries(unit_test_complex_basics m)
target_link_libraries(unit_test_matrix_basics m)

