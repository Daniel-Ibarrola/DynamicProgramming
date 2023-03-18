//
// Created by daniel on 18/03/23.
//
#include "gtest/gtest.h"
#include "subset.h"


TEST(TestSubsetSum, ValidSumReturnsTrue1)
{
    std::vector<int> set {5, 3, 2, 4};
    ASSERT_TRUE(subsetSum(12, set));
}


TEST(TestSubsetSum, ValidSumReturnsTrue2)
{
    std::vector<int> set {2, 2, 3};
    ASSERT_TRUE(subsetSum(5, set));
}


TEST(TestSubsetSum, InvalidSumReturnsFalse1)
{
    std::vector<int> set {5, 3, 2, 4};
    ASSERT_FALSE(subsetSum(15, set));
}


TEST(TestSubsetSum, InvalidSumReturnsFalse2)
{
    std::vector<int> set {2, 2, 3};
    ASSERT_FALSE(subsetSum(1, set));
}
