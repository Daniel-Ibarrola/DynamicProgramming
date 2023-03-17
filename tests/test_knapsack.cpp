//
// Created by daniel on 17/03/23.
//

#include "gtest/gtest.h"
#include "knapsack.h"


TEST(TestO1KnapsackRecursion, ComputesMaxProfitCorrectly)
{
    std::vector<Item> items {
            {3, 6}, {2, 8}, {4, 7}
    };
    Knapsack knapsack(8, items);
    ASSERT_EQ(knapsack.maxProfit("rec"), 15);
}

TEST(TestO1KnapsackMemoization, ComputesMaxProfitCorrectly)
{
    std::vector<Item> items {
            {3, 6}, {2, 8}, {4, 7}
    };
    Knapsack knapsack(8, items);
    ASSERT_EQ(knapsack.maxProfit("mem"), 15);
}

TEST(TestO1KnapsackDynamicProgramming, ComputesMaxProfitCorrectly)
{
    std::vector<Item> items {
            {3, 6}, {2, 8}, {4, 7}
    };
    Knapsack knapsack(8, items);
    ASSERT_EQ(knapsack.maxProfit("dp"), 15);
}
