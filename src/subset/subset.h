//
// Created by daniel on 18/03/23.
//

#ifndef DYNAMICPROGRAMMING_SUBSET_H
#define DYNAMICPROGRAMMING_SUBSET_H

#include <cmath>
#include <vector>

using table = std::vector<std::vector<bool>>;

bool subsetSum(int targetSum, const std::vector<int>& set);

int subsetsWithSum(const std::vector<int>& set, int targetSum);

#endif //DYNAMICPROGRAMMING_SUBSET_H
