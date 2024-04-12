#include "ACO.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

ACO::ACO(const DistanceMatrix& matrix, int numAnts, int maxIterations, double alpha, double beta, double evaporationRate, double initialPheromone)
    : matrix(matrix), numAnts(numAnts), maxIterations(maxIterations), alpha(alpha), beta(beta), evaporationRate(evaporationRate), initialPheromone(initialPheromone) {}

void ACO::solve()
{
    srand(time(nullptr));
    initializePheromones();

    double bestLength = numeric_limits<double>::max();
    vector<int> bestPath;

    for (int iteration = 0; iteration < maxIterations; ++iteration)
    {
        vector<vector<int>> paths(numAnts, vector<int>());
        vector<double> lengths(numAnts, 0.0);

        for (int ant = 0; ant < numAnts; ++ant)
        {
            vector<bool> visited(matrix.size(), false);
            int currentCity = 0;  // Start from the first city for every ant
            paths[ant].push_back(currentCity);
            visited[currentCity] = true;

            for (int i = 1; i < matrix.size(); ++i)
            {
                int nextCity = selectNextCity(ant, visited, currentCity, paths);
                paths[ant].push_back(nextCity);
                visited[nextCity] = true;
                currentCity = nextCity;
            }

            // Ensure the ant returns to the starting city to complete the tour
            paths[ant].push_back(0);

            lengths[ant] = calculatePathLength(paths[ant]);
            if (lengths[ant] < bestLength)
            {
                bestLength = lengths[ant];
                bestPath = paths[ant];
            }
        }

        updatePheromones(paths);

        cout << "Lan lap " << iteration + 1 << ", do dai duong di ngan nhat la : " << bestLength << endl;
    }

    // Display the best path found
    cout << bestPath[0];
    for (int i = 1; i < bestPath.size(); ++i) {
        cout << " -> " << bestPath[i];
    }
    cout << endl;
}


void ACO::initializePheromones()
{
    pheromones.resize(matrix.size(), vector<double>(matrix.size(), initialPheromone));
}

int ACO::selectNextCity(int ant, const vector<bool>& visited, int currentCity, const vector<vector<int>>& paths)
{
    double totalProbability = 0.0;
    vector<double> probabilities(matrix.size(), 0.0);

    for (int city = 0; city < matrix.size(); ++city)
    {
        if (!visited[city])
        {
            probabilities[city] = calculateProbability(ant, city, visited, paths);
            totalProbability += probabilities[city];
        }
    }

    double randomValue = ((double)rand() / RAND_MAX) * totalProbability;
    double cumulativeProbability = 0.0;

    for (int city = 0; city < matrix.size(); ++city)
    {
        if (!visited[city])
        {
            cumulativeProbability += probabilities[city];
            if (cumulativeProbability >= randomValue)
            {
                return city;
            }
        }
    }

    return -1;
}

double ACO::calculateProbability(int ant, int city, const vector<bool>& visited, const vector<vector<int>>& paths)
{
    double pheromone = pheromones[paths[ant].back()][city];
    double visibility = 1.0 / matrix.getDistance(paths[ant].back(), city);
    return pow(pheromone, alpha) * pow(visibility, beta);
}

double ACO::calculatePathLength(const vector<int>& path)
{
    double length = 0.0;
    for (int i = 0; i < path.size(); ++i) {
        int from = path[i];
        int to = (i == path.size() - 1) ? path[0] : path[i + 1]; // Consider starting city when i reaches the end
        length += matrix.getDistance(from, to);
    }
    return length;
}

void ACO::updatePheromones(const vector<vector<int>>& paths)
{
    for (int i = 0; i < matrix.size(); ++i)
    {
        for (int j = 0; j < matrix.size(); ++j)
        {
            pheromones[i][j] *= (1.0 - evaporationRate);
        }
    }

    for (int ant = 0; ant < numAnts; ++ant)
    {
        double pathLength = calculatePathLength(paths[ant]);
        for (int i = 0; i < paths[ant].size() - 1; ++i)
        {
            int from = paths[ant][i];
            int to = paths[ant][i + 1];
            pheromones[from][to] += 1.0 / pathLength;
            pheromones[to][from] += 1.0 / pathLength;
        }
    }
}