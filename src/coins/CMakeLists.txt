add_library(coins "")

target_sources(coins
        PRIVATE
        coin_change.cpp
        PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/coin_change.h
        )

target_include_directories(coins
        PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
        )
