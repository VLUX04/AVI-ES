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

void countriesPerCity(string city){
    set<string> countries;
    for(auto in : airports){
        if(in.get_City() == city){
            if(connections.findVertex(in.get_AirportCode()) != nullptr){
                for(auto in1 : connections.findVertex(in.get_AirportCode())->getAdj()){
                    for(auto in2 : airports){
                        if(in2.get_AirportCode() == in1.getDest()->getInfo()){
                            countries.insert(in2.get_Country());
                        }
                    }
                }
            }
        }
    }
    cout << countries.size() << endl;
}

void countriesPerAirport(string code){
    set<string> countries;
    for(auto in : airports){
        if(in.get_AirportCode() == code && connections.findVertex(code) != nullptr){
            for(auto in1 : connections.findVertex(code)->getAdj()){
                for(auto in2 : airports){
                    if(in2.get_AirportCode() == in1.getDest()->getInfo()){
                        countries.insert(in2.get_Country());
                    }
                }
            }
        }
    }
    cout << countries.size() << endl;
}

void numAirportsDest(string airport){
    set<string> airportss;
    for(auto in : airports){
        if(in.get_AirportCode() == airport && connections.findVertex(airport) != nullptr){
            for(auto in1 : connections.findVertex(airport)->getAdj()){
                for(auto in2 : airports){
                    if(in2.get_AirportCode() == in1.getDest()->getInfo()){
                        airportss.insert(in2.get_AirportCode());
                    }
                }
            }
        }
    }
    cout << airportss.size() << endl;

}
void numCitiesDest(string airport){
    set<string> cities;
    for(auto in : airports){
        if(in.get_AirportCode() == airport && connections.findVertex(airport) != nullptr){
            for(auto in1 : connections.findVertex(airport)->getAdj()){
                for(auto in2 : airports){
                    if(in2.get_AirportCode() == in1.getDest()->getInfo()){
                        cities.insert(in2.get_City());
                    }
                }
            }
        }
    }
    cout << cities.size() << endl;
}

void countriesPerAirportAtDistance(string airport,int k){
    set<string> countries;
    for(int i = 1; i <= k; i++){
        for(auto in : connections.nodesAtDistanceBFS(airport,i)){
            for(auto in1 : airports){
                if(in1.get_AirportCode() == in){
                    countries.insert(in1.get_Country());
                }
            }
        }
    }
    cout << countries.size() << endl;
}

void numAirportsDestAtDistance(string airport,int k){
    set<string> airportss;
    for(int i = 1; i <= k; i++){
        for(auto in : connections.nodesAtDistanceBFS(airport,i)){
            for(auto in1 : airports){
                if(in1.get_AirportCode() == in){
                    airportss.insert(in1.get_AirportCode());
                }
            }
        }
    }
    cout << airportss.size() << endl;

}
void numCitiesDestAtDistance(string airport,int k){
    set<string> cities;
    for(int i = 1; i <= k; i++){
        for(auto in : connections.nodesAtDistanceBFS(airport,i)){
            for(auto in1 : airports){
                if(in1.get_AirportCode() == in){
                    cities.insert(in1.get_City());
                }
            }
        }
    }
    cout << cities.size() << endl;
}



#endif //PROJECT_AIR_DISPLAYS_H
