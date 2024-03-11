#include <iostream>
#include <fstream>
#include <sstream>
#include "city.h"
#include "cities.h"
#include <vector>
#include <queue>


struct CityComparator {
    bool operator()(const City& city1, const City& city2) const {
         return city1.getDistance() > city2.getDistance();
    }
};

void researchBestPath(City &city);

int shortest_distance = -1;
Cities *shortest_path = nullptr;

int main(int argc, char *argv[])
{
// Pass a file with a list of cities
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <nom_fichier>" << std::endl;
        return 1;
    }
    std::ifstream file(argv[1]);
    if (!file.is_open()) {
        std::cerr << "Erreur lors de l'ouverture du fichier." << std::endl;
        return 2;
    }
    Cities cities;

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string cityFromName, cityToName;
        int distance;

        if (!(iss >> cityFromName >> distance >> cityToName)) {
            std::cerr << "Erreur lors de la lecture des données depuis le fichier." << std::endl;
            continue;
        }

        cities.addCity(cityFromName);
        cities.addCity(cityToName);
        cities.find(cityFromName)->addNeighbor(cities.find(cityToName), distance);
    }
    cities.find("Issy")->display(0, new std::vector<City*>);


// Define the starting point
    City *startingCity;
    std::string userInput;

    std::cout << "Saisissez la ville de depart parmi celles affichees : " << std::endl;
    std::getline(std::cin, userInput);

    startingCity = cities.find(userInput);

    researchBestPath(&cities, startingCity, new Cities(), 0);
}

// Research the best path
void researchBestPath(Cities *all_cities, City *current_city, Cities path, int current_distance){
    // An already path candidate has been found and we already have travelled too far
    if(shortest_distance != -1 && current_distance > shortest_distance)
        return;
    if len(path) + 1 == all_cities->size():
    {
        if(current_distance < shortest_distance || shortest_distance == -1)
        {
            shortest_distance = current_distance;
            shortest_path = &path;
        }
        return;
    }
    for next_city in neighbors:
        if next_city in path:
            continue
        researchBestPath(all_cities, next_city, path + current_city, current_distance + neighbor->getDistance());
}
    //std::priority_queue<City, std::vector<City>, CityComparator> cityQueue;
