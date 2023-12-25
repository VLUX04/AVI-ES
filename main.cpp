#include <iostream>
#include "Readers/AirlineReader.h"
#include "Readers/AirportReader.h"
#include "Readers/FlightsReader.h"
#include "data_storage/Displays.h"

int main() {
    AirlineReader();
    AirportReader();
    FlightsReader();
    numberOut("MAG");
    flightsPerCity("Paris");
    flightsPerAirline("Ryanair");
    return 0;
}
