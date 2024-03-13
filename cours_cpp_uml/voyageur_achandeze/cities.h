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
    Cities(Cities *);
    size_t getSize();
    void addCity(const std::string);
    void addCity(City *);
    void removeLastCity();
    City *find(const std::string);
    void display();
    void free();
};

#endif
