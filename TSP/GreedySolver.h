#ifndef GREEDY_SOLVER_H
#define GREEDY_SOLVER_H

#include "DistanceMatrix.h"

class GreedySolver {
public:
    GreedySolver(const DistanceMatrix& matrix);
    void solve();

private:
    const DistanceMatrix& matrix;
};

#endif // GREEDY_SOLVER_H
