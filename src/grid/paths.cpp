//
// Created by daniel on 19/04/23.
//

#include "paths.h"


int numUniquePaths(int n, int m)
{
    // Calculates the number of unique paths in an (n x m) grid where
    // only movement to the right and down is allowed

    // We use a top-down approach
    // The number of unique paths in the first row and in the first
    // column is one. So we initialize the table with ones
    if (n <= 0 || m <= 0)
        return 0;

    matrix results (n, std::vector<int>(m, 1));

    for (auto ii {1}; ii < results.size(); ++ii){
        for (auto jj {1}; jj < results[ii].size(); ++jj){
            results[ii][jj] = results[ii - 1][jj] + results[ii][jj - 1];
        }
    }

    return results[n - 1][m - 1];
}
