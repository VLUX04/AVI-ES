/**
 * @file FlightsReader.h
 * @brief Header file containing functions to read flights data from a CSV file.
 */

#ifndef Project_Air_FLIGHTSREADER_H
#define Project_Air_FLIGHTSREADER_H

#include <list>
#include <fstream>
#include <iostream>
#include "../Classes/Flights.h"
#include "Graph.h"
#include <algorithm>

using namespace std;

set<Flight> flights; ///< Set that contains all the flights.
map<pair<string,string>,set<string>> AirToAirAirline; ///< Map that contains source and destination of the flights and its respective airline.

Graph<string> connections; ///< Graph that contains the connections between airports.
Graph<string> undirectedConnections; ///< Undirected graph of the connections between airports.

/**
 * @brief Reads flight data from a CSV file, populates a set of Flight objects, and updates a graph of airport connections and its undirected graph.
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

        flights.insert(Flight(source,target,airline));
        if(source != "" && target != ""){
            connections.addVertex(source);
            connections.addVertex(target);
            connections.findVertex(target)->setIndegree(connections.findVertex(target)->getIndegree()+1);
            connections.addEdge(source, target, airline);
            undirectedConnections.addVertex(source);
            undirectedConnections.addVertex(target);
            undirectedConnections.findVertex(target)->setIndegree(connections.findVertex(target)->getIndegree()+1);
            undirectedConnections.addEdge(source, target, airline);
            undirectedConnections.addEdge(target,source," ");
            AirToAirAirline[{source,target}].insert(airline);
        }

    }
    file.close();
}

#endif //Project_Air_FLIGHTSREADER_H