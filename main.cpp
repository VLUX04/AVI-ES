#include <iostream>
#include "Readers/AirlineReader.h"
#include "Readers/AirportReader.h"
#include "Readers/FlightsReader.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    AirlineReader();
    AirportReader();
    FlightsReader();
    return 0;
}
