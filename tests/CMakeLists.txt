project(Google_tests)
add_subdirectory(lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(
        Google_Tests_run
        test_knapsack.cpp
        test_subset.cpp
        test_coin_change.cpp
        test_paths.cpp
)

target_link_libraries(Google_Tests_run knapsack)
target_link_libraries(Google_Tests_run subset)
target_link_libraries(Google_Tests_run coins)
target_link_libraries(Google_Tests_run grid)
target_link_libraries(Google_Tests_run gtest gtest_main)
