add_library(
    vector SHARED
    vector.c
    )

set_target_properties(vector PROPERTIES VERSION ${PROJECT_VERSION})
