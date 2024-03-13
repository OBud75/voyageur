#ifndef __NEIGHBOR_H
#define __NEIGHBOR_H

class City;

class Neighbor
{
private:
    City *city;
    int distance;
    bool isVisited;
public:
    Neighbor(City *, int);
    City *getCity();
    int getDistance();
};

#endif
