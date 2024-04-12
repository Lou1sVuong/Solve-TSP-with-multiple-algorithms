#include "GreedySolver.h"
#include <iostream>
#include <vector>
#include <limits>

using namespace std;

GreedySolver::GreedySolver(const DistanceMatrix& matrix) : matrix(matrix) {}

void GreedySolver::solve() {
    int n = matrix.size();
    vector<bool> visited(n, false);
    int currentCity = 0;
    visited[currentCity] = true;
    vector<int> path = { currentCity };

    double totalDistance = 0.0;

    for (int i = 1; i < n; ++i) {
        int nextCity = -1;
        double minDistance = numeric_limits<double>::max();

        for (int j = 0; j < n; ++j) {
            if (!visited[j] && matrix.getDistance(currentCity, j) < minDistance) {
                minDistance = matrix.getDistance(currentCity, j);
                nextCity = j;
            }
        }

        visited[nextCity] = true;
        path.push_back(nextCity);
        totalDistance += minDistance;
        currentCity = nextCity;
    }

    // Return to the start city
    totalDistance += matrix.getDistance(currentCity, 0);
    path.push_back(0);

    cout << "Greedy Algorithm: " << endl;
    cout << "Greedy Path: ";
    for (int i = 0; i < path.size() - 1; i++) {
        cout << path[i] << " -> ";
    }
    cout << path.back() << endl;  // Ensuring it ends with the start city for clarity

    cout << "Total Distance: " << totalDistance << endl;
}
