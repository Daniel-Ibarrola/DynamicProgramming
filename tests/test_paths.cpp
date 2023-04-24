//
// Created by daniel on 19/04/23.
//

#include "gtest/gtest.h"
#include "paths.h"


TEST(TestUniquePaths, EmptyGrid)
{
    ASSERT_EQ(numUniquePaths(0, 0), 0);
}


TEST(TestUniquePaths, Grid2X2)
{
    ASSERT_EQ(numUniquePaths(2, 2), 2);
}


TEST(TestUniquePaths, Grid3X3)
{
    ASSERT_EQ(numUniquePaths(3, 3), 6);
}


TEST(TestUniquePaths, Grid3X4)
{
    ASSERT_EQ(numUniquePaths(3, 4), 10);
}


TEST(TestUniquePathsWithObstacles, GridWithNoObstacles)
{
    matrix grid (3, std::vector<int>(3, 0));
    ASSERT_EQ(numUniquePaths(grid), 6);
}


TEST(TestUniquePathsWithObstacles, Grid3X3)
{
    matrix grid (3, std::vector<int>(3, 0));
    grid[1][1] = 1;
    ASSERT_EQ(numUniquePaths(grid), 2);
}


TEST(TestUniquePathsWithObstacles, Grid3X4)
{
    matrix grid {
            {0, 0, 0, 0},
            {1, 0, 1, 0},
            {0, 0 ,0, 0},
    };
    ASSERT_EQ(numUniquePaths(grid), 2);
}


TEST(TestUniquePathsWithObstacles, Grid5X4)
{
    matrix grid (5, std::vector<int>(4, 0));
    grid[0][1] = 1;
    grid[2][0] = 1;
    ASSERT_EQ(numUniquePaths(grid), 0);
}
