#include <iostream>
#include "Readers/AirlineReader.h"
#include "Readers/AirportReader.h"
#include "Readers/FlightsReader.h"
#include "data_storage/Displays.h"

int main() {
   AirlineReader();
   AirportReader();
   FlightsReader();
   /*numberOut("MAG");
   flightsPerCity("Paris");
   flightsPerAirline("Ryanair");
   countriesPerCity("Paris");
   countriesPerAirport("ORY");
   numAirportsDest("ORY");
   numCitiesDest("ORY");
   countriesPerAirportAtDistance("ORY",3);
   numAirportsDestAtDistance("ORY",3);
   numCitiesDestAtDistance("ORY",3);
   greatestAirTrafficCapacity(4);    //3.8
   essentialAirports();*/
   bestFlightAirportToAirport("SVO", "AGP");
   //bestFlightCityToCity("Moscow", "Paris");
   return 0;
}
