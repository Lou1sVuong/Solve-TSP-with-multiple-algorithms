#include "BranchAndBoundSolver.h"
#include <iostream>
#include <limits>
#include <queue>

using namespace std;

BranchAndBoundSolver::BranchAndBoundSolver(const DistanceMatrix& matrix)
    : matrix(matrix), N(matrix.size()), bestCost(numeric_limits<double>::max()) {}

void BranchAndBoundSolver::solve() {
    priority_queue<Node, vector<Node>, greater<Node>> pq;

    // Start with first city
    Node start;
    start.path.push_back(0);
    start.lastVisited = 0;
    start.cost = 0;
    start.bound = calculateBound(start);
    pq.push(start);

    while (!pq.empty()) {
        Node top = pq.top();
        pq.pop();

        if (top.bound < bestCost) {
            // Explore neighbors
            for (int i = 0; i < N; i++) {
                if (find(top.path.begin(), top.path.end(), i) == top.path.end()) {
                    Node child = top;
                    child.path.push_back(i);
                    child.cost += matrix.getDistance(child.lastVisited, i);
                    child.lastVisited = i;

                    if (child.path.size() == N) {
                        // Completing the path by returning to the start
                        child.cost += matrix.getDistance(i, 0);
                        if (child.cost < bestCost) {
                            bestCost = child.cost;
                        }
                    }
                    else {
                        child.bound = calculateBound(child);
                        if (child.bound < bestCost) {
                            pq.push(child);
                        }
                    }
                }
            }
        }
    }

    cout << "Minimum Cost: " << bestCost << endl;
}

double BranchAndBoundSolver::calculateBound(Node& node) {
    double bound = node.cost;
    // Implement the logic to calculate the lower bound based on the remaining cities to be visited
    // This is a simple heuristic which could be the minimal cost to any unvisited city
    for (int i = 0; i < N; i++) {
        if (find(node.path.begin(), node.path.end(), i) == node.path.end()) {
            double minCost = numeric_limits<double>::max();
            for (int j = 0; j < N; j++) {
                if (i != j && find(node.path.begin(), node.path.end(), j) == node.path.end()) {
                    minCost = min(minCost, matrix.getDistance(i, j));
                }
            }
            bound += minCost;
        }
    }
    return bound;
}
