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


table subsetSumTable(int targetSum, const std::vector<int>& set)
{
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
    return results;
}


bool subsetSum(int targetSum, const std::vector<int>& set)
{
    // Returns true if there exists a subset of the given set, whose elements sum is equal
    // to the given sum value
    // Time complexity O(targetSum * set.size())
    if (set.empty())
        return true;
    table results {subsetSumTable(targetSum, set)};
    return results[results.size() - 1][targetSum];
}


int subsetsWithSum(const std::vector<int>& set, int targetSum)
{
    // Counts the number of subsets whose element sum is equal to the target sum
    std::vector<std::vector<int>> results(set.size() + 1, std::vector<int>(targetSum + 1, 0));
    // For a sum of zero, we can always found a subset (null subset or {0})
    for (auto element {0}; element < results.size(); ++element)
        results[element][0] = 1;

    int numOfZeros {0};
    for (auto element {1}; element < results.size(); ++element)
        for (auto sum {1}; sum < results[element].size(); ++sum)
        {
            if (set[element - 1] == 0)
                ++numOfZeros;
            if (set[element - 1] > sum)
                results[element][sum] = results[element - 1][sum];
            else
                results[element][sum] =
                        results[element - 1][sum] + results[element - 1][sum - set[element - 1]];

        }

    return static_cast<int>(std::pow(2, numOfZeros)) * results[results.size() - 1][targetSum];
}


int minSubsetSumDiff(const std::vector<int>& set)
{
    //! \brief Given a set it returns the minimum difference after
    /// partitioning such set into two subsets and computing the difference of the sum of their elements
    //! \param set a vector with numbers
    int targetSum {std::reduce(set.begin(), set.end())};
    table results {subsetSumTable(targetSum / 2, set)};
    std::size_t lastRow {results.size() - 1};

    int minDiff {std::numeric_limits<int>::max()};
    for (auto ii {0}; ii < results[lastRow].size(); ++ii)
    {
        if (results[lastRow][ii])
            minDiff = std::min(minDiff, targetSum - 2 * ii);
    }
    return minDiff;
}
