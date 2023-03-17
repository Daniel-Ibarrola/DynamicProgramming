add_library(knapsack "")

target_sources(knapsack
        PRIVATE
            knapsack.cpp
        PUBLIC
            ${CMAKE_CURRENT_LIST_DIR}/knapsack.h
)

target_include_directories(knapsack
        PUBLIC
            ${CMAKE_CURRENT_LIST_DIR}
)
