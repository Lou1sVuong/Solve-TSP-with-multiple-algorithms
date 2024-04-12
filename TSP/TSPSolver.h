#include "ACO.h"
#include "Genetic.h"
#include  "GreedySolver.h"
#include "BruteForceSolver.h"
#include "BacktrackingSolver.h"
#include "BranchAndBoundSolver.h"
class TSPSolver
{
public:
    void solveWithACO(const DistanceMatrix& matrix);
    void solveWithGA(const DistanceMatrix &matrix);
    void solveWithGreedy(const DistanceMatrix& matrix);
    void solveWithBF(const DistanceMatrix& matrix);
    void solveWithBT(const DistanceMatrix& matrix);
    void solveWithBAB(const DistanceMatrix& matrix);
};