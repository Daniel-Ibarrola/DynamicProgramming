add_library(subset "")

target_sources(subset
        PRIVATE
        subset.cpp
        PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/subset.h
        )

target_include_directories(subset
        PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
        )
