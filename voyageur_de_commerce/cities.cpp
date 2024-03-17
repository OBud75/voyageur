#include "cities.h"
#include <algorithm>
#include "city.h"
#include <iostream>

Path::Path()
{
    size = 0;
}

Path::Path(Path *_paths)
{
    size = 0;
    for(size_t i = 0; i < _paths->getSize(); i++)
    {
        path.push_back(_paths->path[i]);
        size++;
    }
}

void Path::addCity(const std::string name)
{
    if(find(name) == nullptr)
    {
        path.push_back(new City(name));
        size++;
    }
}

void Path::addCity(City *city)
{
    path.push_back(city);
    size++;
}

void Path::removeLastCity()
{
    path.pop_back();
    size--;
}

size_t Path::getSize()
{
    return size;
}


City *Path::find(const std::string name)
{
    for(size_t i = 0; i < size; i++)
    {
        if(path[i]->getName() == name)
        {
            return path[i];
        }
    }
    return nullptr;
}

void Path::display()
{
    for(size_t i = 0; i < size; i++)
    {
        std::cout << path[i]->getName() << ' ';
    }
    std::cout << std::endl;
}

void Path::free()
{
    for(size_t i = 0; i < size; i++)
    {
        delete path[i];
    }
}
