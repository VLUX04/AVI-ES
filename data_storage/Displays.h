//
// Created by psclr on 25/12/2023.
//

#ifndef PROJECT_AIR_DISPLAYS_H
#define PROJECT_AIR_DISPLAYS_H

#include <vector>
#include "../Classes/Airline.h"
#include "../Classes/Airport.h"
#include "../Classes/Flights.h"
#include "../Readers/Graph.h"
#include "../Readers/AirlineReader.h"
#include "../Readers/AirportReader.h"
#include "../Readers/FlightsReader.h"

void numberAirlines(){
    cout << airlines.size()<< endl;
}

void numberAirports(){
    cout << airports.size()<< endl;
}

void numberFlights(){
    cout << flights.size()<< endl;
}

void numberOut(string airport){

    if(connections.findVertex(airport) != nullptr){
        cout << connections.findVertex(airport)->getAdj().size() << endl;
        set<string> numAirlines;
        for(auto in : connections.findVertex(airport)->getAdj()){
            numAirlines.insert(in.getWeight());
        }
        cout << numAirlines.size() << endl;
    }
    else{cout << "Wrong Input." << endl;}
}

void flightsPerCity(string city){
    int count = 0;
    for(auto in : airports){
        if(in.get_City() == city){
            if(connections.findVertex(in.get_AirportCode()) != nullptr){
                count += connections.findVertex(in.get_AirportCode())->getAdj().size();
            }
        }
    }
    cout << count << endl;
}

void flightsPerAirline(string name){
    int count = 0;
    for(auto in : airlines){
        if(in.get_AirlineName() == name){
            for(auto in1 : connections.getVertexSet()){
                for(auto in2 : in1->getAdj()){
                    if(in2.getWeight() == in.get_AirlineCode())count++;
                }
            }
        }
    }
    cout << count << endl;
}


#endif //PROJECT_AIR_DISPLAYS_H
