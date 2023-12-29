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
void displayGroupCountriesHelper(int start, int groupSize) {
    vector<string> countries;
    for(auto a:Countries){countries.push_back(a.first);}
    cout << endl;
    cout << "|------------------------------------------------------------|" << endl;
    cout << "| Countries List                                             |" << endl;
    cout << "|------------------------------------------------------------|" << endl;
    // Display the current group of 10 elements
    for (int i = start; i < start + groupSize && i < airports.size(); ++i) {
        string linha = multString(" ", 58 - countries[i].size());
        cout << "| " << countries[i] << linha << " |" << endl;
        cout << "|------------------------------------------------------------|" << endl;
    }
}
void displayGroupAirportsHelper(vector<Airport> cityAirports,int start, int groupSize) {
    cout << endl;
    cout << "|------------------------------------------------------------|" << endl;
    cout << "| Available airports List                                    |" << endl;
    cout << "|------------------------------------------------------------|" << endl;
    // Display the current group of 10 elements
    for (int i = start; i < start + groupSize && i < cityAirports.size(); ++i) {
        string linha = multString(" ", 49 - cityAirports[i].get_AirportCode().size() - cityAirports[i].get_AirportName().size());
        cout << "| Code: " << cityAirports[i].get_AirportCode() << " (" << cityAirports[i].get_AirportName() << ")" << linha << " |" << endl;
        cout << "|------------------------------------------------------------|" << endl;
    }
}
void displayGroupCitiesHelper(string country,int start ,int groupSize) {
    vector<string> cities;
    for(auto a:Countries){
        if(a.first == country){
            for(auto x: a.second)cities.push_back(x);
        }
    }
    string linha = multString(" ", 46 - country.size());
    cout << endl;
    cout << "|------------------------------------------------------------|" << endl;
    cout << "| Cities from " << country << linha << " |" << endl;
    cout << "|------------------------------------------------------------|" << endl;
    // Display the current group of 10 elements
    for (int i = start; i < start + groupSize && i < cities.size(); ++i) {
        linha = multString(" ", 58 - cities[i].size());
        cout << "| " << cities[i] << linha << " |" << endl;
        cout << "|------------------------------------------------------------|" << endl;
    }
}
void displayGroupAirlineHelper(vector<Airline> airlinePerCountry,int start ,int groupSize) {
    string linha = multString(" ",34 - airlinePerCountry[0].get_Country().size());
    cout << endl;
    cout << "|------------------------------------------------------------|" << endl;
    cout << "| Available airlines from " << airlinePerCountry[0].get_Country() << linha << " |" << endl;
    cout << "|------------------------------------------------------------|" << endl;
    // Display the current group of 10 elements
    for (int i = start; i < start + groupSize && i < airlinePerCountry.size(); ++i) {
        linha = multString(" ", 49 - airlinePerCountry[i].get_AirlineCode().size() - airlinePerCountry[i].get_AirlineName().size());
        cout << "| Code: " << airlinePerCountry[i].get_AirlineCode() << " (" << airlinePerCountry[i].get_AirlineName() << ")" << linha << " |" << endl;
        cout << "|------------------------------------------------------------|" << endl;
    }
}

