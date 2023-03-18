//
// Created by daniel on 18/03/23.
//

#include "subset.h"


bool subsetSum(int currentSum, int element, const std::vector<int>& set)
{
    if (currentSum == 0)
        return true;
    if (currentSum < 0 || element < 0)
        return false;

    if (set[element] > currentSum)
        return subsetSum(currentSum, element - 1, set);

    return subsetSum(currentSum, element - 1, set) ||
            subsetSum(currentSum - set[element], element - 1, set);
}


bool subsetSum(int sum, const std::vector<int>& set)
{
    // Returns true if there exists a subset of the given set, whose elements sum is equal
    // to the given sum value
    return subsetSum(sum, static_cast<int>(set.size() - 1), set);
}
