add_executable(main main.cpp)

add_subdirectory(knapsack)
add_subdirectory(subset)
add_subdirectory(coins)

target_link_libraries(main
        PRIVATE
            knapsack
            subset
            coins
)
