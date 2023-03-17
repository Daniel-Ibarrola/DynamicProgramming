//
// Created by daniel on 17/03/23.
//

#include "knapsack.h"


int knapsack(int currentWeight,
             int item,
             const std::vector<int>& weights,
             const std::vector<int>& profits)
{
    // Base cases: no space left in knapsack or we run out of items
    if (currentWeight == 0 || item == -1)
        return 0;

    // Not sufficient space, skip current item
    if (weights[item] > currentWeight)
        return knapsack(currentWeight, item - 1, weights, profits);

    // Max of including or excluding current item
    return std::max(
            // Include
            knapsack(currentWeight, item - 1, weights, profits),
            // Exclude
            knapsack(currentWeight - weights[item], item - 1, weights, profits) + profits[item]
            );
}

int knapsack(int capacity, const std::vector<int>& weights, const std::vector<int>& profits)
{
    // Computes the max profit of a 0-1 knapsack
    assert(weights.size() == profits.size());
    return knapsack(capacity,
                    static_cast<int>(weights.size() - 1),
                    weights,
                    profits);
}
