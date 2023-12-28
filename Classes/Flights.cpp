#include "Flights.h"

Flight::Flight(std::string source, std::string target, std::string airline) {source_=source; target_=target; airline_=airline;}
string Flight::get_Source() const {return source_;}
string Flight::get_Target() const {return target_;}
string Flight::get_Airline() const {return airline_;}
bool Flight::operator==(const Flight& other) const {
    return source_ == other.source_ && target_ == other.target_ && airline_ == other.airline_;
}

bool Flight::operator<(const Flight& other) const {
    if (airline_ != other.airline_) return airline_ < other.airline_;
    if (source_ != other.source_) return source_ < other.source_;
    return target_ < other.target_;
}
