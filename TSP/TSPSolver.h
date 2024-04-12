#include "ACO.h"
#include "Genetic.h"

class TSPSolver
{
public:
    void solveWithACO(const DistanceMatrix& matrix);
    void solveWithGA(const DistanceMatrix &matrix);
};