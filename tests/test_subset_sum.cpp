//
// Created by daniel on 18/03/23.
//
#include "gtest/gtest.h"
#include "subset.h"


TEST(TestSubsetSum, ValidSumReturnsTrue)
{
    std::vector<int> set {5, 3, 2, 4};
    ASSERT_TRUE(subsetSum(12, set));
}


TEST(TestSubsetSum, InvalidSumReturnsFalse)
{
    std::vector<int> set {5, 3, 2, 4};
    ASSERT_FALSE(subsetSum(15, set));
}
