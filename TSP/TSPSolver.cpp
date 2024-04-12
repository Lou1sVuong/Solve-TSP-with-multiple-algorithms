#include "TSPSolver.h"

void TSPSolver::solveWithACO(const DistanceMatrix& matrix)
{
    int numAntsValue = 100;               // Giả sử giá trị của numAntsValue là 10
    int maxIterationsValue = 500;        // Giả sử giá trị của maxIterationsValue là 100
    double alphaValue = 0.5;             // Giả sử giá trị của alphaValue là 0.5
    double betaValue = 1.0;              // Giả sử giá trị của betaValue là 1.0
    double evaporationRateValue = 0.1;   // Giả sử giá trị của evaporationRateValue là 0.1
    double initialPheromoneValue = 0.01; // Giả sử giá trị của initialPheromoneValue là 0.01

    ACO aco(matrix, numAntsValue, maxIterationsValue, alphaValue, betaValue, evaporationRateValue, initialPheromoneValue);
    aco.solve();
}

void TSPSolver::solveWithGA(const DistanceMatrix& matrix)
{
    int populationSize = 3000; // Số lượng cá thể trong quần thể
    int generations = 500;   // Số thế hệ
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
