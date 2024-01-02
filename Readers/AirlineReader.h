/**
 * @file AirlineReader.h
 * @brief Header file containing functions to read airline data from a CSV file.
 */

#ifndef Project_Air_AIRLINEREADER_H
#define Project_Air_AIRLINEREADER_H

#include <fstream>
#include <iostream>
#include <string>
#include <list>
#include <map>
#include <fstream>
#include "../Classes/Airline.h"
#include <list>
#include <map>
#include <vector>
#include <set>
#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;

vector<Airline> airlines; ///< Vector that stores all the airline objects from the CSV file.

/**
 * @brief Reads airline data from a CSV file and populates a vector of Airline objects.
 */
void AirlineReader() {
    string FILENAME = "dataset/airlines.csv"; ///< File path for the airline CSV file.
    ifstream file; ///< Input file stream.
    string file_text; ///< Variable to store each line of the file.

    file.open(FILENAME);

    getline(file, file_text);

    while(!file.eof()) {
        getline(file, file_text, ',');
        string airlineCode = file_text; ///< Airline code.

        getline(file, file_text, ',');
        string airlineName = file_text; ///< Airline name.

        getline(file, file_text, ',');
        string callSign = file_text; ///< Airline call sign.

        getline(file, file_text);
        string country = file_text; ///< Country where the airline is based.

        airlines.emplace_back(airlineCode, airlineName, callSign, country);
    }
    file.close();
}

#endif //Project_Air_AIRLINEREADER_H