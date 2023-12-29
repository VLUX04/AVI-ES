#ifndef Project_Air_AIRPORTREADER_H
#define Project_Air_AIRPORTREADER_H

#include <list>
#include <fstream>
#include <iostream>
#include "../Classes/Airport.h"

using namespace std;
map<string,set<string>> Countries;
set<string> Cities;
vector<Airport> airports; ///< Vector that stores all the airport objects from the CSV file.

/**
 * @brief Reads airport data from a CSV file and populates a vector of Airport objects.
 */
void AirportReader() {
    string FILENAME = "dataset/airports.csv"; ///< File path for the airport data CSV file.
    ifstream file; ///< Input file stream.
    string file_text; ///< Variable to store each line of the file.

    file.open(FILENAME);

    getline(file, file_text);

    while(!file.eof()) {
        getline(file, file_text, ',');
        string airportCode = file_text; ///< Airport code.

        getline(file, file_text, ',');
        string airportName = file_text; ///< Airport name.

        getline(file, file_text, ',');
        string city = file_text; ///< City where the airport is located.

        getline(file, file_text, ',');
        string country = file_text; ///< Country where the airport is located.

        getline(file, file_text, ',');
        string helper = file_text;
        double latitude = atof(helper.c_str()); ///< Latitude of the airport's location.

        getline(file, file_text);
        helper = file_text;
        double longitude = atof(helper.c_str()); ///< Longitude of the airport's location.
        Countries[country].insert(city);
        Cities.insert(city);
        airports.emplace_back(airportCode, airportName, city, country, latitude, longitude);
    }
    file.close();
}

#endif //Project_Air_AIRPORTREADER_H