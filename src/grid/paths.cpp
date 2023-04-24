//
// Created by daniel on 19/04/23.
//

#include "paths.h"


int numUniquePaths(int n, int m)
{
    /// \brief Calculates the number of unique paths in an (n x m) grid where
    /// only movement to the right and down is allowed

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


int numUniquePaths(const matrix& grid)
{
    /*! \brief Calculates the number of unique paths in an (n x m) grid where
     only movement to the right and down is allowed. Obstacles are allowed

     \param grid  A grid of n x m where a value of 1 represents an obstacle and
                  a value of 0 empty space
    */
    if (grid.empty())
        return 0;

    matrix results (grid.size(), std::vector<int>(grid[0].size()));

    // Fill the first column and rows with ones, except if there is an obstacle, in which case
    // they won't be able to be traversed
    bool rowObstacle {false};
    for (auto ii {0}; ii < results.size(); ++ii)
    {
        if (grid[ii][0] == 1)
            rowObstacle = true;
        if (rowObstacle)
            results[ii][0] = 0;
        else{
            results[ii][0] = 1;
        }
    }

    bool colObstacle {false};
    for (auto jj {0}; jj < results[0].size(); ++jj)
    {
        if (grid[0][jj] == 1)
            colObstacle = true;
        if (colObstacle)
            results[0][jj] = 0;
        else{
            results[0][jj] = 1;
        }
    }

    // If the first column and row are obstructed we cannot reach the end
    if (rowObstacle && colObstacle)
        return 0;

    for (auto ii {1}; ii < results.size(); ++ii){
        for (auto jj {1}; jj < results[ii].size(); ++jj){
            if (grid[ii][jj] == 1)
                results[ii][jj] = 0;
            else
                results[ii][jj] = results[ii - 1][jj] + results[ii][jj - 1];
        }
    }

    return results[results.size() - 1][results[0].size() - 1];
}
