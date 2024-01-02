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

set<string> airlinesToFilter; ///< Set of airlines to filter during display operations.
int NumAirline = INT_MAX; ///< Maximum number of airlines to consider during display operations.
set<string> airportsToFilter; ///< Set of airports to filter during display operations.


/**
 * @brief Returns the number of airports in the dataset.
 * @return The number of airports.
 */
int numberAirports(){
    return airports.size();
}

/**
 * @brief Returns the number of flights in the dataset.
 * @return The number of flights.
 */
int numberFlights(){
    return flights.size();
}

/**
 * @brief Displays the number of flights out of a specific airport and the number of different airlines they are from.
 * Complexity: O(V + N * log N).
 * @param airport The code of the airport.
 */
void numberOut(const string& airport){
    cout << endl;
    cout << "The number of flights out of " << airport << " is " << connections.findVertex(airport)->getAdj().size();
    set<string> numAirlines;
    for(const auto& in : connections.findVertex(airport)->getAdj()){
        numAirlines.insert(in.getWeight());
    }
    cout << " and they are from " << numAirlines.size() << " different airlines." << endl;
}

/**
 * @brief Returns the number of flights per city.
 * Complexity: O(V).
 * @param city The name of the city.
 * @return The total number of flights from airports in the specified city.
 */
int flightsPerCity(const string& city){
    int count = 0;
    for(const auto& in : airports){
        if(in.get_City() == city){
            if(connections.findVertex(in.get_AirportCode()) != nullptr){
                count += connections.findVertex(in.get_AirportCode())->getAdj().size();
            }
        }
    }
    return count;
}

/**
 * @brief Returns the number of flights of a specific airline.
 * Complexity: O(N * V * E).
 * @param name The name or code of the airline.
 * @return The total number of flights operated by the specified airline.
 */
int flightsPerAirline(const string& name){
    int count = 0;
    for(const auto& in : airlines){
        if(in.get_AirlineName() == name || in.get_AirlineCode() == name){
            for(auto in1 : connections.getVertexSet()){
                for(const auto& in2 : in1->getAdj()){
                    if(in2.getWeight() == in.get_AirlineCode())count++;
                }
            }
        }
    }
    return count;
}

/**
 * @brief Returns the number of reachable countries from a specific city.
 * Complexity: O(V^3 * N * log C).
 * @param country The name of the city's country.
 * @param city The name of the city.
 * @return The number of unique countries that can be reached from airports in the specified city.
 */