string flightsAirportHelper(){
    string country;
    string city;
    string airport;
    int startCountry = 0;
    int startCity = 0;
    int startAirport = 0;
    int groupSize1 = 10;
    while (startCountry < Countries.size()) {
        displayGroupCountriesHelper(startCountry,groupSize1);
        cout << endl;
        cout << "Display Tools: Enter 'N' to view the next " << groupSize1 << " countries, 'P' to see the previous "<< groupSize1 <<" or 'R' to return" << endl;
        cout << "Select a country or a tool: ";
        getline(cin >> ws,country);
        auto it = Countries.find(country);
        if(it != Countries.end()) {
            while(startCity < Countries[country].size()){
                displayGroupCitiesHelper(country,startCity,groupSize1);
                cout << endl;
                cout << "Display Tools: Enter 'N' to view the next " << groupSize1 << " cities, 'P' to see the previous "<< groupSize1 <<" or 'R' to return" << endl;
                cout << "Select a city or a tool: ";
                getline(cin >> ws,city);
                if(find(Countries[country].begin(),Countries[country].end(),city) != Countries[country].end()){
                    vector<string> cityAirportCodes;
                    vector<Airport> cityAirports;
                    for(const auto& a: airports){
                        if(a.get_Country() == country && a.get_City() == city){cityAirports.push_back(a);cityAirportCodes.push_back(a.get_AirportCode());}
                    }
                    while(startAirport < cityAirports.size()){
                        displayGroupAirportsHelper(cityAirports,startAirport,groupSize1);
                        cout << endl;
                        cout << "Display Tools: Enter 'N' to view the next " << groupSize1 << " airports, 'P' to see the previous "<< groupSize1 <<" or 'R' to return" << endl;
                        cout << "Select a airport by code or a tool: ";
                        getline(cin >> ws,airport);
                        if(find(cityAirportCodes.begin(),cityAirportCodes.end(),airport) != cityAirportCodes.end()){
                            numberOut(airport);
                            return "qwert";
                        }
                        else if(airport == "N") {
                            if(startAirport <= cityAirportCodes.size()-10 && (startAirport+groupSize1)<cityAirportCodes.size()){
                                startAirport += groupSize1;
                            }
                            else{
                                cout << endl;
                                cout << "ERROR: Cannot go further" << endl;
                            }
                        }
                        else if(airport == "P") {
                            if(startAirport >= 10){startAirport -= groupSize1;}
                            else{
                                cout << endl;
                                cout << "ERROR: Cannot go back" << endl;
                            }
                        }
                        else if(airport == "R"){
                            return "r";
                        }
                        else {
                            cout << endl;
                            cout << "ERROR: Invalid input" << endl;
                        }
                    }
                }
                else if(city == "N") {
                    if(startCity <= Countries[country].size()-10 && (startCity+groupSize1)<Countries[country].size()){
                        startCity += groupSize1;
                    }
                    else{
                        cout << endl;
                        cout << "ERROR: Cannot go further" << endl;
                    }
                }
                else if(city == "P") {
                    if(startCity >= 10){startCity -= groupSize1;}
                    else{
                        cout << endl;
                        cout << "ERROR: Cannot go back" << endl;
                    }
                }
                else if(city == "R"){
                    return "r";
                }
                else {
                    cout << endl;
                    cout << "ERROR: Invalid input" << endl;
                }
            }
        }
        else if(country == "N") {
            if(startCountry <= Countries.size()-10 && (startCountry+groupSize1)<Countries.size()) {
                startCountry += groupSize1;
            }
            else{
                cout << endl;
                cout << "ERROR: Cannot go further" << endl;
            }
        }
        else if(country == "P") {
            if(startCountry >= 10){startCountry -= groupSize1;}
            else{
                cout << endl;
                cout << "ERROR: Cannot go back" << endl;
            }
        }
        else if(country == "R"){
            return "r";
        }
        else {
            cout << endl;
            cout << "ERROR: Invalid input" << endl;
        }
    }
}  //1 2

