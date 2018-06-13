find_library(NAMES criterion)

set(
    TESTS
    test_vector_basics.c
    )

foreach(test in ${TESTS})
endforeach(test)

add_executable(unit_test_vector_basics
    test_vector_basics.c
    ../src/vector.c
    )

add_test(NAME unit_test_vector_basics COMMAND unit_test_vector_basics) 


target_link_libraries(unit_test_vector_basics criterion)

target_link_libraries(unit_test_vector_basics m)
