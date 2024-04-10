// FileManager.h
#pragma once

#include <string>
#include "DistanceMatrix.h" // Assuming DistanceMatrix is defined in a separate file

class FileManager
{
public:
    static DistanceMatrix readMatrixFromFile(const std::string& fileName);
};