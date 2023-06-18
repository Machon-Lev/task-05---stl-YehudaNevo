#include <iostream>
#include <memory>
#include "City.h"
#include "CityDatabase.h"
#include "CityReader.h"
#include "DistanceCalculator.h"



int main() {
    CityDatabase db;
    CityReader reader("data.txt", db);
    reader.readCities();

    while (true) {
        std::string city;
        std::cout << "Enter the name of the city: "<<std::endl;
        std::getline(std::cin, city);
        if (city == "0") {
            break;
        }

        double radius;
        std::cout << "Enter the desired radius: ";
        std::cin >> radius;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore the rest of the line

        int norm;
        std::cout << "Enter the desired norm (0 – L2, Euclidean distance, 1 – Linf, Chebyshev distance, 2 – L1, Manhattan distance): ";
        std::cin >> norm;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore the rest of the line

        std::vector<City> result;
        try {
            result = db.findNearbyCities(city, radius, norm);
        } catch (const std::out_of_range& e) {
            std::cout << "ERROR: \"" << city << "\" is not found in the city list. Please try again.\n";
            continue;
        }

        std::cout << "Number of nearby cities: " << result.size() << '\n';
        std::for_each(result.begin(), result.end(), [](const City& city) { std::cout << city.name << '\n'; });
    }

    return 0;
}

