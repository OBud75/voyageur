#ifndef __CITY_H
#define __CITY_H

#include <vector>
#include <string>

class Neighbor;
class Cities;

class City
{
private:
    std::string name;
    std::vector<Neighbor*> neighbors;
    std::vector<Cities*> currentPath;
    std::vector<Cities*> bestPath;
    int distance;
public:
    City(const std::string&);
    const std::string getName();
    void addNeighbor(City *, int);
    void display(int, std::vector<City*> *);
    City *findNeighbor(const std::string);
    Cities * getCurrentPath();
    Cities * getBestPath();
    int getDistance();

};

#endif
