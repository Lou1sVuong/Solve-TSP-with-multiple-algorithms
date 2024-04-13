#include "TSPSolver.h"

void TSPSolver::solveWithACO(const DistanceMatrix& matrix)
{
    int numAntsValue = 100;               
    int maxIterationsValue = 200;     
    double alphaValue = 0.5;           
    double betaValue = 1.0;             
    double evaporationRateValue = 0.1;  
    double initialPheromoneValue = 0.01; 

    ACO aco(matrix, numAntsValue, maxIterationsValue, alphaValue, betaValue, evaporationRateValue, initialPheromoneValue);
    aco.solve();
}

void TSPSolver::solveWithGA(const DistanceMatrix& matrix)
{
    int populationSize = 3000; // Số lượng cá thể trong quần thể
    int generations = 200;   // Số thế hệ
    double mutationRate = 0.05; // Tỷ lệ đột biến
    GeneticAlgorithm ga(matrix, populationSize, generations, mutationRate);
    ga.solve();
}

void TSPSolver::solveWithGreedy(const DistanceMatrix& matrix) {
    GreedySolver Greedy(matrix);
    Greedy.solve();
};

void TSPSolver::solveWithBF(const DistanceMatrix& matrix) {
    BruteForceSolver BruteForce(matrix);
    BruteForce.solve();
}

void TSPSolver::solveWithBT(const DistanceMatrix& matrix) {
    BacktrackingSolver BacktrackingSolver(matrix);
    BacktrackingSolver.solve();
};

void TSPSolver::solveWithBAB(const DistanceMatrix& matrix) {
    BranchAndBoundSolver BranchAndBoundSolver(matrix);
    BranchAndBoundSolver.solve();
};
