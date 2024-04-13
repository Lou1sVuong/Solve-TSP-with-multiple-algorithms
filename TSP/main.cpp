#include "TSPSolver.h"
#include "FileManager.h"
#include "DistanceMatrix.h"
#include <iostream>
#include <limits>
#include <chrono> // For timing

using namespace std;
using namespace std::chrono;

int main() {
    TSPSolver solver;

    int choice;
    int data;
    char runAgain;
    string cities;

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
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Your choice is not valid, please choose again (1-6): ";
            cin >> choice;
        }

        cout << "Available Datasets:" << endl;
        cout << "1. 5 cites" << endl;
        cout << "2. 15 cites" << endl;
        cout << "3. 17 cites" << endl;
        cout << "4. 26 cites" << endl;
        cout << "5. 48 cites" << endl;

        cout << "Which dataset do you want to use? Enter a number (1-5): ";
        cin >> data;

        while (cin.fail() || data < 1 || data > 5) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Your choice is not valid, please choose again (1-5): ";
            cin >> data;
        }

        switch (data) {
        case 1:
            cities = "cities5.txt";
            break;
        case 2:
            cities = "cities15.txt";
            break;
        case 3:
            cities = "cities17.txt";
            break;
        case 4:
            cities = "cities26.txt";
            break;
        case 5:
            cities = "cities48.txt";
            break;
        default:
            break;
        }

        DistanceMatrix matrix = FileManager::readMatrixFromFile(cities);
        auto start = high_resolution_clock::now(); // bat dau dem gio

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
            solver.solveWithBF(matrix);
            break;
        case 5:
            solver.solveWithBT(matrix);
            break;
        case 6:
            cout << "Exiting the program." << endl;
            return 0;
        }

        auto stop = high_resolution_clock::now(); 
        auto duration = duration_cast<milliseconds>(stop - start);
        cout << "Time taken: " << duration.count() << " milliseconds" << endl;

        cout << "Do you want to run another algorithm? (Y/N): ";
        cin >> runAgain;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

    } while (runAgain == 'Y' || runAgain == 'y');

    return 0;
}