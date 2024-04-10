#ifndef CITY_H
#define CITY_H
using namespace std;

class City
{
public:
    int id;
    double x, y;

    City(int id, double x, double y);
    double distanceTo(const City& other) const;
};

#endif // CITY_H