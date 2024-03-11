#include "city.h"
#include "neighbor.h"
#include <iostream>
#include <algorithm>

City::City(const std::string& _name)
{
    name =_name;
    distance = 0; // ajout
}

const std::string City::getName()
{
    return name;
}

void City::addNeighbor(City *_city, int _distance)
{
    if(findNeighbor(_city->getName()) == nullptr)
    {
        neighbors.push_back(new Neighbor(_city, _distance));
        _city->neighbors.push_back(new Neighbor(this, _distance));
    }
}

void City::display(int indent, std::vector<City*> *already_displayed)
{
    already_displayed->push_back(this);
    std::cout << name << std::endl;
    for(size_t i = 0; i < neighbors.size(); i++)
    {
        City *_city = neighbors[i]->getCity();
        for(int _i = 0; _i < indent; _i++)
        {
            std::cout << "  ";
        }
        std::cout << "  -> " << neighbors[i]->getDistance() << ": ";
        auto it = std::find(already_displayed->begin(), already_displayed->end(), _city);
        if (it != already_displayed->end())
            std::cout << neighbors[i]->getCity()->getName() << std::endl;
        else
            neighbors[i]->getCity()->display(indent + 1,  already_displayed);
    }
}

City *City::findNeighbor(const std::string name)
{
    for(size_t i = 0; i < neighbors.size(); i++)
    {
        if(neighbors[i]->getCity()->getName() == name)
        {
            return neighbors[i]->getCity();
        }
    }
    return nullptr;
}

//ajout
Cities * City::getCurrentPath(){

    return currentPath;

}

Cities * City::getBestPath(){

    return bestPath;

}

int City::getDistance(){

    return distance;

}
