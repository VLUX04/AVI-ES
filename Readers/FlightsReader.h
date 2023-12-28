#ifndef Project_Air_FLIGHTSREADER_H
#define Project_Air_FLIGHTSREADER_H


#include <list>
#include <fstream>
#include <iostream>
#include "../Classes/Flights.h"
#include "Graph.h"
#include <algorithm>

using namespace std;

set<Flight> flights;

Graph<string> connections;

void FlightsReader() {

    string FILENAME = "dataset/flights.csv";
    ifstream file;
    string file_text;
    file.open(FILENAME);

    getline(file, file_text);

    while(!file.eof()) {

        getline(file, file_text, ',');
        string Source = file_text;

        getline(file, file_text, ',');
        string Target = file_text;

        getline(file, file_text);
        string Airline = file_text;

        flights.insert(Flight(Source,Target,Airline));

        connections.addVertex(Source);
        connections.addVertex(Target);
        connections.findVertex(Target)->setIndegree(connections.findVertex(Target)->getIndegree()+1);
        connections.addEdge(Source,Target,Airline);
    }
    file.close();

}

#endif //Project_Air_FLIGHTSREADER_H