string flightsPerCityHelper(){
    string country;
    string city;
    int start1 = 0;
    int groupSize1 = 10;
    while (start1 < Countries.size()) {
        displayGroupCountriesHelper(start1,groupSize1);
        cout << endl;
        cout << "Display Tools: Enter 'N' to view the next " << groupSize1 << " countries, 'P' to see the previous "<< groupSize1 <<" or 'R' to return" << endl;
        cout << "Select a country or a tool: ";
        getline(cin >> ws,country);
        auto it = Countries.find(country);
        if(it != Countries.end()) {
            start1 = 0;
            while(start1 < Countries[country].size()) {
                displayGroupCitiesHelper(country, start1, groupSize1);
                cout << endl;
                cout << "Display Tools: Enter 'N' to view the next " << groupSize1 << " cities, 'P' to see the previous " << groupSize1 << " or 'R' to return" << endl;
                cout << "Select a city or a tool: ";
                getline(cin >> ws,city);
                if (find(Countries[country].begin(), Countries[country].end(), city) != Countries[country].end()) {
                    if(flightsPerCity(city) == 1) {
                        cout << endl << "There is " << flightsPerCity(city) << " flight from " << city << endl;
                    }
                    else{cout << endl << "There are " << flightsPerCity(city) << " flights from " << city << endl;}
                    return "qwert";
                }
                else if (city == "N") {
                    if (start1 <= Countries[country].size() - 10 && (start1+groupSize1)<Countries[country].size()) { start1 += groupSize1; }
                    else {
                        cout << endl;
                        cout << "ERROR: Cannot go further" << endl;
                    }
                }
                else if (city == "P") {
                    if (start1 >= 10) { start1 -= groupSize1; }
                    else {
                        cout << endl;
                        cout << "ERROR: Cannot go back" << endl;
                    }
                }
                else if (city == "R") {
                    return "r";
                }
                else {
                    cout << endl;
                    cout << "ERROR: Invalid input" << endl;
                }
            }
        }
        else if(country == "N") {
            if(start1 <= Countries.size()-10 && (start1+groupSize1)<Countries.size()){start1 += groupSize1;}
            else{
                cout << endl;
                cout << "ERROR: Cannot go further" << endl;
            }
        }
        else if(country == "P") {
            if(start1 >= 10){start1 -= groupSize1;}
            else{
                cout << endl;
                cout << "ERROR: Cannot go back" << endl;
            }
        }
        else if(country == "R"){
            return "r";
        }
        else {
            cout << endl;
            cout << "ERROR: Invalid input" << endl;
        }
    }
}  //1 3

string flightsPerAirlineHelper(){
    string country;
    string airline;
    int start1 = 0;
    int groupSize1 = 10;
    while (start1 < Countries.size()) {
        displayGroupCountriesHelper(start1,groupSize1);
        cout << endl;
        cout << "Display Tools: Enter 'N' to view the next " << groupSize1 << " countries, 'P' to see the previous "<< groupSize1 <<" or 'R' to return" << endl;
        cout << "Select a country or a tool: ";
        getline(cin >> ws,country);
        auto it = Countries.find(country);
        if(it != Countries.end()){
            vector<string>airliness;
            vector<Airline> airlinePerCountry;
            for(auto airlinee:airlines){
                if(airlinee.get_Country() == country){
                    airlinePerCountry.push_back(airlinee);
                    airliness.push_back(airlinee.get_AirlineCode());
                    airliness.push_back(airlinee.get_AirlineName());
                }
            }
            start1 = 0;
            while(start1 < airlinePerCountry.size()){
                displayGroupAirlineHelper(airlinePerCountry,start1 ,groupSize1);
                cout << endl;
                cout << "Display Tools: Enter 'N' to view the next " << groupSize1 << " airlines, 'P' to see the previous "<< groupSize1 <<" or 'R' to return" << endl;
                cout << "Select an airline by code or name or a tool: ";
                getline(cin >> ws, airline);
                if(find(airliness.begin(),airliness.end(),airline) != airliness.end()) {
                    if(flightsPerAirline(airline) == 1){
                        cout << endl << "There is " << flightsPerAirline(airline) << " flight from the airline " << airline << endl;
                    }
                    else{cout << endl << "There are " << flightsPerAirline(airline) << " flights from the airline " << airline << endl;}
                    return "qwert";
                }
                else if(airline == "N") {
                    if(start1 <= airliness.size()/2 - 10 && (start1+groupSize1)<airliness.size()/2){start1 += groupSize1;}
                    else{
                        cout << endl;
                        cout << "ERROR: Cannot go further" << endl;
                    }
                }
                else if(airline == "P") {
                    if(start1 >= 10){start1 -= groupSize1;}
                    else{
                        cout << endl;
                        cout << "ERROR: Cannot go back" << endl;
                    }
                }
                else if(airline == "R"){
                    return "r";
                }
                else {
                    cout << endl;
                    cout << "ERROR: Invalid input" << endl;
                }
            }
        }
        else if(country == "N") {
            if(start1 <= Countries.size()-10 && (start1+groupSize1)<Countries.size()){start1 += groupSize1;}
            else{
                cout << endl;
                cout << "ERROR: Cannot go further" << endl;
            }
        }
        else if(country == "P") {
            if(start1 >= 10){start1 -= groupSize1;}
            else{
                cout << endl;
                cout << "ERROR: Cannot go back" << endl;
            }
        }
        else if(country == "R"){
            return "r";
        }
        else {
            cout << endl;
            cout << "ERROR: Invalid input" << endl;
        }
    }
}  //1 3

