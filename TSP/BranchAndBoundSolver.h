#ifndef BRANCH_AND_BOUND_SOLVER_H
#define BRANCH_AND_BOUND_SOLVER_H

#include "DistanceMatrix.h"
#include <vector>
#include <queue>

class BranchAndBoundSolver {
public:
    BranchAndBoundSolver(const DistanceMatrix& matrix);
    void solve();

private:
    const DistanceMatrix& matrix;
    int N;
    double bestCost;

    struct Node {
        std::vector<int> path;
        double bound;
        double cost;
        int lastVisited;

        // For priority queue to work in min order based on bound
        bool operator>(const Node& other) const {
            return this->bound > other.bound;
        }
    };

    double calculateBound(Node& node);
};

#endif // BRANCH_AND_BOUND_SOLVER_H
