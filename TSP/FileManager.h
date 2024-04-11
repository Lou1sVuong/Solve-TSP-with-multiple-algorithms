#pragma once

#include <string>
#include "DistanceMatrix.h" // Assuming DistanceMatrix is defined in a separate file

class FileManager
{
public:
    static DistanceMatrix readMatrixFromFile(const std::string& fileName);
    static double calculateDistance(const std::pair<double, double>& p1, const std::pair<double, double>& p2);
};
