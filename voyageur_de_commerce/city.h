#ifndef __CITY_H
#define __CITY_H

#include <vector>
#include <string>

class Neighbor;
class Path;

class City
{
private:
    std::string name;
    std::vector<Neighbor*> neighbors;
    int distance;
public:
    City(const std::string&);
    const std::string getName();
    void addNeighbor(City *, int);
    void display(int, std::vector<City*> *);
    City *findNeighbor(const std::string);
    int getDistance();
    std::vector<Neighbor*> getNeighbors();
    ~City();
};

#endif
