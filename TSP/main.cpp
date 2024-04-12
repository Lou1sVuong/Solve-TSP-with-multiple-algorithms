#include "TSPSolver.h"
#include "FileManager.h"
#include "DistanceMatrix.h"
#include <iostream>
#include <limits>

using namespace std;

int main() {
    DistanceMatrix matrix = FileManager::readMatrixFromFile("data.txt");
    TSPSolver solver;

    int choice;
    char runAgain;

    do {
        cout << "Available Algorithms:" << endl;
        cout << "1. ACO algorithm" << endl;
        cout << "2. Genetic algorithm" << endl;
        cout << "3. Greedy algorithm" << endl;
        cout << "4. Brute Force algorithm" << endl;
        cout << "5. Backtracking algorithm" << endl;
        cout << "6. Exit" << endl;

        cout << "Which algorithm do you want to use? Enter a number (1-6): ";
        cin >> choice;

        while (cin.fail() || choice < 1 || choice > 6) {
            cin.clear(); // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore wrong input until next newline
            cout << "Your choice is not valid, please choose again (1-6): ";
            cin >> choice;
        }

        switch (choice) {
        case 1:
            solver.solveWithACO(matrix);
            break;
        case 2:
            solver.solveWithGA(matrix);
            break;
        case 3:
            solver.solveWithGreedy(matrix);
            break;
        case 4:
            // Assuming solveWithBF is your brute force method
            solver.solveWithBF(matrix);
            break;
        case 5:
            // Assuming solveWithBT is your backtracking method
            solver.solveWithBT(matrix);
            break;
        case 6:
            cout << "Exiting the program." << endl;
            return 0;
        }

        // Ask if the user wants to run another algorithm
        cout << "Do you want to run another algorithm? (Y/N): ";
        cin >> runAgain;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer

    } while (runAgain == 'Y' || runAgain == 'y');

    return 0;
}
