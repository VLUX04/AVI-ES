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
    Airport();
    Airport(string airportCode, string airportName, string city, string country, double latitude, double longitude);
    string get_AirportCode() const;
    string get_AirportName() const;
    string get_City() const;
    string get_Country() const;
    double get_Latitude() const;
    double get_Longitude() const;
};


#endif //Project_Air_AIRPORT_H
