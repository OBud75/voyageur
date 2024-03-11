#include "cities.h"
#include <algorithm>
#include "city.h"

Cities::Cities()
{
    size = 0;
}

void Cities::addCity(const std::string name)
{
    if(find(name) == nullptr)
    {
        cities.push_back(new City(name));
        size++;
    }
}

void Cities::addCity(City *city)
{
    if(find(city->getName()) == nullptr)
    {
        cities.push_back(city);
        size++;
    }
}

City *Cities::find(const std::string name)
{
    for(size_t i = 0; i < size; i++)
    {
        if(cities[i]->getName() == name)
        {
            return cities[i];
        }
    }
    return nullptr;
}