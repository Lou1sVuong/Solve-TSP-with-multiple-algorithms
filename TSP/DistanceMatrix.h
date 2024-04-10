#ifndef DISTANCEMATRIX_H
#define DISTANCEMATRIX_H

#include <vector>
using namespace std;

class DistanceMatrix
{
public:
    vector<vector<double>> matrix;

    int size() const;

    DistanceMatrix(int size);
    void setDistance(int i, int j, double distance);
    double getDistance(int i, int j) const;
};

#endif // DISTANCEMATRIX_H