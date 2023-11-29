
#include "Flights.h"

Flight::Flight(std::string source, std::string target, std::string airline) {source_=source; target_=target; airline_=airline;}
string Flight::get_Source() {return source_;}
string Flight::get_Target() {return target_;}
string Flight::get_Airline() {return airline_;}