string countriesPerAirportHelper(){
    string country;
    string city;
    string airport;
    int startCountry = 0;
    int startCity = 0;
    int startAirport = 0;
    int groupSize1 = 10;

    while (startCountry < Countries.size()) {
        displayGroupCountriesHelper(startCountry,groupSize1);
        cout << endl;
        cout << "Display Tools: Enter 'N' to view the next " << groupSize1 << " countries, 'P' to see the previous "<< groupSize1 <<" or 'R' to return" << endl;
        cout << "Select a country or a tool: ";
        getline(cin >> ws,country);
        auto it = Countries.find(country);
        if(it != Countries.end()) {
            while(startCity < Countries[country].size()){
                displayGroupCitiesHelper(country,startCity,groupSize1);
                cout << endl;
                cout << "Display Tools: Enter 'N' to view the next " << groupSize1 << " cities, 'P' to see the previous "<< groupSize1 <<" or 'R' to return" << endl;
                cout << "Select a city or a tool: ";
                getline(cin >> ws,city);
                if(find(Countries[country].begin(),Countries[country].end(),city) != Countries[country].end()){
                    vector<string> cityAirportCodes;
                    vector<Airport> cityAirports;
                    for(const auto& a: airports){
                        if(a.get_Country() == country && a.get_City() == city){cityAirports.push_back(a);cityAirportCodes.push_back(a.get_AirportCode());}
                    }
                    while(startAirport < cityAirports.size()){
                        displayGroupAirportsHelper(cityAirports,startAirport,groupSize1);
                        cout << endl;
                        cout << "Display Tools: Enter 'N' to view the next " << groupSize1 << " airports, 'P' to see the previous "<< groupSize1 <<" or 'R' to return" << endl;
                        cout << "Select a airport by code or a tool: ";
                        getline(cin >> ws,airport);
                        if(find(cityAirportCodes.begin(),cityAirportCodes.end(),airport) != cityAirportCodes.end()){
                            if(countriesPerAirport(airport) == 1){
                                cout << endl << "There is " << countriesPerAirport(airport) << " reachable country from the airport " << airport << endl;
                            }
                            else{cout << endl << "There are " << countriesPerAirport(airport) << " reachable countries from the airport " << airport << endl;}
                            return "qwert";
                        }
                        else if(airport == "N") {
                            if(startAirport <= cityAirportCodes.size()-10 && (startAirport+groupSize1)<cityAirportCodes.size()){
                                startAirport += groupSize1;
                            }
                            else{
                                cout << endl;
                                cout << "ERROR: Cannot go further" << endl;
                            }
                        }
                        else if(airport == "P") {
                            if(startAirport >= 10){startAirport -= groupSize1;}
                            else{
                                cout << endl;
                                cout << "ERROR: Cannot go back" << endl;
                            }
                        }
                        else if(airport == "R"){
                            return "r";
                        }
                        else {
                            cout << endl;
                            cout << "ERROR: Invalid input" << endl;
                        }
                    }
                }
                else if(city == "N") {
                    if(startCity <= Countries[country].size()-10 && (startCity+groupSize1)<Countries[country].size()){
                        startCity += groupSize1;
                    }
                    else{
                        cout << endl;
                        cout << "ERROR: Cannot go further" << endl;
                    }
                }
                else if(city == "P") {
                    if(startCity >= 10){startCity -= groupSize1;}
                    else{
                        cout << endl;
                        cout << "ERROR: Cannot go back" << endl;
                    }
                }
                else if(city == "R"){
                    return "r";
                }
                else {
                    cout << endl;
                    cout << "ERROR: Invalid input" << endl;
                }
            }
        }
        else if(country == "N") {
            if(startCountry <= Countries.size()-10 && (startCountry+groupSize1)<Countries.size()) {
                startCountry += groupSize1;
            }
            else{
                cout << endl;
                cout << "ERROR: Cannot go further" << endl;
            }
        }
        else if(country == "P") {
            if(startCountry >= 10){startCountry -= groupSize1;}
            else{
                cout << endl;
                cout << "ERROR: Cannot go back" << endl;
            }
        }
        else if(country == "R"){
            return "r";
        }
        else {
            cout << endl;
            cout << "ERROR: Invalid input" << endl;
        }
    }
} //1 4

