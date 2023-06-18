#include "CityDatabase.h"
#include <algorithm>
#include <cmath>
#include <vector>
#include <unordered_map>


CityDatabase::CityDatabase() {
    calculators[0] = new EuclideanCalculator();
    calculators[1] = new ChebyshevCalculator();
    calculators[2] = new ManhattanCalculator();
}

CityDatabase::~CityDatabase() {
    for (auto& calculator : calculators) {
        delete calculator.second;
    }
}


void CityDatabase::addCity(const City& city) {
    cities[city.name] = city;
}

void CityDatabase::removeCity(const std::string& cityName) {
    cities.erase(cityName);
}

const City& CityDatabase::getCity(const std::string& cityName) const {
    return cities.at(cityName);
}

std::vector<City> CityDatabase::findNearbyCities(const std::string& cityName, double radius, int norm) const {
    const City& city = getCity(cityName);
    std::vector<City> result;

    for (const auto& pair : cities) {
        if (calculators.at(norm)->calculate(city, pair.second) <= radius)
            result.push_back(pair.second);
    }

    std::sort(result.begin(), result.end(),
              [&city, norm, this](const City& city1, const City& city2) {
                  return calculators.at(norm)->calculate(city, city1) < calculators.at(norm)->calculate(city, city2);
              });

    return result;
}
