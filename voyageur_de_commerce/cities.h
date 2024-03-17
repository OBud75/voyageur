#ifndef __CITIES_H
#define __CITIES_H

#include <vector>
#include <string>

class City;

class Path
{
private:
    size_t size;
    std::vector<City*> path;
public:
    Path();
    Path(Path *);
    size_t getSize();
    void addCity(const std::string);
    void addCity(City *);
    void removeLastCity();
    City *find(const std::string);
    void display();
    void free();
};

#endif
