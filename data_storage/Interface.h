#ifndef PROJECT_AIR_INTERFACE_H
#define PROJECT_AIR_INTERFACE_H

#include "Helpers.h"

void Initialize() {
    AirlineReader();
    AirportReader();
    FlightsReader();
    char input;
    int k;
    int stops;
    pair<double,double> location;
    double lon;
    double lat;
    double targetLon;
    double targetLat;
    string source;
    string destiny;
    char airport_city;
    char city_airline;
    string airport;
    string city;
    int position = 0;
    while (true) {
        switch (position) {
            case 0:
                cout << endl;
                cout << "|------------------------------------------------------------|" << endl;
                cout << "|                            MENU                            |" << endl;
                cout << "|------------------------------------------------------------|" << endl;
                cout << "| Functionalities:                                           |" << endl;
                cout << "|                                                            |" << endl;
                cout << "| 1. Statistics                                              |" << endl;
                cout << "| 2. Best flight option                                      |" << endl;
                cout << "| 3. Best flight option with filters                         |" << endl;
                cout << "|                                                            |" << endl;
                cout << "|------------------------------------------------------------|" << endl;
                cout << " Enter the index number to select or 'B' to exit: ";
                cin >> input;
                if (cin.peek() != '\n') {
                    cout << endl;
                    cout << "ERROR: Invalid input" << endl;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    position = 0;
                    break;
                }
                switch (input) {
                    case '1':
                        position = 1;
                        break;
                    case '2':
                        position = 2;
                        break;
                    case '3':
                        position = 3;
                        break;
                    case 'B':
                        return;  //exit
                    default:
                        cout << endl;
                        cout << "ERROR: Invalid input" << endl;
                        position = 0;
                        break;
                }
                break;
            case 1:
                cout << endl;
                cout << "|------------------------------------------------------------|" << endl;
                cout << "|                         STATISTICS                         |" << endl;
                cout << "|------------------------------------------------------------|" << endl;
                cout << "|                                                            |" << endl;
                cout << "| 1. Global number of airports and flights                   |" << endl;
                cout << "| 2. Number of flights given an airport                      |" << endl;
                cout << "| 3. Number of flights given a city/airline                  |" << endl;
                cout << "| 4. Number of  countries that a given airport/city flies to |" << endl;
                cout << "| 5. Number of destinations available for a given airport    |" << endl;
                cout << "| 6. Number of reachable destinations from a given airport   |" << endl;
                cout << "|    in a maximum number of X stops                          |" << endl;
                cout << "| 7. Trip with the maximum number of stops between them      |" << endl;
                cout << "|    and corresponding pair of source-destination            |" << endl;
                cout << "| 8. Top-K airport with the greatest air traffic capacity    |" << endl;
                cout << "| 9. Essential airports to network's circulation capability  |" << endl;
                cout << "|                                                            |" << endl;
                cout << "|------------------------------------------------------------|" << endl;
                cout << " Enter the index number to select or 'B' to go back: ";
                cin >> input;
                if (cin.peek() != '\n') {
                    cout << endl;
                    cout << "ERROR: Invalid input" << endl;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    position = 1;
                    break;
                }
                switch (input) {
                    case '1':
                        cout << endl;
                        cout << "The global number of airports is " << numberAirports() << endl;
                        cout << "The global number of flights is " << numberFlights() << endl;
                        break;
                    case '2':
                        airport = selectCountryCityAirportHelper();
                        if(airport=="r") break;
                        cout << endl;
                        numberOut(airport);
                        break;
                    case '3':
                        cout << endl;
                        cout << "|------------------------------------------------------------|" << endl;
                        cout << "|                          FLIGHTS                           |" << endl;
                        cout << "|------------------------------------------------------------|" << endl;
                        cout << "|                                                            |" << endl;
                        cout << "| 1. Per city                                                |" << endl;
                        cout << "| 2. Per airline                                             |" << endl;
                        cout << "|                                                            |" << endl;
                        cout << "|------------------------------------------------------------|" << endl;
                        cout << " Enter the index number to select or 'B' to go back: ";
                        cin >> city_airline;
                        if (cin.peek() != '\n') {
                            cout << endl;
                            cout << "ERROR: Invalid input" << endl;
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            break;
                        }
                        switch (city_airline) {
                            case '1':
                                city=selectCountryCityHelper();
                                if(city=="r") break;
                                cout << endl;
                                if(flightsPerCity(city) == 1) {
                                    cout << endl << "There is " << flightsPerCity(city) << " flight from " << city << endl;
                                }
                                else{cout << endl << "There are " << flightsPerCity(city) << " flights from " << city << endl;}
                                break;
                            case '2':
                                cout << endl;
                                flightsPerAirlineHelper();
                                break;
                            case 'B':
                                position = 1;
                                break;
                            default:
                                cout << endl;
                                cout << "ERROR: Invalid input" << endl;
                                position = 1;
                                break;
                        }
                        break;
                    case '4':
                        cout << endl;
                        cout << "|------------------------------------------------------------|" << endl;
                        cout << "|                     Reachable Countries                    |" << endl;
                        cout << "|------------------------------------------------------------|" << endl;
                        cout << "|                                                            |" << endl;
                        cout << "| 1. Per airport                                             |" << endl;
                        cout << "| 2. Per city                                                |" << endl;
                        cout << "|                                                            |" << endl;
                        cout << "|------------------------------------------------------------|" << endl;
                        cout << " Enter the index number to select or 'B' to go back: ";
                        cin >> airport_city;
                        if (cin.peek() != '\n') {
                            cout << endl;
                            cout << "ERROR: Invalid input" << endl;
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            break;
                        }
                        switch (airport_city) {
                            case '1':
                                airport = selectCountryCityAirportHelper();
                                if(airport=="r") break;
                                cout << endl;
                                if(countriesPerAirport(airport) == 1){
                                    cout << endl << "There is " << countriesPerAirport(airport) << " reachable country from the airport " << airport << endl;
                                }
                                else{cout << endl << "There are " << countriesPerAirport(airport) << " reachable countries from the airport " << airport << endl;}
                                break;
                            case '2':
                                cout << endl;
                                countriesPerCityHelper();
                                break;
                            case 'B':
                                position = 1;
                                break;
                            default:
                                cout << endl;
                                cout << "ERROR: Invalid input" << endl;
                                position = 1;
                                break;
                        }
                        break;
                    case '5':
                        airport = selectCountryCityAirportHelper();
                        if(airport=="r") break;
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
                        break;
                    case '6':
                        cout << endl;
                        cout << "Choose a maximum value for stops: ";
                        cin >> stops;
                        if (cin.fail() || stops < 1) {
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            cout << endl;
                            cout << "ERROR: Invalid input. Please enter a valid integer." << endl;
                            position = 1;
                            break;
                        } else {
                            airport = selectCountryCityAirportHelper();
                            if(airport=="r") break;
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
                        }
                        break;
                    case '7':
                        cout << endl;
                        maxTrip();
                        break;
                    case '8':
                        cout << endl;
                        cout << "Choose a value for K: ";
                        cin >> k;
                        if (cin.fail() || k < 1) {
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            cout << endl;
                            cout << "ERROR: Invalid input. Please enter a valid integer." << endl;
                            position = 1;
                            break;
                        } else {greatestAirTrafficCapacity(k);}
                        break;
                    case '9':
                        cout << endl;
                        essentialAirportsHelper();
                        break;
                    case 'B':
                        position = 0;
                        break;
                    default:
                        cout << endl;
                        cout << "ERROR: Invalid input" << endl;
                        position = 1;
                        break;
                }
                break;
            case 2:
                cout << endl;
                cout << "|------------------------------------------------------------|" << endl;
                cout << "|                     BEST FLIGHT OPTION                     |" << endl;
                cout << "|------------------------------------------------------------|" << endl;
                cout << "| Best flight options given:                                 |" << endl;
                cout << "|                                                            |" << endl;
                cout << "| 1. Airport code or name                                    |" << endl;
                cout << "| 2. City name                                               |" << endl;
                cout << "| 3. Geographical coordinates                                |" << endl;
                cout << "|                                                            |" << endl;
                cout << "|------------------------------------------------------------|" << endl;
                cout << " Enter the index number to select or 'B' to go back: ";
                cin >> input;
                if (cin.peek() != '\n') {
                    cout << endl;
                    cout << "ERROR: Invalid input" << endl;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    position = 2;
                    break;
                }
                switch (input) {
                    case '1':
                        source = selectCountryCityAirportHelper();
                        if(source=="r") break;
                        destiny = selectCountryCityAirportHelper();
                        if(destiny=="r") break;
                        if(source==destiny) {
                            cout << endl;
                            cout << "ERROR: Invalid Input. The source cannot be the same as the destination." << endl;
                            break;
                        }
                        bestFlightAirportToAirport(source, destiny);
                        break;
                    case '2':
                        source = selectCountryCityHelper();
                        if(source=="r") break;
                        destiny = selectCountryCityHelper();
                        if(destiny=="r") break;
                        if(source==destiny) {
                            cout << endl;
                            cout << "ERROR: Invalid Input. The source cannot be the same as the destination." << endl;
                            break;
                        }
                        bestFlightCityToCity(source, destiny);
                        break;
                    case '3':
                        cout << endl;
                        cout << "Choose the coordinates of the source airport: " << endl;
                        location = chooseCordinates();
                        if(location.first == 200.0 && location.second == 200.0){
                            position = 2;
                            break;
                        }
                        lat = location.first;
                        lon = location.second;
                        cout << endl;
                        cout << "Choose the coordinates of the target airport: " << endl;
                        location = chooseCordinates();
                        if(location.first == 200.0 && location.second == 200.0){
                            position = 2;
                            break;
                        }
                        targetLat = location.first;
                        targetLon = location.second;
                        cout << endl << "Wait a moment. We are calculating the best flight options..." << endl;
                        coordsBestFlight(lon,lat,targetLon,targetLat);
                        break;
                    case 'B':
                        position = 0;
                        break;
                    default:
                        cout << endl;
                        cout << "ERROR: Invalid input" << endl;
                        position = 2;
                        break;
                }
                break;
            case 3:
                cout << endl;
                cout << "|------------------------------------------------------------|" << endl;
                cout << "|              BEST FLIGHT OPTION WITH FILTERS               |" << endl;
                cout << "|------------------------------------------------------------|" << endl;
                cout << "| Best flight options given:                                 |" << endl;
                cout << "|                                                            |" << endl;
                cout << "| 1. Airport code or name                                    |" << endl;
                cout << "| 2. City name                                               |" << endl;
                cout << "| 3. Geographical coordinates                                |" << endl;
                cout << "|                                                            |" << endl;
                cout << "|------------------------------------------------------------|" << endl;
                cout << " Enter the index number to select or 'B' to go back: ";
                cin >> input;

        }
    }
}

#endif //PROJECT_AIR_INTERFACE_H