string countriesPerCityHelper(){
    string country;
    string city;
    int startCountry = 0;
    int startCity = 0;
    int groupSize1 = 10;

    while (startCountry < Countries.size()) {
        displayGroupCountriesHelper(startCountry,groupSize1);
        cout << endl;
        cout << "Display Tools: Enter 'N' to view the next " << groupSize1 << " countries, 'P' to see the previous "<< groupSize1 <<" or 'R' to return" << endl;
        cout << "Select a country or a tool: ";
        getline(cin >> ws,country);
        auto it = Countries.find(country);
        if(it != Countries.end()) {
            while(startCity < Countries[country].size()){
                displayGroupCitiesHelper(country,startCity,groupSize1);
                cout << endl;
                cout << "Display Tools: Enter 'N' to view the next " << groupSize1 << " cities, 'P' to see the previous "<< groupSize1 <<" or 'R' to return" << endl;
                cout << "Select a city or a tool: ";
                getline(cin >> ws,city);
                if(find(Countries[country].begin(),Countries[country].end(),city) != Countries[country].end()){
                    if(countriesPerCity(country,city) == 1){
                        cout << endl << "There is " << countriesPerCity(country,city) << " reachable country from the city " << city << endl;
                    }
                    else{cout << endl << "There are " << countriesPerCity(country,city) << " reachable countries from the city " << city << endl;}
                    return "qwert";
                }
                else if(city == "N") {
                    if(startCity <= Countries[country].size()-10 && (startCity+groupSize1)<Countries[country].size()){
                        startCity += groupSize1;
                    }
                    else{
                        cout << endl;
                        cout << "ERROR: Cannot go further" << endl;
                    }
                }
                else if(city == "P") {
                    if(startCity >= 10){startCity -= groupSize1;}
                    else{
                        cout << endl;
                        cout << "ERROR: Cannot go back" << endl;
                    }
                }
                else if(city == "R"){
                    return "r";
                }
                else {
                    cout << endl;
                    cout << "ERROR: Invalid input" << endl;
                }
            }
        }
        else if(country == "N") {
            if(startCountry <= Countries.size()-10 && (startCountry+groupSize1)<Countries.size()) {
                startCountry += groupSize1;
            }
            else{
                cout << endl;
                cout << "ERROR: Cannot go further" << endl;
            }
        }
        else if(country == "P") {
            if(startCountry >= 10){startCountry -= groupSize1;}
            else{
                cout << endl;
                cout << "ERROR: Cannot go back" << endl;
            }
        }
        else if(country == "R"){
            return "r";
        }
        else {
            cout << endl;
            cout << "ERROR: Invalid input" << endl;
        }
    }
}  //1 4

