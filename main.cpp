#include <iostream>
#include "Readers/AirlineReader.h"
#include "Readers/AirportReader.h"
#include "Readers/FlightsReader.h"
#include "data_storage/Displays.h"

int main() {
   AirlineReader();
   AirportReader();
   FlightsReader();
   numberOut("MAG");//3.1
   flightsPerCity("Paris");//3.2
   flightsPerAirline("Ryanair");//3.3
   countriesPerCity("Paris");//3.4
   countriesPerAirport("ORY");//
   numAirportsDest("ORY");//3.5
   numCitiesDest("ORY");//
   countriesPerAirportAtDistance("ORY",3);//
   numAirportsDestAtDistance("ORY",3);//3.6
   numCitiesDestAtDistance("ORY",3);//
   maxTrip();//3.7
   greatestAirTrafficCapacity(4);//3.8
   essentialAirports();//3.9
   return 0;
}
