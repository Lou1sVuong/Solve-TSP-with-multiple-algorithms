#ifndef GENETIC_H
#define GENETIC_H

#include <vector>
#include <algorithm>
#include <numeric>
#include "DistanceMatrix.h"  // Giả sử đã có class này được định nghĩa
using namespace std;
class GeneticAlgorithm {
public:
    GeneticAlgorithm(const DistanceMatrix& matrix, int populationSize, int generations, double mutationRate);
    void solve();

private:
    DistanceMatrix matrix;
    int populationSize;
    int generations;
    double mutationRate;
    vector<vector<int>> population;

    void initializePopulation();
    vector<int> createRandomChromosome();
    double calculateFitness(const vector<int>& chromosome);
    void selection();
    void crossover();
    void mutate(vector<int>& chromosome);
    vector<int> selectParent();
};

#endif
