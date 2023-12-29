#ifndef PROJECT_AIR_DISPLAYS_H
#define PROJECT_AIR_DISPLAYS_H

#include <utility>
#include <vector>
#include <unordered_set>
#include <limits>
#include <climits>
#include <cmath>
#include "../Classes/Airline.h"
#include "../Classes/Airport.h"
#include "../Classes/Flights.h"
#include "../Readers/Graph.h"
#include "../Readers/AirlineReader.h"
#include "../Readers/AirportReader.h"
#include "../Readers/FlightsReader.h"

set<string> airlinesToFilter;
int NumAirline =INT_MAX;
string ChosedAirline;
set<string> airpotsToFilter;

bool checkIfAlreadySeen(Flight flight, vector<Flight> vector1);

void numberAirlines(){
    cout << airlines.size()<< endl;
}

int numberAirports(){
    return airports.size();
}

int numberFlights(){
    return flights.size();
}

void numberOut(string airport){
    cout << endl;
    cout << "The number of flights out of " << airport << " is " << connections.findVertex(airport)->getAdj().size();
    set<string> numAirlines;
    for(auto in : connections.findVertex(airport)->getAdj()){
        numAirlines.insert(in.getWeight());
    }
    cout << " and they are from " << numAirlines.size() << " different airlines." << endl;
}

int flightsPerCity(string city){
    int count = 0;
    for(auto in : airports){
        if(in.get_City() == city){
            if(connections.findVertex(in.get_AirportCode()) != nullptr){
                count += connections.findVertex(in.get_AirportCode())->getAdj().size();
            }
        }
    }
    return count;
}

int flightsPerAirline(string name){
    int count = 0;
    for(auto in : airlines){
        if(in.get_AirlineName() == name || in.get_AirlineCode() == name){
            for(auto in1 : connections.getVertexSet()){
                for(auto in2 : in1->getAdj()){
                    if(in2.getWeight() == in.get_AirlineCode())count++;
                }
            }
        }
    }
    return count;
}

