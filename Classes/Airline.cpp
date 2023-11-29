#include "Airline.h"

Airline::Airline(std::string airlineCode, std::string airlineName, std::string callSign, std::string country) {airlineCode_=airlineCode; airlineName_=airlineName; callSign_=callSign; country_ = country}
string Airline::get_AirlineCode() {return airlineCode_;}
string Airline::get_AirlineName() {return airlineName_;}
string Airline::get_CallSign() {return callSign_;}
string Airline::get_Country() {return country_;}
