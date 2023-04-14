//
// Created by daniel on 13/04/23.
//

#ifndef DYNAMICPROGRAMMING_COIN_CHANGE_H
#define DYNAMICPROGRAMMING_COIN_CHANGE_H


#include <cmath>
#include <limits>
#include <vector>

using matrix = std::vector<std::vector<int>>;

int minCoins(const std::vector<int>& coins, int targetAmount);

int numCoinCombinations(const std::vector<int>& coins, int targetAmount);

#endif //DYNAMICPROGRAMMING_COIN_CHANGE_H
