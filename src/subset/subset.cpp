//
// Created by daniel on 18/03/23.
//

#include "subset.h"


bool subsetSum(int currentSum, int element, const std::vector<int>& set)
{
    // Recursive procedure for subset sum.
    // Time complexity O(2^n)
    if (currentSum == 0)
        return true;
    if (currentSum < 0 || element < 0)
        return false;

    if (set[element] > currentSum)
        return subsetSum(currentSum, element - 1, set);

    return subsetSum(currentSum, element - 1, set) ||
            subsetSum(currentSum - set[element], element - 1, set);
}


bool subsetSum(int targetSum, const std::vector<int>& set)
{
    // Returns true if there exists a subset of the given set, whose elements sum is equal
    // to the given sum value
    // Time complexity O(targetSum * set.size())

    if (set.empty())
        return true;

    table results(set.size() + 1, std::vector<bool>(targetSum + 1, false));

    // For a sum of zero, we can always found a subset (null subset or {0})
    for (auto element {0}; element < results.size(); ++element)
        results[element][0] = true;

    for (auto element {1}; element < results.size(); ++element)
    {
        for (auto sum {1}; sum < results[element].size(); ++sum)
        {
            // Exclude current element
            if (set[element - 1] > sum)
                results[element][sum] = results[element - 1][sum];
            else
                results[element][sum] =
                        results[element - 1][sum] || // Exclude
                        results[element - 1][sum - set[element - 1]]; // Include
        }
    }

    return results[results.size() - 1][targetSum];
}
