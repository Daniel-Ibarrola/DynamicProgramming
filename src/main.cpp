//
// Created by daniel on 17/03/23.
//

#include <string>
#include <iostream>
#include "knapsack.h"


void print(const std::vector<int>& vec, const std::string& name)
{
    std::cout << name + ": ";
    for (auto element : vec)
        std::cout << element << ' ';
    std::cout << '\n';
}


int main()
{
    std::vector<int> weights {3, 2, 4};
    std::vector<int> profits {6, 8, 7};
    int capacity {8};
    int maxProfit {knapsack(capacity, weights, profits)};

    std::cout << "Knapsack with capacity of " << capacity << '\n';
    print(weights, "Weights");
    print(profits, "Profits");
    std::cout << "Max profit is " << maxProfit;

    return 0;
}
