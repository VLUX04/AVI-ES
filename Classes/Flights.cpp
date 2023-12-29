#include "Flights.h"

Flight::Flight(std::string source, std::string target, std::string airline) {source_=source; target_=target; airline_=airline;}
string Flight::get_Source() const {return source_;}
string Flight::get_Target() const {return target_;}
string Flight::get_Airline() const {return airline_;}
bool Flight::operator==(const Flight& other) const {
    return source_ == other.source_ && target_ == other.target_ && airline_ == other.airline_;
}

bool Flight::operator<(const Flight& other) const {
    if (source_ != other.source_) return source_ < other.source_;
    if (target_ != other.target_) return target_ < other.target_;
    return airline_ < other.airline_;
}