string destinationsPerAirportHelper(){
    string country;
    string city;
    string airport;
    int startCountry = 0;
    int startCity = 0;
    int startAirport = 0;
    int groupSize1 = 10;
    while (startCountry < Countries.size()) {
        displayGroupCountriesHelper(startCountry,groupSize1);
        cout << endl;
        cout << "Display Tools: Enter 'N' to view the next " << groupSize1 << " countries, 'P' to see the previous "<< groupSize1 <<" or 'R' to return" << endl;
        cout << "Select a country or a tool: ";
        getline(cin >> ws,country);
        auto it = Countries.find(country);
        if(it != Countries.end()) {
            while(startCity < Countries[country].size()){
                displayGroupCitiesHelper(country,startCity,groupSize1);
                cout << endl;
                cout << "Display Tools: Enter 'N' to view the next " << groupSize1 << " cities, 'P' to see the previous "<< groupSize1 <<" or 'R' to return" << endl;
                cout << "Select a city or a tool: ";
                getline(cin >> ws,city);
                if(find(Countries[country].begin(),Countries[country].end(),city) != Countries[country].end()){
                    vector<string> cityAirportCodes;
                    vector<Airport> cityAirports;
                    for(const auto& a: airports){
                        if(a.get_Country() == country && a.get_City() == city){cityAirports.push_back(a);cityAirportCodes.push_back(a.get_AirportCode());}
                    }
                    while(startAirport < cityAirports.size()){
                        displayGroupAirportsHelper(cityAirports,startAirport,groupSize1);
                        cout << endl;
                        cout << "Display Tools: Enter 'N' to view the next " << groupSize1 << " airports, 'P' to see the previous "<< groupSize1 <<" or 'R' to return" << endl;
                        cout << "Select a airport by code or a tool: ";
                        getline(cin >> ws,airport);
                        if(find(cityAirportCodes.begin(),cityAirportCodes.end(),airport) != cityAirportCodes.end()){
                            cout << endl;
                            if(numAirportsDest(airport) == 1){
                                cout << "There is " << numAirportsDest(airport) << " airport as destination from the airport " << airport << endl;
                            }
                            else{cout << "There are " << numAirportsDest(airport) << " different airports as destination from the airport " << airport << endl;}
                            if(numCitiesDest(airport) == 1){
                                cout << "There is " << numCitiesDest(airport) << "  city as destination from the airport " << airport << endl;
                            }
                            else{cout << "There are " << numCitiesDest(airport) << " different cities as destination from the airport " << airport << endl;}
                            if(numCountriesDest(airport) == 1){
                                cout << "There is " << numCountriesDest(airport) << " country as destination from the airport " << airport << endl;
                            }
                            else{cout << "There are " << numCountriesDest(airport) << " different countries as destination from the airport " << airport << endl;}
                            return "qwert";
                        }
                        else if(airport == "N") {
                            if(startAirport <= cityAirportCodes.size()-10 && (startAirport+groupSize1)<cityAirportCodes.size()){
                                startAirport += groupSize1;
                            }
                            else{
                                cout << endl;
                                cout << "ERROR: Cannot go further" << endl;
                            }
                        }
                        else if(airport == "P") {
                            if(startAirport >= 10){startAirport -= groupSize1;}
                            else{
                                cout << endl;
                                cout << "ERROR: Cannot go back" << endl;
                            }
                        }
                        else if(airport == "R"){
                            return "r";
                        }
                        else {
                            cout << endl;
                            cout << "ERROR: Invalid input" << endl;
                        }
                    }
                }
                else if(city == "N") {
                    if(startCity <= Countries[country].size()-10 && (startCity+groupSize1)<Countries[country].size()){
                        startCity += groupSize1;
                    }
                    else{
                        cout << endl;
                        cout << "ERROR: Cannot go further" << endl;
                    }
                }
                else if(city == "P") {
                    if(startCity >= 10){startCity -= groupSize1;}
                    else{
                        cout << endl;
                        cout << "ERROR: Cannot go back" << endl;
                    }
                }
                else if(city == "R"){
                    return "r";
                }
                else {
                    cout << endl;
                    cout << "ERROR: Invalid input" << endl;
                }
            }
        }
        else if(country == "N") {
            if(startCountry <= Countries.size()-10 && (startCountry+groupSize1)<Countries.size()) {
                startCountry += groupSize1;
            }
            else{
                cout << endl;
                cout << "ERROR: Cannot go further" << endl;
            }
        }
        else if(country == "P") {
            if(startCountry >= 10){startCountry -= groupSize1;}
            else{
                cout << endl;
                cout << "ERROR: Cannot go back" << endl;
            }
        }
        else if(country == "R"){
            return "r";
        }
        else {
            cout << endl;
            cout << "ERROR: Invalid input" << endl;
        }
    }
}  //1 5

