//
// Created by tomas on 26/12/2023.
//

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
    string source;
    string destiny;
    char airport_city;
    char city_airline;
    string airport;
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
                    cout << "ERROR: Invalid input" << endl;
                    cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
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
                    cout << "ERROR: Invalid input" << endl;
                    cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
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
                        cout << endl;
                        flightsAirportHelper();
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
                            cout << "ERROR: Invalid input" << endl;
                            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
                            break;
                        }
                        switch (city_airline) {
                            case '1':
                                cout << endl;
                                flightsPerCityHelper();
                                break;
                            case '2':
                                cout << endl;
                                flightsPerAirlineHelper();
                                break;
                            case 'B':
                                position = 1;
                                break;
                            default:
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
                            cout << "ERROR: Invalid input" << endl;
                            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
                            break;
                        }
                        switch (airport_city) {
                            case '1':
                                cout << endl;
                                countriesPerAirportHelper();
                                break;
                            case '2':
                                cout << endl;
                                countriesPerCityHelper();
                                break;
                            case 'B':
                                position = 1;
                                break;
                            default:
                                cout << "ERROR: Invalid input" << endl;
                                position = 1;
                                break;
                        }
                        break;
                    case '5':
                        cout << endl;
                        destinationsPerAirportHelper();
                        break;
                    case '6':
                        cout << endl;
                        cout << "Choose a maximum value for stops: ";
                        cin >> stops;
                        if (std::cin.fail() || stops < 1) {
                            cin.clear();
                            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            cout << "Invalid input. Please enter a valid integer." << std::endl;
                            position = 1;
                            break;
                        } else {
                            reachableDestinationsHelper(stops);
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
                        if (std::cin.fail() || k < 1) {
                            cin.clear();
                            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            cout << "Invalid input. Please enter a valid integer." << std::endl;
                            position = 1;
                            break;
                        } else {
                            greatestAirTrafficCapacity(k);
                        }
                        break;
                    case '9':
                        cout << endl;
                        essentialAirports();
                        break;
                    case 'B':
                        position = 0;
                        break;
                    default:
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
                    cout << "ERROR: Invalid input" << endl;
                    cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
                    position = 2;
                    break;
                }
                switch (input) {
                    case '1':
                        cout << endl;
                        bestFlightAirportToAirportHelper();
                        break;
                    case '2':
                        cout << endl;
                        bestFlightCityToCityHelper();  //falta resolver a verificacao
                        break;
                    case '3':
                        cout << endl;

                        break;
                    case 'B':
                        position = 0;
                        break;
                    default:
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
