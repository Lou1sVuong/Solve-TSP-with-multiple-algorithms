#include "BacktrackingSolver.h"
#include <iostream>
#include <limits>
#include <vector>

using namespace std;

BacktrackingSolver::BacktrackingSolver(const DistanceMatrix& matrix)
    : matrix(matrix), N(matrix.size()), bestCost(numeric_limits<double>::max()), currentCost(0) {
    visited.resize(N, false);
    currentPath.push_back(0);  // Start from the first city
    visited[0] = true;
}

void BacktrackingSolver::solve() {
    backtrack(1);  // Start backtracking from the second city
    cout << "Optimal Path: ";
    for (int city : bestPath) {
        cout << city << " -> ";
    }
    cout << bestPath.front() << endl;  // Completing the cycle by returning to the start
    cout << "Minimum Distance: " << bestCost << endl;
}

void BacktrackingSolver::backtrack(int level) {
    if (level == N) {
        // Calculate returning cost
        double returnCost = matrix.getDistance(currentPath.back(), currentPath.front());
        double totalCost = currentCost + returnCost;
        if (totalCost < bestCost) {
            bestCost = totalCost;
            bestPath = currentPath;
        }
        return;
    }

    for (int nextCity = 1; nextCity < N; ++nextCity) {
        if (!visited[nextCity]) {
            visited[nextCity] = true;
            currentPath.push_back(nextCity);
            currentCost += matrix.getDistance(currentPath[currentPath.size() - 2], nextCity);

            backtrack(level + 1);

            // Undo move
            currentCost -= matrix.getDistance(currentPath[currentPath.size() - 2], nextCity);
            currentPath.pop_back();
            visited[nextCity] = false;
        }
    }
}
