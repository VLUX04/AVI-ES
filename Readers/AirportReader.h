/**
 * @file AirportReader.h
 * @brief Header file containing functions to read airport data from a CSV file.
 */

#ifndef Project_Air_AIRPORTREADER_H
#define Project_Air_AIRPORTREADER_H

#include <list>
#include <fstream>
#include <iostream>
#include "../Classes/Airport.h"

using namespace std;

map<string,set<string>> Countries; ///< Map that contains the cities of every country.
set<string> Cities; ///< Set that contains all the cities.
vector<Airport> airports; ///< Vector that stores all the airport objects from the CSV file.

/**
 * @brief Reads airport data from a CSV file and populates a vector of Airport objects.
 */
void AirportReader() {
    string FILENAME = "dataset/airports.csv";
    ifstream file;
    string file_text;

    file.open(FILENAME);

    getline(file, file_text);

    while(!file.eof()) {
        getline(file, file_text, ',');
        string airportCode = file_text;

        getline(file, file_text, ',');
        string airportName = file_text;

        getline(file, file_text, ',');
        string city = file_text;

        getline(file, file_text, ',');
        string country = file_text;

        getline(file, file_text, ',');
        string helper = file_text;
        double latitude = atof(helper.c_str());

        getline(file, file_text);
        helper = file_text;
        double longitude = atof(helper.c_str());

        if(!country.empty()) Countries[country].insert(city);
        Cities.insert(city);
        airports.emplace_back(airportCode, airportName, city, country, latitude, longitude);
    }
    file.close();
}

#endif //Project_Air_AIRPORTREADER_H