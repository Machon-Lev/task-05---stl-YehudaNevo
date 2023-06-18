//
// Created by yehuda nevo on 17/06/2023.
//
#ifndef TASK06_CITYDATABASE_H
#define TASK06_CITYDATABASE_H
#include <unordered_map>
#include <vector>
#include <string>
#include "City.h"
#include "DistanceCalculator.h"
#include <map>

class CityDatabase {
public:
    CityDatabase();
    ~CityDatabase();

    void addCity(const City& city);
    void removeCity(const std::string& cityName);
    const City& getCity(const std::string& cityName) const;
    std::vector<City> findNearbyCities(const std::string& cityName, double radius, int norm) const;



private:
    std::unordered_map<std::string, City> cities;
    std::map<int, DistanceCalculator*> calculators;
};



#endif //TASK06_CITYDATABASE_H
