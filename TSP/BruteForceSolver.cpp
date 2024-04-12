#include "BruteForceSolver.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

BruteForceSolver::BruteForceSolver(const DistanceMatrix& matrix) : matrix(matrix) {}

void BruteForceSolver::solve() {
    int n = matrix.size();
    vector<int> cities(n);
    for (int i = 0; i < n; ++i) {
        cities[i] = i;
    }

    double minDistance = numeric_limits<double>::max();
    vector<int> bestPath;

    do {
        double currentDistance = 0;
        for (int i = 0; i < n - 1; ++i) {
            currentDistance += matrix.getDistance(cities[i], cities[i + 1]);
        }
        currentDistance += matrix.getDistance(cities.back(), cities.front()); // Complete the tour by returning to the start

        if (currentDistance < minDistance) {
            minDistance = currentDistance;
            bestPath = cities;
        }
    } while (next_permutation(cities.begin(), cities.end()));

    cout << "Brute Force TSP Solver: " << endl;
    cout << "Shortest Path: ";
    for (int city : bestPath) {
        cout << city << " -> ";
    }
    cout << bestPath.front() << endl; // End the path output by returning to the start city
    cout << "Minimum Distance: " << minDistance << endl;
}
