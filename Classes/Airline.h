
#ifndef Project_Air_AIRLINE_H
#define Project_Air_AIRLINE_H

#include <string>
using namespace std;

class Airline {

private:
    string airlineCode_;
    string airlineName_;
    string callSign_;
    string country_;

public:
    Airline(string airlineCode, string airlineName, string callSign, string country);
    string get_AirlineCode();
    string get_AirlineName();
    string get_CallSign();
    string get_Country();
};


#endif
