//
// Created by daniel on 19/04/23.
//

#ifndef DYNAMICPROGRAMMING_PATHS_H
#define DYNAMICPROGRAMMING_PATHS_H

#include <vector>

using matrix = std::vector<std::vector<int>>;

int numUniquePaths(int n, int m);

int numUniquePaths(const matrix& grid);

#endif //DYNAMICPROGRAMMING_PATHS_H
