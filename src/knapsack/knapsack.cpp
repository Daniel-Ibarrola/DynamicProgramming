//
// Created by daniel on 17/03/23.
//

#include "knapsack.h"


int Knapsack::maxProfitRec(int currentWeight, int item)
{
    // Compute the max profit of the knapsack using recursion.
    // Time complexity: O(2^n)

    // Base cases: no space left in knapsack or we run out of items
    if (currentWeight == 0 || item == -1)
        return 0;

    // Not sufficient space, skip current item
    if (m_items[item].weight > currentWeight)
        return maxProfitRec(currentWeight, item - 1);

    // Max of including or excluding current item
    return std::max(
            // Include
            maxProfitRec(currentWeight, item - 1),
            // Exclude
            maxProfitRec(currentWeight - m_items[item].weight, item - 1) + m_items[item].profit
            );
}

int Knapsack::maxProfitMem(int currentWeight, int item, std::vector<std::vector<int>>& profits)
{
    // Compute the max profit of the knapsack using recursion with memoization
    // Time complexity O(weight * items)

    // Base cases: no space left in knapsack or we run out of items
    if (currentWeight == 0 || item == -1)
        return 0;

    // Look up if the value has been computed
    if (profits[item][currentWeight - 1] != -1)
        return profits[item][currentWeight - 1];

    // Not sufficient space, skip current item
    int result;
    if (m_items[item].weight > currentWeight)
        result = maxProfitMem(currentWeight, item - 1, profits);
    else
    {
        // Max of including or excluding current item
        result = std::max(
                // Include
                maxProfitMem(currentWeight, item - 1, profits),
                // Exclude
                maxProfitMem(currentWeight - m_items[item].weight, item - 1, profits)
                    + m_items[item].profit
        );
    }
    profits[item][currentWeight - 1] = result;
    return result;

}

int Knapsack::maxProfit(const std::string &method)
{
    // Returns the max profit of the knapsack
    if (method == "rec")
        return maxProfitRec(m_capacity, static_cast<int>(m_items.size() - 1));
    else if (method == "mem")
    {
        std::vector<std::vector<int>> profits(m_items.size(), std::vector<int>(m_capacity, -1));
        return maxProfitMem(m_capacity, static_cast<int>(m_items.size() - 1), profits);
    }
    else
        throw InvalidMethodError();
}

