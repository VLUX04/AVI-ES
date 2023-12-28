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
void numCountriesDest(string airport){
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
    cout << countries.size() << endl;
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
        for (int i = 0; i < k; i++) {

            cout << airportss[i].get_AirportCode() << "| " << connections.findVertex(airportss[i].get_AirportCode())->getAdj().size() + connections.findVertex(airportss[i].get_AirportCode())->getIndegree() << endl;
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
    cout<<res.size();
}


vector<vector<Flight>> bestFlightAirportToAirport(const string& source, const string& target) {

    /*pair<string, set<queue<Flight*>>> res;
    Airport* ap1 = fn.findAirport(airport1);
    Airport* ap2 = fn.findAirport(airport2);
    res.first = airport1;
    for (auto a : fn.getAirports()) a->setVisited(false);
    queue<pair<Airport*, queue<Flight*>>> q;
    q.push({ap1, {}});
    ap1->setVisited(true);
    while (!q.empty()) {
        auto currentAirport = q.front().first;
        auto currentPath = q.front().second;
        q.pop();
        for (auto flight : currentAirport->getFlights()) {
            auto nextAirport = flight->getDestination();
            if (checkWantedAirlines(flight, use)) {
                auto newPath = currentPath;
                newPath.push(flight);
                if(newPath.size()>res.second.begin()->size())break;
                if (nextAirport->getCode() == ap2->getCode()) {
                    if (min > newPath.size()) {
                        res.second.clear();
                        min = newPath.size();
                    }
                    res.second.insert(newPath);
                } else {
                    q.push({nextAirport, newPath});
                }
            }
        }
    }*/
    Vertex<string>* v1;
    Vertex<string>* v2;
    for(auto a: airports) {
        if(source==a.get_AirportName() || source == a.get_AirportCode())
            v1 = connections.findVertex(a.get_AirportCode());
        if(target==a.get_AirportName() || target == a.get_AirportCode())
            v2 = connections.findVertex(a.get_AirportCode());
    }
    vector<vector<Flight>> validItineraries;
    queue<pair<Vertex<string>*, vector<Flight>>> q;
    set<Flight> flightsVisited;
    int minStops = INT_MAX;

    q.push({v1, {}});

    while (!q.empty()) {
        auto current = q.front();

        Vertex<string>* currentVertex = current.first;
        vector<Flight>& currentItinerary = current.second;

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
                        validItineraries.emplace_back(newItinerary);
                    } else if (newItinerary.size() == minStops) {
                        validItineraries.emplace_back(newItinerary);
                    }
                } else {
                    q.emplace(nextVertex, newItinerary);
                    flightsVisited.insert(currentFlight);
                }
            }
        }
    }
    for(auto in: flightsVisited){
        if(in.get_Source() == "LED" && in.get_Target() == "AMS")cout << in.get_Airline()<< endl;
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

    vector<vector<vector<Flight>>> allPaths;

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

    vector<vector<vector<Flight>>> allPaths;

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


#endif //PROJECT_AIR_DISPLAYS_H
