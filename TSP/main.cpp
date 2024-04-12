#include "TSPSolver.h"
#include "FileManager.h"
#include "DistanceMatrix.h"
#include <iostream>

using namespace std;

int main()
{

    // Read distances from file
    DistanceMatrix matrix = FileManager::readMatrixFromFile("data.txt");

    TSPSolver solver;

   solver.solveWithACO(matrix);

    solver.solveWithGA(matrix);


    return 0;
}
