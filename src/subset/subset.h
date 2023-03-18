//
// Created by daniel on 18/03/23.
//

#ifndef DYNAMICPROGRAMMING_SUBSET_H
#define DYNAMICPROGRAMMING_SUBSET_H

#include <vector>

using table = std::vector<std::vector<bool>>;

bool subsetSum(int targetSum, const std::vector<int>& set);

#endif //DYNAMICPROGRAMMING_SUBSET_H
