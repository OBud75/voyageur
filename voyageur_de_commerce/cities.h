#ifndef __CITIES_H
#define __CITIES_H

#include <vector>
#include <string>

class City;

class Cities
{
private:
    size_t size;
    std::vector<City*> cities;
public:
    Cities();
    void addCity(const std::string);
    void addCity(City *);
    City *find(const std::string);
};

#endif