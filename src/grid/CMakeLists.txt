add_library(grid "")

target_sources(grid
        PRIVATE
        paths.cpp
        PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/paths.h
        )

target_include_directories(grid
        PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
        )