#ifndef BRUTE_FORCE_SOLVER_H
#define BRUTE_FORCE_SOLVER_H

#include "DistanceMatrix.h"
#include <vector>

class BruteForceSolver {
public:
    BruteForceSolver(const DistanceMatrix& matrix);
    void solve();

private:
    const DistanceMatrix& matrix;
};

#endif // BRUTE_FORCE_SOLVER_H
