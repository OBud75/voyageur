#include "cities.h"
#include <algorithm>
#include "city.h"
#include <iostream>

Cities::Cities()
{
    size = 0;
}

Cities::Cities(Cities *_cities)
{
    size = 0;
    for(size_t i = 0; i < _cities->getSize(); i++)
    {
        cities.push_back(_cities->cities[i]);
        size++;
    }
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
    cities.push_back(city);
    size++;
}

void Cities::removeLastCity()
{
    cities.pop_back();
    size--;
}

size_t Cities::getSize()
{
    return size;
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

void Cities::display()
{
    for(size_t i = 0; i < size; i++)
    {
        std::cout << cities[i]->getName() << ' ';
    }
    std::cout << std::endl;
}

void Cities::free()
{
    for(size_t i = 0; i < size; i++)
    {
        delete cities[i];
    }
}
