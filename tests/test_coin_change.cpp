//
// Created by daniel on 13/04/23.
//

#include "gtest/gtest.h"
#include "coin_change.h"


TEST(TestMinimumNumberOfCoins, EmptyCoins)
{
    std::vector<int> coins;
    ASSERT_EQ(minCoins(coins, 5), -1);
}

TEST(TestMinimumNumberOfCoins, CannotMakeAmount)
{
    std::vector<int> coins {2, 4};
    ASSERT_EQ(minCoins(coins, 5), -1);
}


TEST(TestMinimumNumberOfCoins, Test1)
{
    std::vector<int> coins {1, 2, 5};
    ASSERT_EQ(minCoins(coins, 6), 2);
}


TEST(TestMinimumNumberOfCoins, Test2)
{
    std::vector<int> coins {1, 2, 5};
    ASSERT_EQ(minCoins(coins, 11), 3);
}


TEST(TestNumberofCoinsCombinations, NoCoins)
{
    std::vector<int> coins;
    ASSERT_EQ(numCoinCombinations(coins, 5), 0);
}


TEST(TestNumberofCoinsCombinations, CannotMakeAmount)
{
    std::vector<int> coins {2, 4};
    ASSERT_EQ(numCoinCombinations(coins, 5), 0);
}


TEST(TestNumberofCoinsCombinations, Test1)
{
    std::vector<int> coins {1, 2, 5};
    ASSERT_EQ(numCoinCombinations(coins, 5), 4);
}
