#include "neighbor.h"
#include "city.h"

Neighbor::Neighbor(City *_city, int _distance)
{
    city = _city;
    distance = _distance;
}

int Neighbor::getDistance()
{
    return distance;
}

City *Neighbor::getCity()
{
    return city;
}
