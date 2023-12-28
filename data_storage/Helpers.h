//
// Created by tomas on 27/12/2023.
//

#ifndef PROJECT_AIR_HELPERS_H
#define PROJECT_AIR_HELPERS_H
#include "Displays.h"

string multString(const char *const charr, int repetition) {
    std::string result;
    for (int i = 0; i < repetition; i++) {
        result += charr;
    }
    return result;
}

void displayGroupAirportsHelper(int start, int groupSize) {
    cout << endl;
    cout << "|------------------------------------------------------------|" << endl;
    cout << "| Airports List                                              |" << endl;
    cout << "|------------------------------------------------------------|" << endl;
    // Display the current group of 10 elements
    for (int i = start; i < start + groupSize && i < airports.size(); ++i) {
        string linha = multString(" ", 49 - airports[i].get_AirportCode().size() - airports[i].get_AirportName().size());
        cout << "| Code: " << airports[i].get_AirportCode() << " (" << airports[i].get_AirportName() << ")" << linha << " |" << endl;
        cout << "|------------------------------------------------------------|" << endl;
    }
}
string flightsAirportHelper(){
    list<string> airportCodes;
    for(auto a: airports){airportCodes.push_back(a.get_AirportCode());}
    string airport;
    int start1 = 0;
    int groupSize1 = 10;
    while (start1 < airportCodes.size()) {
        displayGroupAirportsHelper(start1 ,groupSize1);
        cout << endl;
        cout << "Display Tools: Enter 'N' to view the next " << groupSize1 << " airports, 'P' to see the previous "<< groupSize1 <<" or 'R' to return" << endl;
        cout << "Select an airport by code or a tool: ";
        cin >> airport;
        if(find(airportCodes.begin(),airportCodes.end(),airport) != airportCodes.end()) {
            break;
        }
        else if(airport == "N") {
            if(start1 <= airportCodes.size()-10){start1 += groupSize1;}
            else{
                cout << "ERROR: Cannot go further" << endl;
                cout << endl;
            }
        }
        else if(airport == "P") {
            if(start1 >= 10){start1 -= groupSize1;}
            else{
                cout << "ERROR: Cannot go back" << endl;
                cout << endl;
            }
        }
        else if(airport == "R"){
            return "r";
        }
        else {
            cout << "ERROR: Invalid input" << endl;
            cout << endl;
        }
    }
    numberOut(airport);
    return "qwert";
}
void displayGroupCitiesHelper(const vector<string> cities,int start ,int groupSize) {
    cout << endl;
    cout << "|------------------------------------------------------------|" << endl;
    cout << "| Cities List                                                |" << endl;
    cout << "|------------------------------------------------------------|" << endl;
    // Display the current group of 10 elements
    for (int i = start; i < start + groupSize && i < cities.size(); ++i) {
        string linha = multString(" ", 58 - cities[i].size());
        cout << "| " << cities[i] << linha << " |" << endl;
        cout << "|------------------------------------------------------------|" << endl;
    }
}
string flightsPerCityHelper(){
    set<string> cities;
    for(auto a: airports){cities.insert(a.get_City());}
    vector<string> citiess;
    for(auto a:cities)citiess.push_back(a);
    string city;
    int start1 = 0;
    int groupSize1 = 10;
    while (start1 < cities.size()) {
        displayGroupCitiesHelper(citiess,start1 ,groupSize1);
        cout << endl;
        cout << "Display Tools: Enter 'N' to view the next " << groupSize1 << " cities, 'P' to see the previous "<< groupSize1 <<" or 'R' to return" << endl;
        cout << "Select a city or a tool: ";
        cin >> city;
        if(find(cities.begin(),cities.end(),city) != cities.end()) {
            break;
        }
        else if(city == "N") {
            if(start1 <= cities.size()-10){start1 += groupSize1;}
            else{
                cout << "ERROR: Cannot go further" << endl;
                cout << endl;
            }
        }
        else if(city == "P") {
            if(start1 >= 10){start1 -= groupSize1;}
            else{
                cout << "ERROR: Cannot go back" << endl;
                cout << endl;
            }
        }
        else if(city == "R"){
            return "r";
        }
        else {
            cout << "ERROR: Invalid input" << endl;
            cout << endl;
        }
    }
    flightsPerCity(city);
    return "qwert";
}
void displayGroupAirlineHelper(int start ,int groupSize) {
    cout << endl;
    cout << "|------------------------------------------------------------|" << endl;
    cout << "| Airlines List                                              |" << endl;
    cout << "|------------------------------------------------------------|" << endl;
    // Display the current group of 10 elements
    for (int i = start; i < start + groupSize && i < airlines.size(); ++i) {
        string linha = multString(" ", 49 - airlines[i].get_AirlineCode().size() - airlines[i].get_AirlineName().size());
        cout << "| Code: " << airlines[i].get_AirlineCode() << " (" << airlines[i].get_AirlineName() << ")" << linha << " |" << endl;
        cout << "|------------------------------------------------------------|" << endl;
    }
}
string flightsPerAirlineHelper(){
    list<string> airlinesCode;
    for(auto a: airlines){airlinesCode.push_back(a.get_AirlineCode());}
    string airport;
    string airline;
    int start1 = 0;
    int groupSize1 = 10;
    while (start1 < airlines.size()) {
        displayGroupAirlineHelper(start1 ,groupSize1);
        cout << endl;
        cout << "Display Tools: Enter 'N' to view the next " << groupSize1 << " airlines, 'P' to see the previous "<< groupSize1 <<" or 'R' to return" << endl;
        cout << "Select an airline by code or a tool: ";
        cin >> airline;
        if(find(airlinesCode.begin(),airlinesCode.end(),airline) != airlinesCode.end()) {
            break;
        }
        else if(airline == "N") {
            if(start1 <= airlinesCode.size()-10){start1 += groupSize1;}
            else{
                cout << "ERROR: Cannot go further" << endl;
                cout << endl;
            }
        }
        else if(airline == "P") {
            if(start1 >= 10){start1 -= groupSize1;}
            else{
                cout << "ERROR: Cannot go back" << endl;
                cout << endl;
            }
        }
        else if(airline == "R"){
            return "r";
        }
        else {
            cout << "ERROR: Invalid input" << endl;
            cout << endl;
        }
    }
    flightsPerAirline(airline);
    return "qwert";
}
string countriesPerAirportHelper(){
    list<string> airportCodes;
    for(auto a: airports){airportCodes.push_back(a.get_AirportCode());}
    string airport;
    int start1 = 0;
    int groupSize1 = 10;
    while (start1 < airportCodes.size()) {
        displayGroupAirportsHelper(start1 ,groupSize1);
        cout << endl;
        cout << "Display Tools: Enter 'N' to view the next " << groupSize1 << " airports, 'P' to see the previous "<< groupSize1 <<" or 'R' to return" << endl;
        cout << "Select an airport by code or a tool: ";
        cin >> airport;
        if(find(airportCodes.begin(),airportCodes.end(),airport) != airportCodes.end()) {
            break;
        }
        else if(airport == "N") {
            if(start1 <= airportCodes.size()-10){start1 += groupSize1;}
            else{
                cout << "ERROR: Cannot go further" << endl;
                cout << endl;
            }
        }
        else if(airport == "P") {
            if(start1 >= 10){start1 -= groupSize1;}
            else{
                cout << "ERROR: Cannot go back" << endl;
                cout << endl;
            }
        }
        else if(airport == "R"){
            return "r";
        }
        else {
            cout << "ERROR: Invalid input" << endl;
            cout << endl;
        }
    }
    countriesPerAirport(airport);
    return "qwert";
}
string countriesPerCityHelper(){
    set<string> cities;
    for(auto a: airports){cities.insert(a.get_City());}
    vector<string> citiess;
    for(auto a:cities)citiess.push_back(a);
    string city;
    int start1 = 0;
    int groupSize1 = 10;
    while (start1 < cities.size()) {
        displayGroupCitiesHelper(citiess,start1 ,groupSize1);
        cout << endl;
        cout << "Display Tools: Enter 'N' to view the next " << groupSize1 << " cities, 'P' to see the previous "<< groupSize1 <<" or 'R' to return" << endl;
        cout << "Select an city or a tool: ";
        cin >> city;
        if(find(cities.begin(),cities.end(),city) != cities.end()) {
            break;
        }
        else if(city == "N") {
            if(start1 <= cities.size()-10){start1 += groupSize1;}
            else{
                cout << "ERROR: Cannot go further" << endl;
                cout << endl;
            }
        }
        else if(city == "P") {
            if(start1 >= 10){start1 -= groupSize1;}
            else{
                cout << "ERROR: Cannot go back" << endl;
                cout << endl;
            }
        }
        else if(city == "R"){
            return "r";
        }
        else {
            cout << "ERROR: Invalid input" << endl;
            cout << endl;
        }
    }
    countriesPerCity(city);
    return "qwert";
}
string destinationsPerAirportHelper(){
    list<string> airportCodes;
    for(auto a: airports){airportCodes.push_back(a.get_AirportCode());}
    string airport;
    int start1 = 0;
    int groupSize1 = 10;
    while (start1 < airportCodes.size()) {
        displayGroupAirportsHelper(start1 ,groupSize1);
        cout << endl;
        cout << "Display Tools: Enter 'N' to view the next " << groupSize1 << " airports, 'P' to see the previous "<< groupSize1 <<" or 'R' to return" << endl;
        cout << "Select an airport by code or a tool: ";
        cin >> airport;
        if(find(airportCodes.begin(),airportCodes.end(),airport) != airportCodes.end()) {
            break;
        }
        else if(airport == "N") {
            if(start1 <= airportCodes.size()-10){start1 += groupSize1;}
            else{
                cout << "ERROR: Cannot go further" << endl;
                cout << endl;
            }
        }
        else if(airport == "P") {
            if(start1 >= 10){start1 -= groupSize1;}
            else{
                cout << "ERROR: Cannot go back" << endl;
                cout << endl;
            }
        }
        else if(airport == "R"){
            return "r";
        }
        else {
            cout << "ERROR: Invalid input" << endl;
            cout << endl;
        }
    }
    numAirportsDest(airport);
    numCitiesDest(airport);
    numCountriesDest(airport);
    return "qwert";
}
string reachableDestinationsHelper(int stops){
    list<string> airportCodes;
    for(auto a: airports){airportCodes.push_back(a.get_AirportCode());}
    string airport;
    int start1 = 0;
    int groupSize1 = 10;
    while (start1 < airportCodes.size()) {
        displayGroupAirportsHelper(start1 ,groupSize1);
        cout << endl;
        cout << "Display Tools: Enter 'N' to view the next " << groupSize1 << " airports, 'P' to see the previous "<< groupSize1 <<" or 'R' to return" << endl;
        cout << "Select an airport by code or a tool: ";
        cin >> airport;
        if(find(airportCodes.begin(),airportCodes.end(),airport) != airportCodes.end()) {
            break;
        }
        else if(airport == "N") {
            if(start1 <= airportCodes.size()-10){start1 += groupSize1;}
            else{
                cout << "ERROR: Cannot go further" << endl;
                cout << endl;
            }
        }
        else if(airport == "P") {
            if(start1 >= 10){start1 -= groupSize1;}
            else{
                cout << "ERROR: Cannot go back" << endl;
                cout << endl;
            }
        }
        else if(airport == "R"){
            return "r";
        }
        else {
            cout << "ERROR: Invalid input" << endl;
            cout << endl;
        }
    }
    numAirportsDestAtDistance(airport,stops);
    numCitiesDestAtDistance(airport,stops);
    countriesPerAirportAtDistance(airport,stops);
    return "qwert";
}
string bestFlightAirportToAirportHelper(){
    list<string> airportCodes;
    for(auto a: airports){airportCodes.push_back(a.get_AirportCode());}
    string source;
    string destiny;
    int start1 = 0;
    int groupSize1 = 10;
    while (start1 < airportCodes.size()) {
        displayGroupAirportsHelper(start1 ,groupSize1);
        cout << endl;
        cout << "Display Tools: Enter 'N' to view the next " << groupSize1 << " airports, 'P' to see the previous "<< groupSize1 <<" or 'R' to return" << endl;
        cout << "Select a source by code or name or a tool: ";
        getline(cin,source);
        Vertex<string>* v1 = findAirportVertex(source);
        if (v1) {
            start1 = 0;
            while(start1 < airportCodes.size()) {
                displayGroupAirportsHelper(start1, groupSize1);
                cout << endl;
                cout << "Display Tools: Enter 'N' to view the next " << groupSize1
                     << " airports, 'P' to see the previous " << groupSize1 << " or 'R' to return" << endl;
                cout << "Now select a destiny by code or name or a tool: ";
                getline(cin,destiny);
                Vertex<string> *v2 = findAirportVertex(destiny);
                if (v2) {
                    cout << endl;
                    bestFlightAirportToAirport(source, destiny);
                    return "qwert";
                }
                else if (destiny == "N") {
                    if (start1 <= airportCodes.size() - 10) { start1 += groupSize1; }
                    else {
                        cout << "ERROR: Cannot go further" << endl;
                        cout << endl;
                    }
                }
                else if (destiny == "P") {
                    if (start1 >= 10) { start1 -= groupSize1; }
                    else {
                        cout << "ERROR: Cannot go back" << endl;
                        cout << endl;
                    }
                } else if (destiny == "R") {
                    return "r";
                } else {
                    cout << "ERROR: Invalid input" << endl;
                    cout << endl;
                }
            }
        }
        else if(source == "N") {
            if(start1 <= airportCodes.size()-10){start1 += groupSize1;}
            else{
                cout << "ERROR: Cannot go further" << endl;
                cout << endl;
            }
        }
        else if(source == "P") {
            if(start1 >= 10){start1 -= groupSize1;}
            else{
                cout << "ERROR: Cannot go back" << endl;
                cout << endl;
            }
        }
        else if(source == "R"){
            return "r";
        }
        else {
            cout << "ERROR: Invalid input" << endl;
            cout << endl;
        }
    }
}
string bestFlightCityToCityHelper(){/*
    set<string> cities;
    for(auto a: airports){cities.insert(a.get_City());}
    vector<string> citiess;
    for(auto a:cities)citiess.push_back(a);
    string source;
    string destiny;
    int start1 = 0;
    int groupSize1 = 10;
    while (start1 < cities.size()) {
        displayGroupCitiesHelper(citiess,start1 ,groupSize1);
        cout << endl;
        cout << "Display Tools: Enter 'N' to view the next " << groupSize1 << " cities, 'P' to see the previous "<< groupSize1 <<" or 'R' to return" << endl;
        cout << "Select a source or a tool: ";
        cin >> source;
        Vertex<string>* v1 = findAirportVertex(source);
        if (v1) {
            start1 = 0;
            while(start1 < airportCodes.size()) {
                displayGroupCitiesHelper(citiess,start1, groupSize1);
                cout << endl;
                cout << "Display Tools: Enter 'N' to view the next " << groupSize1
                     << " cities, 'P' to see the previous " << groupSize1 << " or 'R' to return" << endl;
                cout << "Now select a destiny or a tool: ";
                cin >> destiny;
                Vertex<string> *v2 = findAirportVertex(destiny);
                if (v2) { bestFlightAirportToAirport(source, destiny); }
                else if (source == "N") {
                    if (start1 <= airportCodes.size() - 10) { start1 += groupSize1; }
                    else {
                        cout << "ERROR: Cannot go further" << endl;
                        cout << endl;
                    }
                }
                else if (source == "P") {
                    if (start1 >= 10) { start1 -= groupSize1; }
                    else {
                        cout << "ERROR: Cannot go back" << endl;
                        cout << endl;
                    }
                } else if (source == "R") {
                    return "r";
                } else {
                    cout << "ERROR: Invalid input" << endl;
                    cout << endl;
                }
            }
        }
        else if(source == "N") {
            if(start1 <= airportCodes.size()-10){start1 += groupSize1;}
            else{
                cout << "ERROR: Cannot go further" << endl;
                cout << endl;
            }
        }
        else if(source == "P") {
            if(start1 >= 10){start1 -= groupSize1;}
            else{
                cout << "ERROR: Cannot go back" << endl;
                cout << endl;
            }
        }
        else if(source == "R"){
            return "r";
        }
        else {
            cout << "ERROR: Invalid input" << endl;
            cout << endl;
        }
    }
    return "qwert";
    */
}



#endif //PROJECT_AIR_HELPERS_H
