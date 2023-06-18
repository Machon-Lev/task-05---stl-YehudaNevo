#include "CityReader.h"
#include <fstream>
#include <sstream>

CityReader::CityReader(const std::string& filename, CityDatabase& db) : filename(filename), database(db) {}

void CityReader::readCities() {
    std::ifstream file(filename);
    if(!file) {
        throw std::runtime_error("Unable to open file");
    }

    std::string line;
    while(std::getline(file, line)) {
        // The entire line is the city name, including the state
        std::string name = line;

        if(!std::getline(file, line)) {
            throw std::runtime_error("Unexpected end of file");
        }

        std::istringstream ss(line);
        double x, y;
        char dummy;  // variable to read the optional '-' sign

        ss >> x;
        if (ss.peek() == ' ') ss.ignore();  // ignore a space if it is next in the stream
        if (ss.peek() == '-') ss >> dummy;  // read the '-' sign if it is next in the stream
        ss >> y;

        if(ss.fail()) {
            throw std::runtime_error("Invalid city coordinates");
        }

        City city{name, x, y};
        database.addCity(city);
    }
}


