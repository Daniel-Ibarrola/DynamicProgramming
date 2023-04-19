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
