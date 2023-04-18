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


TEST(TestSubsetsWithSum, Set1)
{
    std::vector<int> set {3, 1, 2, 3};
    ASSERT_EQ(subsetsWithSum(set, 6), 3);
}


TEST(TestSubsetsWithSum, Set2)
{
    std::vector<int> set {1, 2, 1};
    ASSERT_EQ(subsetsWithSum(set, 3), 2);
}


TEST(TestSubsetsWithSum, Set3)
{
    std::vector<int> set {4, 5, 6, 1};
    ASSERT_EQ(subsetsWithSum(set, 30), 0);
}


TEST(TestSubsetWithSum, set4)
{
    std::vector<int> set {0, 0, 1};
    ASSERT_EQ(subsetsWithSum(set, 1), 4);
}


TEST(TestMinimumSubsetSumDifference, EmptySet)
{
    std::vector<int> set;
    ASSERT_EQ(minSubsetSumDiff(set), 0);
}


TEST(TestMinimumSubsetSumDifference, Test1)
{
    std::vector<int> set {1, 6, 11, 5};
    ASSERT_EQ(minSubsetSumDiff(set), 1);
}
