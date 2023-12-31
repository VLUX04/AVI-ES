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
    int airlineNumber;
    pair<double, double> location;
    double lon;
    double lat;
    double targetLon;
    double targetLat;
    char airport_city;
    char city_airline;
    bool flag = false;
    string source;
    string destiny;
    string airport;
    string city;
    string country;
    string airline;
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
                        checkIsolatedAirportGroups();
                        break;
                    case '2':
                        country = selectCountryHelper();
                        if (country == "r") break;
                        city = selectCityHelper(country);
                        if (city == "r") break;
                        airport = selectAirportHelper(country, city);
                        if (airport == "r") break;
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
                                country = selectCountryHelper();
                                if (country == "r") break;
                                city = selectCityHelper(country);
                                if (city == "r") break;
                                cout << endl;
                                if (flightsPerCity(city) == 1) {
                                    cout << endl << "There is " << flightsPerCity(city) << " flight from " << city
                                         << endl;
                                } else {
                                    cout << endl << "There are " << flightsPerCity(city) << " flights from " << city
                                         << endl;
                                }
                                break;
                            case '2':
                                country = selectCountryHelper();
                                if (country == "r") break;
                                airline = selectAirlineHelper(country);
                                if (airline == "r") break;

                                if (flightsPerAirline(airline) == 1) {
                                    cout << endl << "There is " << flightsPerAirline(airline)
                                         << " flight from the airline " << airline << endl;
                                } else {
                                    cout << endl << "There are " << flightsPerAirline(airline)
                                         << " flights from the airline " << airline << endl;
                                }
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
                                country = selectCountryHelper();
                                if (country == "r") break;
                                city = selectCityHelper(country);
                                if (city == "r") break;
                                airport = selectAirportHelper(country, city);
                                if (airport == "r") break;
                                cout << endl;
                                if (countriesPerAirport(airport) == 1) {
                                    cout << endl << "There is " << countriesPerAirport(airport)
                                         << " reachable country from the airport " << airport << endl;
                                } else {
                                    cout << endl << "There are " << countriesPerAirport(airport)
                                         << " reachable countries from the airport " << airport << endl;
                                }
                                break;
                            case '2':
                                country = selectCountryHelper();
                                if (country == "r") break;
                                city = selectCityHelper(country);
                                if (city == "r") break;
                                cout << endl;
                                if (countriesPerCity(country, city) == 1) {
                                    cout << endl << "There is " << countriesPerCity(country, city)
                                         << " reachable country from the city " << city << endl;
                                } else {
                                    cout << endl << "There are " << countriesPerCity(country, city)
                                         << " reachable countries from the city " << city << endl;
                                }
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
                        country = selectCountryHelper();
                        if (country == "r") break;
                        city = selectCityHelper(country);
                        if (city == "r") break;
                        airport = selectAirportHelper(country, city);
                        if (airport == "r") break;
                        cout << endl;
                        if (numAirportsDest(airport) == 1) {
                            cout << "There is " << numAirportsDest(airport)
                                 << " airport as destination from the airport " << airport << endl;
                        } else {
                            cout << "There are " << numAirportsDest(airport)
                                 << " different airports as destination from the airport " << airport << endl;
                        }
                        if (numCitiesDest(airport) == 1) {
                            cout << "There is " << numCitiesDest(airport) << "  city as destination from the airport "
                                 << airport << endl;
                        } else {
                            cout << "There are " << numCitiesDest(airport)
                                 << " different cities as destination from the airport " << airport << endl;
                        }
                        if (numCountriesDest(airport) == 1) {
                            cout << "There is " << numCountriesDest(airport)
                                 << " country as destination from the airport " << airport << endl;
                        } else {
                            cout << "There are " << numCountriesDest(airport)
                                 << " different countries as destination from the airport " << airport << endl;
                        }
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
                            country = selectCountryHelper();
                            if (country == "r") break;
                            city = selectCityHelper(country);
                            if (city == "r") break;
                            airport = selectAirportHelper(country, city);
                            if (airport == "r") break;
                            cout << endl;
                            if (numAirportsDestAtDistance(airport, stops) == 1) {
                                cout << "There is " << numAirportsDestAtDistance(airport, stops)
                                     << " reachable airport from the airport " << airport << " with " << stops
                                     << " stops." << endl;
                            } else {
                                cout << "There are " << numAirportsDestAtDistance(airport, stops)
                                     << " reachable airports from the airport " << airport << " with " << stops
                                     << " stops." << endl;
                            }
                            if (numCitiesDestAtDistance(airport, stops) == 1) {
                                cout << "There is " << numCitiesDestAtDistance(airport, stops)
                                     << " reachable city from the airport " << airport << " with " << stops << " stops."
                                     << endl;
                            } else {
                                cout << "There are " << numCitiesDestAtDistance(airport, stops)
                                     << " reachable cities from the airport " << airport << " with " << stops
                                     << " stops." << endl;
                            }
                            if (countriesPerAirportAtDistance(airport, stops) == 1) {
                                cout << "There is " << countriesPerAirportAtDistance(airport, stops)
                                     << " reachable country from the airport " << airport << " with " << stops
                                     << " stops." << endl;
                            } else {
                                cout << "There are " << countriesPerAirportAtDistance(airport, stops)
                                     << " reachable countries from the airport " << airport << " with " << stops
                                     << " stops." << endl;
                            }
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
                        } else { greatestAirTrafficCapacity(k); }
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
                cout << "| 1. Airport codes or names                                  |" << endl;
                cout << "| 2. City names                                              |" << endl;
                cout << "| 3. Geographical coordinates                                |" << endl;
                cout << "| 4. Airport code or name and a city name                    |" << endl;
                cout << "| 5. City name and an airport code or name                   |" << endl;
                cout << "| 6. City name and a pair of geographical coordinates        |" << endl;
                cout << "| 7. A pair of geographical coordinates and a city name      |" << endl;
                cout << "| 8. A pair of geographical coordinates and an airport code  |" << endl;
                cout << "|    or name                                                 |" << endl;
                cout << "| 9. Airport code or name and a pair of geographical         |" << endl;
                cout << "|    coordinates                                             |" << endl;
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
                        country = selectCountryHelper();
                        if (country == "r") break;
                        city = selectCityHelper(country);
                        if (city == "r") break;
                        source = selectAirportHelper(country, city);
                        if (source == "r") break;

                        country = selectCountryHelper();
                        if (country == "r") break;
                        city = selectCityHelper(country);
                        if (city == "r") break;
                        destiny = selectAirportHelper(country, city);
                        if (destiny == "r") break;

                        if (source == destiny) {
                            cout << endl;
                            cout << "ERROR: Invalid Input. The source cannot be the same as the destination." << endl;
                            break;
                        }
                        cout << endl << "Wait a moment. We are calculating the best flight options..." << endl;
                        bestFlightAirportToAirport(source, destiny);
                        break;
                    case '2':
                        country = selectCountryHelper();
                        if (country == "r") break;
                        source = selectCityHelper(country);
                        if (source == "r") break;

                        country = selectCountryHelper();
                        if (country == "r") break;
                        destiny = selectCityHelper(country);
                        if (destiny == "r") break;

                        if (source == destiny) {
                            cout << endl;
                            cout << "ERROR: Invalid Input. The source cannot be the same as the destination." << endl;
                            break;
                        }
                        cout << endl << "Wait a moment. We are calculating the best flight options..." << endl;
                        bestFlightCityToCity(source, destiny);
                        break;
                    case '3':
                        cout << endl;
                        cout << "Choose the coordinates of the source airport: " << endl;
                        location = chooseCoordinates();
                        if (location.first == 200.0 && location.second == 200.0) {
                            position = 2;
                            break;
                        }
                        lat = location.first;
                        lon = location.second;
                        cout << endl;
                        cout << "Choose the coordinates of the target airport: " << endl;
                        location = chooseCoordinates();
                        if (location.first == 200.0 && location.second == 200.0) {
                            position = 2;
                            break;
                        }
                        targetLat = location.first;
                        targetLon = location.second;
                        cout << endl << "Wait a moment. We are calculating the best flight options..." << endl;
                        coordsBestFlight(lat, lon, targetLat, targetLon);
                        break;
                    case '4':
                        country = selectCountryHelper();
                        if (country == "r") break;
                        city = selectCityHelper(country);
                        if (city == "r") break;
                        source = selectAirportHelper(country, city);
                        if (source == "r") break;

                        country = selectCountryHelper();
                        if (country == "r") break;
                        destiny = selectCityHelper(country);
                        if (destiny == "r") break;

                        if (city == destiny) {
                            cout << endl;
                            cout << "ERROR: Invalid Input. The source cannot be the same as the destination." << endl;
                            break;
                        }
                        cout << endl << "Wait a moment. We are calculating the best flight options..." << endl;
                        bestFlightAirportToCity(source, destiny);
                        break;
                    case '5':
                        country = selectCountryHelper();
                        if (country == "r") break;
                        source = selectCityHelper(country);
                        if (source == "r") break;

                        country = selectCountryHelper();
                        if (country == "r") break;
                        city = selectCityHelper(country);
                        if (city == "r") break;
                        destiny = selectAirportHelper(country, city);
                        if (destiny == "r") break;

                        if (source == city) {
                            cout << endl;
                            cout << "ERROR: Invalid Input. The source cannot be the same as the destination." << endl;
                            break;
                        }
                        cout << endl << "Wait a moment. We are calculating the best flight options..." << endl;
                        bestFlightCityToAirport(source, destiny);
                        break;
                    case '6':
                        country = selectCountryHelper();
                        if (country == "r") break;
                        source = selectCityHelper(country);
                        if (source == "r") break;

                        cout << endl;
                        cout << "Choose the coordinates of the target airport: " << endl;
                        location = chooseCoordinates();
                        if (location.first == 200.0 && location.second == 200.0) {
                            position = 2;
                            break;
                        }
                        lat = location.first;
                        lon = location.second;
                        cout << endl << "Wait a moment. We are calculating the best flight options..." << endl;
                        bestFlightCityToLocation(source, lon, lat);
                        break;
                    case '7':
                        cout << endl;
                        cout << "Choose the coordinates of the source airport: " << endl;
                        location = chooseCoordinates();
                        if (location.first == 200.0 && location.second == 200.0) {
                            position = 2;
                            break;
                        }
                        lat = location.first;
                        lon = location.second;

                        country = selectCountryHelper();
                        if (country == "r") break;
                        destiny = selectCityHelper(country);
                        if (destiny == "r") break;

                        cout << endl << "Wait a moment. We are calculating the best flight options..." << endl;
                        bestFlightLocationToCity(lon, lat, destiny);
                        break;
                    case '8':
                        cout << endl;
                        cout << "Choose the coordinates of the source airport: " << endl;
                        location = chooseCoordinates();
                        if (location.first == 200.0 && location.second == 200.0) {
                            position = 2;
                            break;
                        }
                        lat = location.first;
                        lon = location.second;

                        country = selectCountryHelper();
                        if (country == "r") break;
                        city = selectCityHelper(country);
                        if (city == "r") break;
                        destiny = selectAirportHelper(country, city);
                        if (destiny == "r") break;

                        for (auto x: airports) {
                            if (x.get_AirportCode() == destiny && x.get_Longitude() == lon && x.get_Latitude() == lat) {
                                flag = true;
                                break;
                            }
                            if (x.get_AirportCode() == destiny) {
                                targetLat = x.get_Latitude();
                                targetLon = x.get_Longitude();
                                break;
                            }
                        }
                        if (flag) {
                            flag = false;
                            cout << endl;
                            cout << "ERROR: Invalid Input. The source cannot be the same as the destination." << endl;
                            break;
                        }
                        cout << endl << "Wait a moment. We are calculating the best flight options..." << endl;
                        bestFlightLocationToAirport(targetLat, targetLon, lon, lat);
                        break;
                    case '9':
                        cout << endl;
                        country = selectCountryHelper();
                        if (country == "r") break;
                        city = selectCityHelper(country);
                        if (city == "r") break;
                        source = selectAirportHelper(country, city);
                        if (source == "r") break;

                        cout << endl;
                        cout << "Choose the coordinates of the target airport: " << endl;
                        location = chooseCoordinates();
                        if (location.first == 200.0 && location.second == 200.0) {
                            position = 2;
                            break;
                        }
                        targetLat = location.first;
                        targetLon = location.second;

                        for (auto x: airports) {
                            if (x.get_AirportCode() == source && x.get_Longitude() == targetLon &&
                                x.get_Latitude() == targetLat) {
                                flag = true;
                                break;
                            }
                            if (x.get_AirportCode() == source) {
                                lat = x.get_Latitude();
                                lon = x.get_Longitude();
                                break;
                            }
                        }
                        if (flag) {
                            flag = false;
                            cout << endl;
                            cout << "ERROR: Invalid Input. The source cannot be the same as the destination." << endl;
                            break;
                        }
                        cout << endl << "Wait a moment. We are calculating the best flight options..." << endl;
                        bestFlightAirportToLocation(lon, lat, targetLon, targetLat);
                        break;
                    case 'B':
                        cout << endl << "All the previous filters will be discarded, are you sure you want to go back?";
                        cout << endl << "Select 'Y' if so or 'N' to stay. ";
                        cin >> input;
                        switch (input) {
                            case 'Y':
                                airlinesToFilter.clear();
                                airpotsToFilter.clear();
                                NumAirline = INT_MAX;
                                position = 0;
                                break;
                            case 'N':
                                break;
                            default:
                                cout << endl;
                                cout << "ERROR: Invalid input" << endl;
                                position = 2;
                                break;
                        }
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
                cout << "|                     Available Filters                      |" << endl;
                cout << "|------------------------------------------------------------|" << endl;
                cout << "|                                                            |" << endl;
                cout << "| 1. Use only a specific set of airlines                     |" << endl;
                cout << "| 2. Minimize the number of different airlines               |" << endl;
                cout << "| 3. Use only a specific set of airports                     |" << endl;
                cout << "|                                                            |" << endl;
                cout << "|        AFTER SELECTING ALL THE FILTERS, PRESS 'F'.         |" << endl;
                cout << "|                                                            |" << endl;
                cout << "|------------------------------------------------------------|" << endl;
                cout << " Enter the index number to select or 'B' to go back: ";
                cin >> input;
                if (cin.peek() != '\n') {
                    cout << endl;
                    cout << "ERROR: Invalid input" << endl;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    position = 3;
                    break;
                }
                switch (input) {
                    case '1':
                        cout << endl;
                        selectAirlinesHelper();
                        break;
                    case '2':
                        cout << endl;
                        cout << "Choose a number of airlines to use: ";
                        cin >> airlineNumber;
                        if (cin.fail() || airlineNumber < 1 || airlineNumber > airlines.size()) {
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            cout << endl;
                            cout << "ERROR: Invalid input. Please enter a valid integer." << endl;
                            position = 3;
                            break;
                        } else {
                            filterNumAirline(airlineNumber);
                            break;
                        }
                    case '3':
                        cout << endl;
                        selectAirportsHelper();
                        break;
                    case 'F':
                        position = 2;
                        break;
                    case 'B':
                        cout << endl << "All the previous filters will be discarded, are you sure you want to go back?";
                        cout << endl << "Select 'Y' if so or 'N' to stay. ";
                        cin >> input;
                        switch (input) {
                            case 'Y':
                                airlinesToFilter.clear();
                                airpotsToFilter.clear();
                                NumAirline = INT_MAX;
                                position = 0;
                                break;
                            case 'N':
                                break;
                            default:
                                cout << endl;
                                cout << "ERROR: Invalid input" << endl;
                                position = 3;
                                break;
                        }
                        break;
                    default:
                        cout << endl;
                        cout << "ERROR: Invalid input" << endl;
                        position = 3;
                        break;
                }

        }
    }
}

#endif //PROJECT_AIR_INTERFACE_H
