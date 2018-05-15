add_library(
    matheng SHARED
    complex.c
    matrix.c
    vector.c
    )

set_target_properties(matheng PROPERTIES VERSION ${PROJECT_VERSION})
