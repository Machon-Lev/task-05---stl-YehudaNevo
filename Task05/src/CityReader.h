//
// Created by yehuda nevo on 17/06/2023.
//

#ifndef TASK06_CITYREADER_H
#define TASK06_CITYREADER_H


#include <string>
#include "CityDatabase.h"

class CityReader {
public:
    CityReader(const std::string& filename, CityDatabase& db);
    void readCities();
private:
    std::string filename;
    CityDatabase& database;
};


#endif //TASK06_CITYREADER_H
