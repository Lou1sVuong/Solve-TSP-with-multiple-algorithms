#include "City.h"
#include <cmath>

City::City(int id, double x, double y) : id(id), x(x), y(y) {}

double City::distanceTo(const City& other) const
{
    double deltaX = x - other.x;
    double deltaY = y - other.y;
    return sqrt(deltaX * deltaX + deltaY * deltaY);
}