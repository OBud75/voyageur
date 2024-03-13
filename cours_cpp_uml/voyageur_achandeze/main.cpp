#include <iostream>
#include <fstream>
#include <sstream>
#include "city.h"
#include "neighbor.h"
#include "cities.h"
#include <vector>
#include <chrono>

void researchBestPath(City *, Cities *, int);

int shortest_distance = -1;
Cities *shortest_path = nullptr;
Cities all_cities;
City *startingCity = nullptr;

/*-----------------------------------------------------------------------------

                            PROGRAMME PRINCIPAL

-----------------------------------------------------------------------------*/

int main(int argc, char *argv[])
{
// Pour passer un fichier avec une liste de villes, sur le modele ville a - distance - ville b
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <nom_fichier>" << std::endl;
        return 1;
    }
    std::ifstream file(argv[1]);
    //std::ifstream file("7.txt");
    if (!file.is_open()) {
        std::cerr << "Erreur lors de l'ouverture du fichier." << std::endl;
        return 2;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string cityFromName, cityToName;
        int distance;

        if (!(iss >> cityFromName >> distance >> cityToName)) {
            std::cerr << "Erreur lors de la lecture des données depuis le fichier." << std::endl;
            continue;
        }

        all_cities.addCity(cityFromName);
        all_cities.addCity(cityToName);
        all_cities.find(cityFromName)->addNeighbor(all_cities.find(cityToName), distance);
    }

// Definit la ville de depart
    std::string userInput;

    while(startingCity == nullptr)
    {
        std::cout << "Saisissez la ville de depart parmi celles du fichier : " << std::endl;
        std::getline(std::cin, userInput);

        startingCity = all_cities.find(userInput);
    }

    std::cout << "Les voisins de cette ville sont : " << std::endl;
    std::vector<City*> *displayed_cities = new std::vector<City*>;
    all_cities.find(userInput)->display(0, displayed_cities);
    delete displayed_cities;
    std::cout << "------------------------------------------------ " << std::endl;

    //lance le chrono avant execution de la recherche
    auto start = std::chrono::high_resolution_clock::now();

    Cities *path = new Cities();
    researchBestPath(startingCity, path, 0);
    delete path;

    //affiche le temps d'execution de l'algo de recherche
    auto end_calcul = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_calcul - start);
    std::cout << "Le calcul a pris: " << duration.count() << " microsecondes" << std::endl;

    if(shortest_distance == -1)
    {
        std::cout << "Pas de route trouvee" << std::endl;
    }
    else
    {
        std::cout << "La route la plus courte trouvee fait : " << shortest_distance << std::endl;
        shortest_path->display();
        delete shortest_path;
    }
    all_cities.free();
}

void researchBestPath(City *current_city, Cities *path, int current_distance){
    // affiche la ville sommet actuelle et la route en cours d'exploration
    /*std::cout << "Recherche distance(" << current_distance << ") Ville : " << current_city->getName() << " Route : ";
    path->display();
    */

    //Si une ville a déja été visitée (elle est dans le path), on crée un pointeur, utilisé pour sortir de la fonction (après MAJ du path)
    City *city_already_visited = path->find(current_city->getName());
    path->addCity(current_city);

    // On a déja trouve un chemin candidat et la distance actuelle dépasse la distance de ce dernier --> sortie
    if(shortest_distance != -1 && current_distance > shortest_distance)
    {
        return;
    }

    //Teste si le chemin fait la même taille que la liste contenant toutes les villes (uniques) (+ 1 car on veut la ville de départ 2 fois) + teste si la ville actuelle est la ville de départ.
    if(path->getSize() == all_cities.getSize() + 1 && current_city == startingCity)
    {
        if(current_distance < shortest_distance || shortest_distance == -1)
        {
            std::cout << "Candidat possible trouve avec distance de " << current_distance << ": ";
            path->display();
            shortest_distance = current_distance;
            //s'il existe déjà un chemin le plus court, on le supprime pour le remplacer
            if(shortest_path != nullptr)
            {
                delete shortest_path;
            }
            //on recrée un nouveau chemin le plus court
            shortest_path = new Cities(path);
        }
        return;
    }

    //sortie de la fonction car ville déjà visitée --> soit on relance avec la ville suivante soit on a un chemin candidat
    if(city_already_visited != nullptr)
    {
        return;
    }

    // recursion : pour chaque ville, on explore les voisins et on calcule la distance cumulée
    for(size_t i = 0; i < current_city->getNeighbors().size(); i++)
    {
        City *next_city = current_city->getNeighbors()[i]->getCity();
        researchBestPath(next_city, path, current_distance + current_city->getNeighbors()[i]->getDistance());
        path->removeLastCity();
    }
}

