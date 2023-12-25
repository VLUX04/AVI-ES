#ifndef Project_Air_AIRPORT_H
#define Project_Air_AIRPORT_H

#include <string>
using namespace std;

class Airport {
private:
    string airportCode_;
    string airportName_;
    string city_;
    string country_;
    double latitude_;
    double longitude_;

public:
    Airport(string airportCode, string airportName, string city, string country, double latitude, double longitude);
    string get_AirportCode();
    string get_AirportName();
    string get_City();
    string get_Country();
    double get_Latitude();
    double get_Longitude();
};


#endif //PROJETO2AED_AIRPORT_H
