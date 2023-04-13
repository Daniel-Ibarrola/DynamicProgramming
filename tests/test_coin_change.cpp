//
// Created by daniel on 13/04/23.
//

#include "gtest/gtest.h"
#include "coin_change.h"


TEST(TestCoinChange, EmptyCoins)
{
    std::vector<int> coins;
    ASSERT_EQ(coinChange(coins, 5), -1);
}

TEST(TestCoinChange, CannotMakeAmount)
{
    std::vector<int> coins {2, 4};
    ASSERT_EQ(coinChange(coins, 5), -1);
}


TEST(TestCoinChange, Test1)
{
    std::vector<int> coins {1, 2, 5};
    ASSERT_EQ(coinChange(coins, 6), 2);
}


TEST(TestCoinChange, Test2)
{
    std::vector<int> coins {1, 2, 5};
    ASSERT_EQ(coinChange(coins, 11), 3);
}
