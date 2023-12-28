#ifndef Project_Air_FLIGHTSREADER_H
#define Project_Air_FLIGHTSREADER_H

#include <list>
#include <fstream>
#include <iostream>
#include "../Classes/Flights.h"
#include "Graph.h"
#include <algorithm>

using namespace std;

vector<Flight> flights; ///< Vector that stores all the flight objects from the CSV file.

Graph<string> connections; ///< Graph that contains the connections between airports.

/**
 * @brief Reads flight data from a CSV file, populates a vector of Flight objects, and updates a graph of airport connections.
 */
void FlightsReader() {
    string FILENAME = "dataset/flights.csv"; ///< File path for the flight data CSV file.
    ifstream file; ///< Input file stream.
    string file_text; ///< Variable to store each line of the file.

    file.open(FILENAME);

    getline(file, file_text);

    while(!file.eof()) {
        getline(file, file_text, ',');
        string source = file_text; ///< Source airport code.

        getline(file, file_text, ',');
        string target = file_text; ///< Target airport code.

        getline(file, file_text);
        string airline = file_text; ///< Airline code.

        flights.emplace_back(source,target,airline);

        connections.addVertex(source);
        connections.addVertex(target);
        connections.findVertex(target)->setIndegree(connections.findVertex(target)->getIndegree()+1);
        connections.addEdge(source, target, airline);
    }
    file.close();
}

#endif //Project_Air_FLIGHTSREADER_H