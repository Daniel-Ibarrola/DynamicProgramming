//
// Created by daniel on 13/04/23.
//

#include "coin_change.h"


const int INF {std::numeric_limits<int>::max()};


int minCoins(const std::vector<int>& coins, int targetAmount)
{
    //! \brief Returns the minimum amount of coins needed to form the given amount
    /// or -1 if it's not possible
    /*!
     * \param coins  A vector with the coin denominations
     * \param targetAmount The needed amount
     *
     * \return The minimum number of coins
     */
     matrix results(coins.size() + 1, std::vector<int>(targetAmount + 1, 0));

     // When we have no coins we cannot form any amount > 0
     for (auto ii {1}; ii < results[0].size(); ++ii)
         results[0][ii] = INF;

     for (auto coin {1}; coin < results.size(); ++coin)
     {
         for (auto amount {1}; amount < results[coin].size(); ++amount)
         {
             if (amount < coins[coin - 1])
                 results[coin][amount] = results[coin - 1][amount];
             else
             {
                 int exclude {results[coin - 1][amount]};
                 int include {results[coin][amount - coins[coin - 1]]};
                 if (include != INF)
                    include++;
                 results[coin][amount] = std::min(exclude, include);
             }
         }
     }

    return results[results.size() - 1][targetAmount]  == INF
            ? -1 : results[results.size() - 1][targetAmount];
}


int numCoinCombinations(const std::vector<int>& coins, int targetAmount)
{
    //! \brief Returns all the possible combinations of coins needed to form the given amount
    /*!
     * \param coins  A vector with the coin denominations
     * \param targetAmount The needed amount
     *
     * \return The minimum number of coins
     */
    matrix results(coins.size() + 1, std::vector<int>(targetAmount + 1, 0));

    // Base case 1: When we have no coins we cannot form any amount > 0
    //  results[0][ii] = 0
    // Base case 2: When we have an amount of zero we can always take an empty
    // subset
    for (auto ii {0}; ii < results.size(); ++ii)
        results[ii][0] = 1;

    for (auto coin {1}; coin < results.size(); ++coin)
    {
        for (auto amount {1}; amount < results[coin].size(); ++amount)
        {
            if (amount < coins[coin - 1])
                results[coin][amount] = results[coin - 1][amount];
            else
            {
                int exclude {results[coin - 1][amount]};
                int include {results[coin][amount - coins[coin - 1]]};
                results[coin][amount] = include + exclude;
            }
        }
    }

    return results[results.size() - 1][targetAmount];
}