string reachableDestinationsHelper(int stops){
    string country;
    string city;
    string airport;
    int startCountry = 0;
    int startCity = 0;
    int startAirport = 0;
    int groupSize1 = 10;

    while (startCountry < Countries.size()) {
        displayGroupCountriesHelper(startCountry,groupSize1);
        cout << endl;
        cout << "Display Tools: Enter 'N' to view the next " << groupSize1 << " countries, 'P' to see the previous "<< groupSize1 <<" or 'R' to return" << endl;
        cout << "Select a country or a tool: ";
        getline(cin >> ws,country);
        auto it = Countries.find(country);
        if(it != Countries.end()) {
            while(startCity < Countries[country].size()){
                displayGroupCitiesHelper(country,startCity,groupSize1);
                cout << endl;
                cout << "Display Tools: Enter 'N' to view the next " << groupSize1 << " cities, 'P' to see the previous "<< groupSize1 <<" or 'R' to return" << endl;
                cout << "Select a city or a tool: ";
                getline(cin >> ws,city);
                if(find(Countries[country].begin(),Countries[country].end(),city) != Countries[country].end()){
                    vector<string> cityAirportCodes;
                    vector<Airport> cityAirports;
                    for(const auto& a: airports){
                        if(a.get_Country() == country && a.get_City() == city){cityAirports.push_back(a);cityAirportCodes.push_back(a.get_AirportCode());}
                    }
                    while(startAirport < cityAirports.size()){
                        displayGroupAirportsHelper(cityAirports,startAirport,groupSize1);
                        cout << endl;
                        cout << "Display Tools: Enter 'N' to view the next " << groupSize1 << " airports, 'P' to see the previous "<< groupSize1 <<" or 'R' to return" << endl;
                        cout << "Select a airport by code or a tool: ";
                        getline(cin >> ws,airport);
                        if(find(cityAirportCodes.begin(),cityAirportCodes.end(),airport) != cityAirportCodes.end()){
                            cout << endl;
                            if(numAirportsDestAtDistance(airport,stops) == 1){
                                cout << "There is " << numAirportsDestAtDistance(airport,stops) << " reachable airport from the airport " << airport << " with " << stops << " stops." << endl;
                            }
                            else{cout << "There are " << numAirportsDestAtDistance(airport,stops) << " reachable airports from the airport " << airport << " with " << stops << " stops." << endl;}
                            if(numCitiesDestAtDistance(airport,stops) == 1){
                                cout << "There is " << numCitiesDestAtDistance(airport,stops) << " reachable city from the airport " << airport << " with " << stops << " stops." << endl;
                            }
                            else{cout << "There are " << numCitiesDestAtDistance(airport,stops) << " reachable cities from the airport " << airport << " with " << stops << " stops." << endl;}
                            if(countriesPerAirportAtDistance(airport,stops) == 1){
                                cout << "There is " << countriesPerAirportAtDistance(airport,stops) << " reachable country from the airport " << airport << " with " << stops << " stops." << endl;
                            }
                            else{cout << "There are " << countriesPerAirportAtDistance(airport,stops) << " reachable countries from the airport " << airport << " with " << stops << " stops." << endl;}
                            return "qwert";
                        }
                        else if(airport == "N") {
                            if(startAirport <= cityAirportCodes.size()-10 && (startAirport+groupSize1)<cityAirportCodes.size()){
                                startAirport += groupSize1;
                            }
                            else{
                                cout << endl;
                                cout << "ERROR: Cannot go further" << endl;
                            }
                        }
                        else if(airport == "P") {
                            if(startAirport >= 10){startAirport -= groupSize1;}
                            else{
                                cout << endl;
                                cout << "ERROR: Cannot go back" << endl;
                            }
                        }
                        else if(airport == "R"){
                            return "r";
                        }
                        else {
                            cout << endl;
                            cout << "ERROR: Invalid input" << endl;
                        }
                    }
                }
                else if(city == "N") {
                    if(startCity <= Countries[country].size()-10 && (startCity+groupSize1)<Countries[country].size()){
                        startCity += groupSize1;
                    }
                    else{
                        cout << endl;
                        cout << "ERROR: Cannot go further" << endl;
                    }
                }
                else if(city == "P") {
                    if(startCity >= 10){startCity -= groupSize1;}
                    else{
                        cout << endl;
                        cout << "ERROR: Cannot go back" << endl;
                    }
                }
                else if(city == "R"){
                    return "r";
                }
                else {
                    cout << endl;
                    cout << "ERROR: Invalid input" << endl;
                }
            }
        }
        else if(country == "N") {
            if(startCountry <= Countries.size()-10 && (startCountry+groupSize1)<Countries.size()) {
                startCountry += groupSize1;
            }
            else{
                cout << endl;
                cout << "ERROR: Cannot go further" << endl;
            }
        }
        else if(country == "P") {
            if(startCountry >= 10){startCountry -= groupSize1;}
            else{
                cout << endl;
                cout << "ERROR: Cannot go back" << endl;
            }
        }
        else if(country == "R"){
            return "r";
        }
        else {
            cout << endl;
            cout << "ERROR: Invalid input" << endl;
        }
    }
} //1 6