int countriesPerCity(const string& country, const string& city){
    set<string> countries;
    for(const auto& in : airports){
        if(in.get_City() == city && in.get_Country() == country){
            if(connections.findVertex(in.get_AirportCode()) != nullptr){
                for(const auto& in1 : connections.findVertex(in.get_AirportCode())->getAdj()){
                    for(const auto& in2 : airports){
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

/**
 * @brief Returns the number of reachable countries from a specific airport.
 * Complexity: O(V^3 * log C).
 * @param code The code of the airport.
 * @return The number of unique countries that can be reached from the specified airport.
 */
int countriesPerAirport(const string& code){
    set<string> countries;
    for(const auto& in : airports){
        if(in.get_AirportCode() == code && connections.findVertex(code) != nullptr){
            for(const auto& in1 : connections.findVertex(code)->getAdj()){
                for(const auto& in2 : airports){
                    if(in2.get_AirportCode() == in1.getDest()->getInfo()){
                        countries.insert(in2.get_Country());
                    }
                }
            }
        }
    }
    return countries.size();
}

/**
 * @brief Returns the number of reachable airports from a specific airport.
 * Complexity: O(V^3 * log C).
 * @param airport The code or name of the airport.
 * @return The number of unique airports that can be reached from the specified airport.
 */
int numAirportsDest(const string& airport){
    set<string> airportss;
    for(const auto& in : airports){
        if((in.get_AirportCode() == airport || in.get_AirportName() == airport) && connections.findVertex(airport) != nullptr){
            for(const auto& in1 : connections.findVertex(airport)->getAdj()){
                for(const auto& in2 : airports){
                    if(in2.get_AirportCode() == in1.getDest()->getInfo()){
                        airportss.insert(in2.get_AirportCode());
                    }
                }
            }
        }
    }
    return airportss.size();

}

/**
 * @brief Returns the number of reachable cities from a specific airport.
 * Complexity: O(V^3 * log C).
 * @param airport The code or name of the airport.
 * @return The number of unique cities that can be reached from the specified airport.
 */
int numCitiesDest(const string& airport){
    set<string> cities;
    for(const auto& in : airports){
        if((in.get_AirportCode() == airport  || in.get_AirportName() == airport) && connections.findVertex(airport) != nullptr){
            for(const auto& in1 : connections.findVertex(airport)->getAdj()){
                for(const auto& in2 : airports){
                    if(in2.get_AirportCode() == in1.getDest()->getInfo()){
                        cities.insert(in2.get_City());
                    }
                }
            }
        }
    }
    return cities.size();
}

/**
 * @brief Returns the number of reachable countries from a specific airport.
 * Complexity: O(V^3 * log C).
 * @param airport The code or name of the airport.
 * @return The number of unique countries that can be reached from the specified airport.
 */
int numCountriesDest(const string& airport){
    set<string> countries;
    for(const auto& in : airports){
        if((in.get_AirportCode() == airport || in.get_AirportName() == airport) && connections.findVertex(airport) != nullptr){
            for(const auto& in1 : connections.findVertex(airport)->getAdj()){
                for(const auto& in2 : airports){
                    if(in2.get_AirportCode() == in1.getDest()->getInfo()){
                        countries.insert(in2.get_Country());
                    }
                }
            }
        }
    }
    return countries.size();
}

/**
 * @brief Returns the number of countries with destinations with a certain number of flight stops from a given airport.
 * Complexity: O((V + E) * V * log C).
 * @param airport The code of the source airport.
 * @param k The number of flight stops.
 * @return The number of countries reachable from the source airport with the specified number of flight stops.
 */
int countriesPerAirportAtDistance(const string& airport,int k){
    set<string> countries;
    for(int i = 1; i <= k; i++){
        for(const auto& in : connections.nodesAtDistanceBFS(airport,i)){
            for(const auto& in1 : airports){
                if(in1.get_AirportCode() == in){
                    countries.insert(in1.get_Country());
                }
            }
        }
    }
    return countries.size();
}

/**
 * @brief Returns the number of airports with destinations with a certain number of flight stops from a given airport.
 * Complexity: O((V + E) * V * log C).
 * @param airport The code of the source airport.
 * @param k The number of flight stops.
 * @return The number of airports reachable from the source airport with the specified number of flight stops.
 */
int numAirportsDestAtDistance(const string& airport,int k){
    set<string> airportss;
    for(int i = 1; i <= k; i++){
        for(const auto& in : connections.nodesAtDistanceBFS(airport,i)){
            for(const auto& in1 : airports){
                if(in1.get_AirportCode() == in){
                    airportss.insert(in1.get_AirportCode());
                }
            }
        }
    }
    return airportss.size();

}

/**
 * @brief Returns the number of cities with destinations with a certain number of flight stops from a given airport.
 * Complexity: O((V + E) * V * log C).
 * @param airport The code of the source airport.
 * @param k The number of flight stops.
 * @return The number of cities reachable from the source airport with the specified number of flight stops.
 */
int numCitiesDestAtDistance(const string& airport,int k){
    set<string> cities;
    for(int i = 1; i <= k; i++){
        for(const auto& in : connections.nodesAtDistanceBFS(airport,i)){
            for(const auto& in1 : airports){
                if(in1.get_AirportCode() == in){
                    cities.insert(in1.get_City());
                }
            }
        }
    }
    return cities.size();
}

/**
 * @brief Compares two airports based on their air traffic capacity.
 * Complexity: O(V).
 * @param a The first airport for comparison.
 * @param b The second airport for comparison.
 * @return True if the air traffic capacity of airport 'a' is greater than that of airport 'b',
 *         or if the capacities are equal, compare based on airport codes; False otherwise.
 */
bool airportCompareByFlights(const Airport& a, const Airport& b){
    size_t adj1= connections.findVertex(a.get_AirportCode())->getAdj().size() + connections.findVertex(a.get_AirportCode())->getIndegree();
    size_t adj2= connections.findVertex(b.get_AirportCode())->getAdj().size() + connections.findVertex(b.get_AirportCode())->getIndegree();
    if(adj1!=adj2)return adj1> adj2;
    else{return a.get_AirportCode()>b.get_AirportCode();}
}

/**
 * @brief Displays the top k airports with the greatest air traffic capacity.
 * Complexity: O(V * log V).
 * @param k The number of top airports to display.
 */
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

/**
 * @brief Depth-first search (DFS) algorithm to mark connected vertices starting from a given vertex.
 * Complexity: O(V + E).
 * @param v Starting vertex for DFS.
 */
void dfsConnected(Vertex<string> * v){
    v->setVisited(true);
    for(const auto& edge:v->getAdj()){
        if(!edge.getDest()->isVisited()){
            dfsConnected(edge.getDest());
        }
    }
}

/**
 * @brief Checks and prints information about the connections between airports in the graph.
 * Complexity: O(V * (V + E)).
 * The function initializes the visited flag for each vertex, performs DFS to find connected components,
 * and then prints the result indicating whether all airports are connected or if there are separated groups.
 */
void checkIsolatedAirportGroups(){
    int res = 0;
    for(auto x:undirectedConnections.getVertexSet()){
        x->setVisited(false);
    }
    for(auto x:undirectedConnections.getVertexSet()){
        if(!x->isVisited()){
            res++;
            dfsConnected(x);
        }
    }
    if(res == 1){
        cout << "All the airports are connected between them." << endl;
        cout << endl;
    }
    else{
        cout  << "There are " << res << " separated groups of airports that are connected between them." << endl;
        cout << endl;
    }
    for(auto &x:undirectedConnections.getVertexSet()){
        x->setVisited(false);
    }
}

/**
 * @brief Performs depth-first search starting from a given vertex.
 * Complexity: O(V + E).
 * @param v The starting vertex.
 * @param path Vector to store the current path.
 * @param maxPath Vector to store the maximum path.
 * @param maxStops Reference to the maximum number of stops.
 * @param trips Set to store pairs of source and destination of trips.
 */
void dfs(Vertex<string>* v, vector<string> &path, vector<string> &maxPath, int &maxStops,set<pair<string,string>> &trips){
    v->setVisited(true);
    path.push_back(v->getInfo());
    for (auto& in : v->getAdj()){
        if (!in.getDest()->isVisited())dfs(in.getDest(),path,maxPath,maxStops,trips);
    }

}

/**
 * @brief Finds and prints the maximum number of stops in trips between airports.
 * Complexity: O(V^2 * (V + E)).
 */
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

/**
 * @brief Performs depth-first search for finding articulation points in an undirected graph.
 * Complexity: O(V + E).
 * @param q The graph.
 * @param v The current vertex.
 * @param s Stack to keep track of visited vertices.
 * @param l Set to store articulation points.
 * @param i Reference to an integer used for numbering vertices.
 */
void dfs_art(Graph<string> q, Vertex<string> * v,stack<string> &s,unordered_set<string> &l, int & i){
    v->setNum(i);
    v->setLow(i);
    i++;
    int children = 0;
    s.push(v->getInfo());
    for(const Edge<string>& edge:v->getAdj()){
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

/**
 * @brief Finds articulation points in the graph and returns a set of those points.
 * Complexity: O(V * (V + E)).
 * @return Set of articulation points.
 */
unordered_set<string> articulationAirports(){
    unordered_set<string> res;
    stack<string> s;
    int i = 0;
    for(auto vertex:undirectedConnections.getVertexSet()){
        vertex->setNum(i);
    }
    i++;
    for(auto vertex:undirectedConnections.getVertexSet()){
        if(vertex->getNum() == 0){dfs_art(undirectedConnections,vertex,s,res,i);}
    }
    return res;
}

/**
 * @brief Finds the best flights (least stops) between two airports and returns a set of valid itineraries.
 * Complexity: O(A + N * log C + (V * F * log C)).
 * @param source The source airport code or name.
 * @param target The target airport code or name.
 * @return Set of valid itineraries.
 */
set<vector<Flight>> bestFlightAirportToAirport(const string& source, const string& target) {
    Vertex<string>* v1;
    Vertex<string>* v2;
    set<vector<Flight>> validItineraries;
    set<vector<Flight>> validItinerariesFiltered;
    queue<pair<Vertex<string>*, vector<Flight>>> q;
    set<Flight> flightsVisited;
    int minStops = INT_MAX;

    for (const auto& a : airports) {
        if (source == a.get_AirportName() || source == a.get_AirportCode())
            v1 = connections.findVertex(a.get_AirportCode());
        if (target == a.get_AirportName() || target == a.get_AirportCode())
            v2 = connections.findVertex(a.get_AirportCode());
    }

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
        cout << endl;
        cout << "No valid flights found." << endl;
        return validItineraries;
    }

    set<string> diffAirlines;
    for (const auto& itinerary : validItineraries) {
        bool flag1 = true;
        bool flag2 = true;
        for (const auto &f: itinerary) {
            diffAirlines.insert(f.get_Airline());
            if (!airlinesToFilter.empty()) {
                flag1 = !(airlinesToFilter.find(f.get_Airline()) == airlinesToFilter.end());
                if (!flag1)break;
            }
        }
        for (const auto &f: itinerary) {
            if (!airportsToFilter.empty()) {
                flag2 = !((airportsToFilter.find(f.get_Source()) == airportsToFilter.end()) || (airportsToFilter.find(f.get_Target()) == airportsToFilter.end()));
                if (!flag2)break;
            }
        }
        if (flag1 && diffAirlines.size() <= NumAirline && flag2) {
            validItinerariesFiltered.insert(itinerary);
        }
    }
    cout << endl;
    if(validItinerariesFiltered.empty()){
        cout << "There are no available flights according to your filters."<< endl;
        return validItinerariesFiltered;
    }
    else if (validItinerariesFiltered.size() == 1) {
        cout << "There is " << validItinerariesFiltered.size() << " possible best itinerary from " << source << " to " << target << " :" << endl;
    } else { cout << "There are " << validItinerariesFiltered.size() << " possible best itineraries from " << source << " to " << target << " :" << endl;}
    cout << endl;
    cout << "|-------------------|---------|" << endl;
    cout << "| Source -> Destiny | Airline |" << endl;
    cout << "|-------------------|---------|" << endl;
    for(auto flights:validItinerariesFiltered){
        for(auto itinerary:flights){
            cout << "|  " << itinerary.get_Source() << "   ->   " << itinerary.get_Target() << "   |   " << itinerary.get_Airline() << "   |" << endl;
        }
        cout << "|-------------------|---------|" << endl;

    }
    return validItinerariesFiltered;
}

/**
 * @brief Converts degrees to radians.
 * @param degree The angle in degrees.
 * @return The angle in radians.
 */
double toRadians(double degree) {
    return degree * (M_PI / 180.0);
}

/**
 * @brief Calculates the Haversine distance between two sets of coordinates.
 * Complexity: O(1).
 * @param lat1 Latitude of the first location.
 * @param lon1 Longitude of the first location.
 * @param lat2 Latitude of the second location.
 * @param lon2 Longitude of the second location.
 * @return The Haversine distance between the two locations.
 */
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

/**
 * @brief Finds the best flights between two locations and returns a set of valid itineraries.
 * Complexity: O(V + (N * M) * (A + N * log C + (V * F * log C))).
 * @param lon Longitude of the source location.
 * @param lat Latitude of the source location.
 * @param targetLon Longitude of the target location.
 * @param targetLat Latitude of the target location.
 * @return Set of valid itineraries.
 */
vector<set<vector<Flight>>> coordsBestFlight( double lat, double lon, double targetLat,double targetLon){
    double min = INT_MAX;
    vector<Airport> sourcePossible;
    for(const auto& in :airports){
        double temp = haversine(in.get_Latitude(),in.get_Longitude(),lat,lon);
        if(temp < min)min = temp;
    }
    for(const auto& in :airports){
        double temp = haversine(in.get_Latitude(),in.get_Longitude(),lat,lon);
        if(temp == min)sourcePossible.push_back(in);
    }
    min = INT_MAX;
    vector<Airport> destPossible;
    for(const auto& in :airports){
        double temp = haversine(in.get_Latitude(),in.get_Longitude(),targetLat,targetLon);
        if(temp < min)min = temp;
    }
    for(const auto& in :airports){
        double temp = haversine(in.get_Latitude(),in.get_Longitude(),targetLat,targetLon);
        if(temp == min)destPossible.push_back(in);
    }
    vector<set<vector<Flight>>> allPaths;
    for(const auto& in : sourcePossible){
        for(const auto& in1 : destPossible){
            allPaths.emplace_back(bestFlightAirportToAirport(in.get_AirportCode(),in1.get_AirportCode()));
        }
    }
    return allPaths;
}

/**
 * @brief Finds airports in a given city.
 * Complexity: O(V).
 * @param city The name of the city.
 * @return Vector of the airports in the city.
 */
vector<Airport> findAirportsInCity(const string& city) {
    vector<Airport> cityAirports;
    for(const auto& a: airports) {
        if(a.get_City()==city)
            cityAirports.push_back(a);
    }
    return cityAirports;
}

/**
 * @brief Finds the best flights between two cities.
 * Complexity: O(V + (N * M) * (A + N * log C + (V * F * log C))).
 * @param sourceCity The name of the source city.
 * @param targetCity The name of the target city.
 */
void bestFlightCityToCity(const string& sourceCity, const string& targetCity) {
    vector<Airport> sourceAirports = findAirportsInCity(sourceCity);
    vector<Airport> targetAirports = findAirportsInCity(targetCity);

    vector<set<vector<Flight>>> allPaths;

    for(const auto& in : sourceAirports){
        for(const auto& in1 : targetAirports){
            allPaths.emplace_back(bestFlightAirportToAirport(in.get_AirportCode(),in1.get_AirportCode()));
        }
    }
}

/**
 * @brief Finds the best flights from an airport to a city.
 * Complexity: O(V + N * (A + N * log C + (V * F * log C))).
 * @param sourceAirport The code or name of the source airport.
 * @param targetCity The name of the target city.
 */
void bestFlightAirportToCity(const string& sourceAirport, const string& targetCity) {
    string source;
    vector<Airport> targetAirports = findAirportsInCity(targetCity);
    for(const auto& x:airports){
        if(x.get_AirportCode() == sourceAirport || x.get_AirportName() == sourceAirport){
            source = x.get_AirportCode();
            break;
        }
    }
    vector<set<vector<Flight>>> allPaths;
    for(const auto& in1 : targetAirports){
        allPaths.emplace_back(bestFlightAirportToAirport(source,in1.get_AirportCode()));
    }
}

/**
 * @brief Finds the best flights from a city to an airport.
 * Complexity: O(V + N * (A + N * log C + (V * F * log C))).
 * @param sourceCity The name of the source city.
 * @param targetAirport The code or name of the target airport.
 */
void bestFlightCityToAirport(const string& sourceCity, const string& targetAirport) {
    string target;
    vector<Airport> sourceAirports = findAirportsInCity(sourceCity);
    for(const auto& x:airports){
        if(x.get_AirportCode() == targetAirport || x.get_AirportName() == targetAirport){
            target = x.get_AirportCode();
            break;
        }
    }
    vector<set<vector<Flight>>> allPaths;
    for(const auto& in1 : sourceAirports){
        allPaths.emplace_back(bestFlightAirportToAirport(in1.get_AirportCode(),target));
    }
}

/**
 * @brief Finds the best flights from a city to a location.
 * Complexity: O(V + N * (A + N * log C + (V * F * log C))).
 * @param sourceCity The name of the source city.
 * @param lon Longitude of the target location.
 * @param lat Latitude of the target location.
 */
void bestFlightCityToLocation(const string& sourceCity,double lon, double lat) {
    vector<Airport> sourceAirports = findAirportsInCity(sourceCity);
    vector<vector<set<vector<Flight>>>> allPaths;
    for(const auto& in1 : sourceAirports){
        allPaths.emplace_back(coordsBestFlight(in1.get_Latitude(),in1.get_Longitude(),lat,lon));
    }
}

/**
 * @brief Finds the best flights from a location to a city.
 * Complexity: O(V + N * (A + N * log C + (V * F * log C))).
 * @param lon Longitude of the source location.
 * @param lat Latitude of the source location.
 * @param targetCity The name of the target city.
 */
void bestFlightLocationToCity(double lon, double lat,const string& targetCity){
    vector<Airport> targetAirports = findAirportsInCity(targetCity);
    vector<vector<set<vector<Flight>>>> allPaths;
    for(const auto& in1 : targetAirports){
        allPaths.emplace_back(coordsBestFlight(lat,lon,in1.get_Latitude(),in1.get_Longitude()));
    }
}

/**
 * @brief Finds the best flights from a location to an airport.
 * Complexity: O(V + (N * M) * (A + N * log C + (V * F * log C))).
 * @param targetLat Latitude of the target location.
 * @param targetLon Longitude of the target location.
 * @param lon Longitude of the source location.
 * @param lat Latitude of the source location.
 */
void bestFlightLocationToAirport(double targetLat,double targetLon,double lon, double lat){
    vector<vector<set<vector<Flight>>>> allPaths;
    allPaths.emplace_back(coordsBestFlight(lat,lon,targetLat,targetLon));
}

/**
 * @brief Finds the best flights from an airport to a location.
 * Complexity: O(V + (N * M) * (A + N * log C + (V * F * log C)))
 * @param lon Longitude of the source location.
 * @param lat Latitude of the source location.
 * @param targetLon Longitude of the target location.
 * @param targetLat Latitude of the target location.
 */
void bestFlightAirportToLocation(double lon, double lat,double targetLon,double targetLat){
    vector<vector<set<vector<Flight>>>> allPaths;
    allPaths.emplace_back(coordsBestFlight(lat,lon,targetLat,targetLon));

}

/**
 * @brief Filters the number of allowed airlines in the output.
 * @param k The maximum number of different airlines in the output.
 */
void filterNumAirline(int k){
    NumAirline = k;
}

/**
 * @brief Filters the set of airlines for the output.
 * @param airlinesToFilter_ Set of airlines to include in the output.
 */
void filterAirlines(set<string> airlinesToFilter_){
    airlinesToFilter = airlinesToFilter_;
}

/**
 * @brief Filters the set of airports for the output.
 * @param airportsToFilter_ Set of airports to include in the output.
 */
void filterAirports(set<string> airportsToFilter_){
    airportsToFilter = airportsToFilter_;
}

#endif //PROJECT_AIR_DISPLAYS_H