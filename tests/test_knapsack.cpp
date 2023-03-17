//
// Created by daniel on 17/03/23.
//

#include "gtest/gtest.h"
#include "knapsack.h"


TEST(TestO1Knapsack, ComputesMaxProfitCorrectly)
{
    std::vector<int> weights {3, 2, 4};
    std::vector<int> profits {6, 8, 7};
    int capacity {8};
    ASSERT_EQ(knapsack(capacity, weights, profits), 15);
}