string bestFlightAirportToAirportHelper(){
    list<string> airportCodes;
    for(auto a: airports){airportCodes.push_back(a.get_AirportCode());}
    string source;
    string destiny;
    int start1 = 0;
    int groupSize1 = 10;
    while (start1 < airportCodes.size()) {
        //displayGroupAirportsHelper(start1 ,groupSize1);
        cout << endl;
        cout << "Display Tools: Enter 'N' to view the next " << groupSize1 << " airports, 'P' to see the previous "<< groupSize1 <<" or 'R' to return" << endl;
        cout << "Select a source by code or name or a tool: ";
        getline(cin,source);
        Vertex<string>* v1;
        for(auto a: airports) {
            if(source==a.get_AirportName() || source == a.get_AirportCode())
                v1 = connections.findVertex(a.get_AirportCode());
        }
        if (v1) {
            start1 = 0;
            while(start1 < airportCodes.size()) {
                //displayGroupAirportsHelper(start1, groupSize1);
                cout << endl;
                cout << "Display Tools: Enter 'N' to view the next " << groupSize1
                     << " airports, 'P' to see the previous " << groupSize1 << " or 'R' to return" << endl;
                cout << "Now select a destiny by code or name or a tool: ";
                getline(cin,destiny);
                Vertex<string> *v2 ;
                for(auto a: airports) {
                    if(destiny==a.get_AirportName() || destiny == a.get_AirportCode())
                        v1 = connections.findVertex(a.get_AirportCode());
                }
                if (v2) { bestFlightAirportToAirport(source, destiny); }
                else if (source == "N") {
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
