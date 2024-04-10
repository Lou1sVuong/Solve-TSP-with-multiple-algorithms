#include "FileManager.h"
#include <fstream>
#include <sstream>
#include <cmath>

using namespace std;


DistanceMatrix FileManager::readMatrixFromFile(const string& fileName)
{
    ifstream file(fileName);
    int size;
    file >> size;
    DistanceMatrix matrix(size);

    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            if (file)
            {
                double distance;
                file >> distance;
                matrix.setDistance(i, j, distance);
            }
        }
    }

    return matrix;
}