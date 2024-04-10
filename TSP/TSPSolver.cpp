#include "TSPSolver.h"

void TSPSolver::solveWithACO(const DistanceMatrix& matrix)
{
    int numAntsValue = 10;               // Giả sử giá trị của numAntsValue là 10
    int maxIterationsValue = 100;        // Giả sử giá trị của maxIterationsValue là 100
    double alphaValue = 0.5;             // Giả sử giá trị của alphaValue là 0.5
    double betaValue = 1.0;              // Giả sử giá trị của betaValue là 1.0
    double evaporationRateValue = 0.1;   // Giả sử giá trị của evaporationRateValue là 0.1
    double initialPheromoneValue = 0.01; // Giả sử giá trị của initialPheromoneValue là 0.01

    ACO aco(matrix, numAntsValue, maxIterationsValue, alphaValue, betaValue, evaporationRateValue, initialPheromoneValue);
    aco.solve();
}

// void TSPSolver::solveWithGA(const DistanceMatrix &matrix)
// {
//     GeneticAlgorithm ga(matrix);
//     ga.solve();
// }