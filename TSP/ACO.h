
#ifndef ACO_H
#define ACO_H

#include "DistanceMatrix.h"
#include <vector>

class ACO
{
public:
    ACO(const DistanceMatrix& matrix, int numAnts, int maxIterations, double alpha, double beta, double evaporationRate, double initialPheromone);
    void solve();

private:
    const DistanceMatrix& matrix;
    int numAnts;
    int maxIterations;
    double alpha;
    double beta;
    double evaporationRate;
    double initialPheromone;
    vector<vector<double>> pheromones;

    void initializePheromones();
    int selectNextCity(int ant, const vector<bool>& visited, int currentCity, const vector<vector<int>>& paths);
    double calculateProbability(int ant, int city, const vector<bool>& visited, const vector<vector<int>>& paths);
    double calculatePathLength(const vector<int>& path);
    void updatePheromones(const vector<vector<int>>& paths);
};

#endif // ACO_H