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
    for(const auto& a:Countries){countries.push_back(a.first);}
    cout << endl;
    cout << "|------------------------------------------------------------|" << endl;
    cout << "| Countries List                                             |" << endl;
    cout << "|------------------------------------------------------------|" << endl;
    // Display the current group of 10 elements
    for (int i = start; i < start + groupSize && i < countries.size(); ++i) {
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
void displayGroupCitiesHelper(const string& country,int start ,int groupSize) {
    vector<string> cities;
    for(const auto& a:Countries){
        if(a.first == country){
            for(const auto& x: a.second)cities.push_back(x);
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
void displayGroupArticulationsHelper(unordered_set<string> res, int start, int groupSize) {
    vector<string>essentialAirports;
    for(const auto& a:res){essentialAirports.push_back(a);}
    cout << endl;
    cout << "|------------------------------------------------------------|" << endl;
    cout << "| Essential airports List                                    |" << endl;
    cout << "|------------------------------------------------------------|" << endl;
    // Display the current group of 10 elements
    for (int i = start; i < start + groupSize && i < essentialAirports.size(); ++i) {
        string linha = multString(" ", 58 - essentialAirports[i].size());
        cout << "| " << essentialAirports[i] << linha << " |" << endl;
        cout << "|------------------------------------------------------------|" << endl;
    }
}

string selectCountryHelper(){
    string country;
    int startCountry = 0;
    int groupSize1 = 10;

    while (startCountry < Countries.size()) {
        displayGroupCountriesHelper(startCountry,groupSize1);
        cout << endl;
        cout << "Display Tools: Enter 'N' to view the next " << groupSize1 << " countries, 'P' to see the previous "<< groupSize1 <<" or 'R' to return" << endl;
        cout << "Select a country or a tool: ";
        getline(cin >> ws,country);
        auto it = Countries.find(country);
        if(it != Countries.end()) {
            return country;
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
    return "qwert";
}
string selectCityHelper(const string& country) {
    string city;
    int startCity = 0;
    int groupSize1 = 10;

    while(startCity < Countries[country].size()){
        displayGroupCitiesHelper(country,startCity,groupSize1);
        cout << endl;
        cout << "Display Tools: Enter 'N' to view the next " << groupSize1 << " cities, 'P' to see the previous "<< groupSize1 <<" or 'R' to return" << endl;
        cout << "Select a city or a tool: ";
        getline(cin >> ws,city);
        if(find(Countries[country].begin(),Countries[country].end(),city) != Countries[country].end()){
            return city;
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
    return "qwert";
}
string selectAirportHelper(const string& country, const string& city) {
    int startAirport = 0;
    int groupSize1 = 10;
    string airport;
    vector<string> cityAirportCodesAndNames;
    vector<Airport> cityAirports;

    for(const auto& a: airports){
        if(a.get_Country() == country && a.get_City() == city){
            cityAirports.push_back(a);
            cityAirportCodesAndNames.push_back(a.get_AirportCode());
            cityAirportCodesAndNames.push_back((a.get_AirportName()));
        }
    }

    while(startAirport < cityAirports.size()){
        displayGroupAirportsHelper(cityAirports,startAirport,groupSize1);
        cout << endl;
        cout << "Display Tools: Enter 'N' to view the next " << groupSize1 << " airports, 'P' to see the previous "<< groupSize1 <<" or 'R' to return" << endl;
        cout << "Select a airport by code or name or a tool: ";
        getline(cin >> ws,airport);
        if(find(cityAirportCodesAndNames.begin(),cityAirportCodesAndNames.end(),airport) != cityAirportCodesAndNames.end()){
            return airport;
        }
        else if(airport == "N") {
            if(startAirport <= cityAirports.size()-10 && (startAirport+groupSize1)<cityAirports.size()){
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
    return "qwert";
}
string selectAirlineHelper(const string& country) {
    string airline;
    int start1 = 0;
    int groupSize1 = 10;
    vector<string>airlinesStr;
    vector<Airline> airlinesPerCountry;
    for(const auto& a: airlines){
        if(a.get_Country() == country){
            airlinesPerCountry.push_back(a);
            airlinesStr.push_back(a.get_AirlineCode());
            airlinesStr.push_back(a.get_AirlineName());
        }
    }
    while(start1 < airlinesPerCountry.size()){
        displayGroupAirlineHelper(airlinesPerCountry,start1 ,groupSize1);
        cout << endl;
        cout << "Display Tools: Enter 'N' to view the next " << groupSize1 << " airlines, 'P' to see the previous "<< groupSize1 <<" or 'R' to return" << endl;
        cout << "Select an airline by code or name or a tool: ";
        getline(cin >> ws, airline);
        if(find(airlinesStr.begin(),airlinesStr.end(),airline) != airlinesStr.end()) {
            return airline;
        }
        else if(airline == "N") {
            if(start1 <= airlinesPerCountry.size() - 10 && (start1+groupSize1)<airlinesPerCountry.size()){start1 += groupSize1;}
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
    return "qwert";
}
string essentialAirportsHelper(){
    string input;
    int start = 0;
    int groupSize = 10;
    unordered_set<string> res = articulationAirports();
    cout << "In total there are " << res.size() << " essential airports to the network's circulation capability." << endl;
    cout << "Enter 'Y' if you want to see the list of the essential airport or 'R' to return." << endl;
    getline(cin >> ws,input);
    if(input == "Y"){
        while(start < res.size()){
            displayGroupArticulationsHelper(res,start,groupSize);
            cout << endl;
            cout << "Display Tools: Enter 'N' to view the next " << groupSize << " airports, 'P' to see the previous "<< groupSize <<" or 'R' to return" << endl;
            getline(cin >> ws,input);
            if(input == "N") {
                if(start <= res.size()-10 && (start+groupSize)<res.size()){
                    start += groupSize;
                }
                else{
                    cout << endl;
                    cout << "ERROR: Cannot go further" << endl;
                }
            }
            else if(input == "P") {
                if(start >= 10){start -= groupSize;}
                else{
                    cout << endl;
                    cout << "ERROR: Cannot go back" << endl;
                }
            }
            else if(input == "R"){
                return "r";
            }
            else {
                cout << endl;
                cout << "ERROR: Invalid input" << endl;
            }
        }
    }
    else{return "qwert";}
    return "qwert";
}
pair<double,double> chooseCoordinates(){
    string lat;
    string lon;
    pair<double,double> res;
    while(true){
        cout << "Choose a value for the latitude or 'R' to return: ";
        cin >> lat;
        if(lat == "R"){
            res.first = 200.0;
            res.second = 200.0;
            return res;
        }
        try{
            res.first = stod(lat);
            if (cin.fail() || res.first < -90.0 || res.first > 90.0) {
                throw invalid_argument("Invalid input. Please enter a valid latitude value (between -90.0 and +90.0).");
            }
            break;
        }
        catch(const invalid_argument& e){
            cout << "Invalid Input." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    cout << endl;
    while(true){
        cout << "Choose a value for the longitude or 'R' to return: ";
        cin >> lon;
        if(lon == "R"){
            res.first = 200.0;
            res.second = 200.0;
            return res;
        }
        try{
            res.second = stod(lon);
            if (cin.fail() || res.second < -180.0 || res.second > 180.0) {
                throw invalid_argument("Invalid input. Please enter a valid latitude value (between -180.0 and +180.0).");
            }
            break;
        }
        catch(const invalid_argument& e){
            cout << "Invalid Input." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    return res;
}

#endif //PROJECT_AIR_HELPERS_H