int countriesPerCity(string country, string city){
    set<string> countries;
    for(auto in : airports){
        if(in.get_City() == city && in.get_Country() == country){
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
    return countries.size();
}

int countriesPerAirport(string code){
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
    return countries.size();
}

int numAirportsDest(string airport){
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
    return airportss.size();

}
int numCitiesDest(string airport){
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
    return cities.size();
}
int numCountriesDest(string airport){
    set<string> countries;
    for(auto in : airports){
        if(in.get_AirportCode() == airport && connections.findVertex(airport) != nullptr){
            for(auto in1 : connections.findVertex(airport)->getAdj()){
                for(auto in2 : airports){
                    if(in2.get_AirportCode() == in1.getDest()->getInfo()){
                        countries.insert(in2.get_Country());
                    }
                }
            }
        }
    }
    return countries.size();
}

int countriesPerAirportAtDistance(string airport,int k){
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
    return countries.size();
}

int numAirportsDestAtDistance(string airport,int k){
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
    return airportss.size();

}
int numCitiesDestAtDistance(string airport,int k){
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
    return cities.size();
}

bool airportCompareByFlights(Airport a, Airport b){
    size_t adj1= connections.findVertex(a.get_AirportCode())->getAdj().size() + connections.findVertex(a.get_AirportCode())->getIndegree();
    size_t adj2= connections.findVertex(b.get_AirportCode())->getAdj().size() + connections.findVertex(b.get_AirportCode())->getIndegree();
    if(adj1!=adj2)return adj1> adj2;
    else{return a.get_AirportCode()>b.get_AirportCode();}
}
void greatestAirTrafficCapacity(int k){
    if(k<=airports.size()) {
        vector<Airport> airportss = airports;
        sort(airportss.begin(), airportss.end(), [](const Airport &a, const Airport &b) {
            return airportCompareByFlights(a, b);
        });
        cout << "The top " << k << " airports with the greatest air traffic capacity are:" << endl;
        cout << "  Airport Code   Air traffic capacity" << endl;
        for (int i = 0; i < k; i++) {
            cout << "      " << airportss[i].get_AirportCode() << "                " << connections.findVertex(airportss[i].get_AirportCode())->getAdj().size() + connections.findVertex(airportss[i].get_AirportCode())->getIndegree() << endl;
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
    cout << "The maximum number of stops is " << maxStops << " and the pairs of source and destiny of those trips are:" << endl;
    cout << "Source -> Destiny:" << endl;
    for(auto in : trips){
        cout << "  " << in.first << "      " << in.second << endl;
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

unordered_set<string> articulationPoints(){
    unordered_set<string> res;
    stack<string> s;
    int i = 0;
    Graph<string> copy = connections;
    for(auto vertex:copy.getVertexSet()){
        vertex->setNum(i);
    }
    i++;
    for(auto vertex:copy.getVertexSet()){
        if(vertex->getNum() == 0){dfs_art(copy,vertex,s,res,i);}
    }
    return res;
}
void essentialAirports(){  //pus so a dar para ver o size
    unordered_set<string> res;
    res = articulationPoints();
    cout << "In total there are " << res.size() << " essential airports to the network's circulation capability" << endl;
}


set<vector<Flight>> bestFlightAirportToAirport(const string& source, const string& target) {

    Vertex<string>* v1;
    Vertex<string>* v2;

    for (auto a : airports) {
        if (source == a.get_AirportName() || source == a.get_AirportCode())
            v1 = connections.findVertex(a.get_AirportCode());
        if (target == a.get_AirportName() || target == a.get_AirportCode())
            v2 = connections.findVertex(a.get_AirportCode());
    }

    set<vector<Flight>> validItineraries;
    queue<pair<Vertex<string>*, vector<Flight>>> q;
    set<Flight> flightsVisited;
    int minStops = INT_MAX;

    q.push({v1, {}});

    while (!q.empty()) {
        auto currentVertex = q.front().first;
        auto currentItinerary = q.front().second;

        q.pop();

        for (const auto& edge : currentVertex->getAdj()) {
            Vertex<string>* nextVertex = edge.getDest();
            Flight currentFlight = Flight(currentVertex->getInfo(), nextVertex->getInfo(), edge.getWeight());
            if (flightsVisited.find(currentFlight) == flightsVisited.end()) {
                vector<Flight> newItinerary = currentItinerary;
                newItinerary.emplace_back(currentFlight);

                if (nextVertex->getInfo() == v2->getInfo()) {
                    if (newItinerary.size() < minStops) {
                        minStops = newItinerary.size();
                        validItineraries.clear();
                        validItineraries.insert(newItinerary);
                    } else if (newItinerary.size() == minStops) {
                        validItineraries.insert(newItinerary);
                    }
                } else {
                    q.emplace(nextVertex, newItinerary);
                    flightsVisited.insert(currentFlight);
                }
            }
        }
    }

    for(auto in1: validItineraries){
        vector <Flight> tempVector = in1;
        for(int i = 0; i <in1.size(); i++){
            for(auto in : AirToAirAirline[{in1[i].get_Source(),in1[i].get_Target()}]){
                if(in1[i].get_Airline() != in){
                    tempVector[i] = Flight(in1[i].get_Source(),in1[i].get_Target(),in);
                }
            }
        }
        validItineraries.insert(tempVector);
    }

    if (minStops == INT_MAX) {
        cout << "No valid flights found." << endl;
        return validItineraries;
    }

    cout << "Best itineraries:" << endl;
    set<string> diffAirlines;
    cout << validItineraries.size() << endl;
    cout << endl;
    for (const auto& itinerary : validItineraries) {
        bool flag1 = true;
        bool flag2 = true;
        bool flag3 = true;
        for (const auto& f : itinerary) {
            diffAirlines.insert(f.get_Airline());
            if(!airlinesToFilter.empty()){
                flag1 = airlinesToFilter.find(f.get_Airline()) == airlinesToFilter.end();
                if(!flag1)break;
            }
        }
        for (const auto& f : itinerary) {
            if(!ChosedAirline.empty()){
                flag2 = ChosedAirline == f.get_Airline();
                if(!flag2)break;
            }
        }
        for (const auto& f : itinerary) {
            if(!airpotsToFilter.empty()){
                flag3 = (airpotsToFilter.find(f.get_Source()) == airpotsToFilter.end()) && (airpotsToFilter.find(f.get_Target()) == airpotsToFilter.end());
                if(!flag3)break;
            }
        }
        if(flag1 && diffAirlines.size() <= NumAirline && flag2 && flag3){
            for (const auto& f : itinerary)cout << f.get_Source() << "->" << f.get_Target() << " (" << f.get_Airline() << ")" << endl;
            cout << endl;
        }

    }
    return validItineraries;

}

bool checkIfAlreadySeen(Flight flight, vector<Flight> flightsVisited) {
    for(auto in : flightsVisited){
        if(in.get_Airline() == flight.get_Airline() && in.get_Target() == flight.get_Target() && in.get_Source() == flight.get_Source())return true;
    }
    return false;
}

double toRadians(double degree) {
    return degree * (M_PI / 180.0);
}

double haversine(double lat1, double lon1, double lat2, double lon2) {
    lat1 = toRadians(lat1);
    lon1 = toRadians(lon1);
    lat2 = toRadians(lat2);
    lon2 = toRadians(lon2);

    double dlat = lat2 - lat1;
    double dlon = lon2 - lon1;

    double a = std::sin(dlat / 2.0) * std::sin(dlat / 2.0) +
               std::cos(lat1) * std::cos(lat2) *
               std::sin(dlon / 2.0) * std::sin(dlon / 2.0);
    double c = 2.0 * std::atan2(std::sqrt(a), std::sqrt(1.0 - a));

    double distance = 6371 * c;

    return distance;
}

void coordsBestFlight( double lon, double lat, double targetLon,double targetLat){
    double min = INT_MAX;
    vector<Airport> sourcePossible;
    for(auto in :airports){
        double temp = haversine(in.get_Latitude(),in.get_Longitude(),lon,lat);
        if(temp < min)min = temp;
    }
    for(auto in :airports){
        double temp = haversine(in.get_Latitude(),in.get_Longitude(),lon,lat);
        if(temp == min)sourcePossible.push_back(in);
    }
    cout << sourcePossible.size() << endl;
    min = INT_MAX;
    vector<Airport> destPossible;
    for(auto in :airports){
        double temp = haversine(in.get_Latitude(),in.get_Longitude(),targetLon,targetLat);
        if(temp < min)min = temp;
    }
    for(auto in :airports){
        double temp = haversine(in.get_Latitude(),in.get_Longitude(),targetLon,targetLat);
        if(temp == min)destPossible.push_back(in);
    }
    cout << destPossible.size() << endl;

    vector<set<vector<Flight>>> allPaths;

    for(auto in : sourcePossible){
        for(auto in1 : destPossible){
            allPaths.push_back(bestFlightAirportToAirport(in.get_AirportCode(),in1.get_AirportCode()));
        }
    }
}

vector<Airport> findAirportsInCity(const string& city) {
    vector<Airport> cityAirports;
    for(const auto& a: airports) {
        if(a.get_City()==city)
            cityAirports.push_back(a);
    }
    return cityAirports;
}

void bestFlightCityToCity(const string& sourceCity, const string& targetCity) {
    vector<Airport> sourceAirports = findAirportsInCity(sourceCity);
    vector<Airport> targetAirports = findAirportsInCity(targetCity);

    vector<set<vector<Flight>>> allPaths;

    for(auto in : sourceAirports){
        for(auto in1 : targetAirports){
            allPaths.push_back(bestFlightAirportToAirport(in.get_AirportCode(),in1.get_AirportCode()));
        }
    }
}

void filterNumAirline(int k){
    NumAirline = k;
}

void filterAirlines(set<string> airlinesToFilter_){
    airlinesToFilter = airlinesToFilter_;
}

void filterChosedAirline(string ChosedAirline_){
    ChosedAirline = ChosedAirline_;
}
void filterAirpots(set<string> airpotsToFilter_){
    airpotsToFilter = airpotsToFilter_;
}



/*
void teste(){
    int adj = 0;
    for(auto x: connections.getVertexSet()){
        adj += x->getAdj().size();
    }
    cout << "original " << adj << endl;

    Graph<string> copia;
    int adj1 =0;
    for (auto x : connections.getVertexSet()) {
        Vertex<string>* newVertex = new Vertex<string>(*x);
        for(auto e:x->getAdj()){
            newVertex.addEdge
        }

        copia.addVertex(newVertex->getInfo());

    }

    for(auto x:copia.getVertexSet()){
        adj1 += x->getAdj().size();
    }
    cout << "copia " << adj1 << endl;

    for(auto x :copia.getVertexSet()){
        for(auto edge: x->getAdj()){
            copia.addEdge(edge.getDest()->getInfo(),x->getInfo()," ");
        }
    }
    adj = 0;
    for(auto x: connections.getVertexSet()){
        adj += x->getAdj().size();
    }
    cout << " dps da copia original " << adj << endl;
    adj1 = 0;
    for(auto x:copia.getVertexSet()){
        adj1 += x->getAdj().size();
    }
    cout << "copia " << adj1 << endl;
}
 */




#endif //PROJECT_AIR_DISPLAYS_H
