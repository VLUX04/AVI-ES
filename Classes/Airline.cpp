#include "Airline.h"

Airport::Airport(std::string airlineCode, std::string airlineName, std::string callSign, std::string country) {airlineCode_=airlineCode; airlineName_=airlineName; callSign_=callSign;}
string Airport::get_AirlineCode() {return airlineCode_;}
string Airport::get_AirlineName() {return airlineName_;}
string Airport::get_CallSign() {return callSign_;}
string Airport::get_Country() {return country_;}
