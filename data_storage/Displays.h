//
// Created by psclr on 25/12/2023.
//

#ifndef PROJECT_AIR_DISPLAYS_H
#define PROJECT_AIR_DISPLAYS_H

#include <vector>
#include <unordered_set>
#include <limits>
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
bool airportCompareByFlights(Airport a, Airport b){
    size_t adj1= connections.findVertex(a.get_AirportCode())->getAdj().size();
    size_t adj2= connections.findVertex(b.get_AirportCode())->getAdj().size();
    if(adj1!=adj2)return adj1> adj2;
    else{return a.get_AirportCode()>b.get_AirportCode();}
}
void greatestAirTrafficCapacity(int k){
    if(k<=airports.size()) {
        vector<Airport> airportss = airports;
        sort(airportss.begin(), airportss.end(), [](const Airport &a, const Airport &b) {
            return airportCompareByFlights(a, b);
        });
        for (int i = 0; i < k; i++) {
            cout << airportss[i].get_AirportCode() << "| ";
        }
    }
    else{cout<<"Incorrect input (k is larger than number of airports)";}
}
void dfs(Vertex<string>* v, vector<string> &path, vector<string> &maxPath, int &maxStops,set<pair<string,string>> &trips){
    v->setVisited(true);
    path.push_back(v->getInfo());
    for (auto& in : v->getAdj()){

        if (!in.getDest()->isVisited())dfs(in.getDest(),path,maxPath,maxStops,trips);

    }

}
void maxTrip(){
    int maxStops=0;
    set<pair<string,string>> trips;
    vector<string> path, maxPath;
    for (auto& in :connections.getVertexSet())in->setVisited(false);

    for (auto& in :connections.getVertexSet()){

        if (!in->isVisited())dfs(in,path,maxPath,maxStops,trips);
        if (path.size()>maxStops){
            maxStops=path.size();
            maxPath=path;
            trips.clear();
            trips.insert({path[0],path[path.size()-1]});
        }
        else if(path.size()==maxStops)trips.insert({path[0],path[path.size()-1]});
        for (auto& in1 : connections.getVertexSet())in1->setVisited(false);
        path.clear();

    }
    cout<<maxStops << endl;
    for(auto in : trips){
        cout << in.first << " " << in.second << endl;
    }

}

void dfs_art(Graph<string> q, Vertex<string> * v,stack<string> &s,unordered_set<string> &l, int & i){
    v->setNum(i);
    v->setLow(i);
    i++;
    int children = 0;
    s.push(v->getInfo());
    for(Edge<string> edge:v->getAdj()){
        if(edge.getDest()->getNum() == 0){
            children++;
            dfs_art(q,edge.getDest(),s,l,i);
            v->setLow(min(v->getLow(),edge.getDest()->getLow()));
            if(v->getAdj().size() != 1 && edge.getDest()->getLow() >= v->getNum())
                l.insert(v->getInfo());
        }
        else if(edge.getDest()->getNum() > 0)
            v->setLow(min(v->getLow(),edge.getDest()->getNum()));
    }
    s.pop();
    if(v->getAdj().size() == 1 && children > 1)
        l.insert(v->getInfo());
}

unordered_set<string> articulationPoints(Graph<string>  g){
    unordered_set<string> res;
    stack<string> s;
    int i = 0;
    Graph<string> copy = g;
    for(auto vertex:copy.getVertexSet()){
        vertex->setNum(i);
        for(auto edge:vertex->getAdj()){
            g.addEdge(edge.getDest()->getInfo(),vertex->getInfo(),"");
        }
    }
    i++;
    for(auto vertex:g.getVertexSet()){
        if(vertex->getNum() == 0){dfs_art(copy,vertex,s,res,i);}
    }
    return res;
}
void essentialAirports(){  //pus so a dar para ver o size
    unordered_set<string> res;
    res = articulationPoints(connections);
    cout<<res.size();
}

void bestFlightAirportDFS(Airport& currentAirport, Airport& target, unordered_set<string>& visited, unordered_set<string>& currentPath, vector<Flight>& currentItinerary, vector<Flight>& bestItinerary) {
    visited.insert(currentAirport.get_AirportCode());
    currentPath.insert(currentAirport.get_AirportCode());

    if (!bestItinerary.empty() && currentItinerary.size() >= bestItinerary.size()) {
        currentPath.erase(currentAirport.get_AirportCode());
        return;
    }

    for (auto& flight : flights) {
        if (flight.get_Source() == currentAirport.get_AirportCode() && currentPath.find(flight.get_Target()) == currentPath.end()) {
            currentItinerary.push_back(flight);

            if (flight.get_Target() == target.get_AirportCode()) {
                if (bestItinerary.empty() || currentItinerary.size() < bestItinerary.size()) {
                    bestItinerary = currentItinerary;
                }
            } else {
                for (auto& a : airports) {
                    if (a.get_AirportCode() == flight.get_Target() || a.get_AirportName() == flight.get_Target()) {
                        if (visited.find(a.get_AirportCode()) == visited.end()) {
                            bestFlightAirportDFS(a, target, visited, currentPath, currentItinerary, bestItinerary);
                        }
                        break;
                    }
                }
            }

            currentItinerary.pop_back();
        }
    }

    currentPath.erase(currentAirport.get_AirportCode());
}


void bestFlightAirportToAirport(const string& source, const string& target) {
    Airport a1 = findAirport(source);
    Airport a2 = findAirport(target);
    if(a1.get_AirportCode()=="" || a2.get_AirportCode()=="") {
        cout << "ERROR: Invalid Input";
        return;
    }
    unordered_set<string> visited;
    unordered_set<string> currentPath;
    vector<Flight> currentItinerary;
    vector<Flight> bestItinerary;

    bestFlightAirportDFS(a1, a2, visited, currentPath, currentItinerary, bestItinerary);

    if(bestItinerary.empty()) {
        cout << "No valid itinerary found." << endl;
        return;
    }
    cout << "Best itinerary:" << endl;
    for (auto& flight : bestItinerary) {
        cout << flight.get_Source() << "->" << flight.get_Target() << endl;
    }
}


#endif //PROJECT_AIR_DISPLAYS_H
