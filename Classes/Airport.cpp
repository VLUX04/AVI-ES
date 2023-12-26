#include "Airport.h"

Airport::Airport() {airportCode_=""; airportName_=""; city_=""; country_=""; latitude_=0; longitude_=0;}
Airport::Airport(std::string airportCode, std::string airportName, std::string city, std::string country, double latitude, double longitude) {airportCode_=airportCode; airportName_=airportName; city_=city; country_=country; latitude_=latitude; longitude_=longitude;}
string Airport::get_AirportCode() {return airportCode_;}
string Airport::get_AirportName() {return airportName_;}
string Airport::get_City() {return city_;}
string Airport::get_Country() {return country_;}
double Airport::get_Latitude() {return latitude_;}
double Airport::get_Longitude() {return longitude_;}
