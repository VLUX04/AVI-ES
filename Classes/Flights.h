/**
 * @file Flights.h
 * @brief Header file of the Flights class.
 */

#ifndef Project_Air_FLIGHTS_H
#define Project_Air_FLIGHTS_H

#include <string>
using namespace std;

/**
 * @class Flight
 * @brief Represents a flight and its relevant information.
 */
class Flight {
private:
    string source_; ///< Source airport code.
    string target_; ///< Target airport code.
    string airline_; ///< Airline code.

public:
    /**
     * @brief Parameterized constructor for the Flight class.
     * @param source The source airport code.
     * @param target The target airport code.
     * @param airline The airline code for the flight.
     */
    Flight(string source, string target, string airline);

    /**
     * @brief Getter function for the source airport code.
     * @return The source airport code.
     */
    string get_Source() const;

    /**
     * @brief Getter function for the target airport code.
     * @return The target airport code.
     */
    string get_Target() const;

    /**
     * @brief Getter function for the airline code.
     * @return The airline code.
     */
    string get_Airline() const;
    bool operator<(const Flight& other) const ;
    bool operator==(const Flight& other) const;
};

#endif //Project_Air_FLIGHTS_H
