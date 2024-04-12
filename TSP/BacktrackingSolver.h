#ifndef BACKTRACKING_SOLVER_H
#define BACKTRACKING_SOLVER_H

#include "DistanceMatrix.h"
#include <vector>

class BacktrackingSolver {
public:
    BacktrackingSolver(const DistanceMatrix& matrix);
    void solve();

private:
    const DistanceMatrix& matrix;
    std::vector<int> bestPath;
    double bestCost;
    std::vector<int> currentPath;
    double currentCost;
    std::vector<bool> visited;
    int N;

    void backtrack(int level);
};

#endif // BACKTRACKING_SOLVER_H
