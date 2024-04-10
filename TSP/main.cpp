#include "TSPSolver.h"
#include "FileManager.h"
#include "DistanceMatrix.h" // Include DistanceMatrix.h to use the DistanceMatrix class
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main()
{
    cout << "hello" << endl;

    // Create a DistanceMatrix object with size 3
    DistanceMatrix matrix(5);

    // Set distances manually using setDistance() method

     /*
     * 
     * 
     * 
     * 
     * 
     * 
     * 
     * 
     * 
     * 
  0   10  15  25  35
  10   0  20  30  40
  15  20  0   35  45
  25  30  35  0   50
  35  40  45  50  0










  */

    matrix.setDistance(0, 0, 0);
    matrix.setDistance(1, 1, 0);
    matrix.setDistance(2, 2, 0);
    matrix.setDistance(3, 3, 0);
    matrix.setDistance(4, 4, 0);

    matrix.setDistance(0, 1, 10);
    matrix.setDistance(1, 0, 10);

    matrix.setDistance(0, 2, 15);
    matrix.setDistance(2, 0, 15);

    matrix.setDistance(0, 3, 25);
    matrix.setDistance(3, 0, 25);

    matrix.setDistance(0, 4, 35);
    matrix.setDistance(4, 0, 35);

    matrix.setDistance(1, 2, 20);
    matrix.setDistance(2, 1, 20);

    matrix.setDistance(1, 3, 30);
    matrix.setDistance(3, 1, 30);

    matrix.setDistance(1, 4, 40);
    matrix.setDistance(4, 1, 40);

    matrix.setDistance(2, 3, 35);
    matrix.setDistance(3, 2, 35);

    matrix.setDistance(2, 4, 45);
    matrix.setDistance(4, 2, 45);

    matrix.setDistance(3, 4, 50);
    matrix.setDistance(4, 3, 50);

   
    

    // Alternatively, you could read the matrix from a file using FileManager::readMatrixFromFile()

    TSPSolver solver;

    solver.solveWithACO(matrix);

    // solver.solveWithGA(matrix);

    return 0;
}
