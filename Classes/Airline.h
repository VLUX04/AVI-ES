#ifndef Project_Air_AIRLINE_H
#define Project_Air_AIRLINE_H

#include <string>
using namespace std;

/**
 * @class Airline
 * @brief Represents an airline and its respective relevant information.
 */
class Airline {
private:
    string airlineCode_; ///< The code of the airline.
    string airlineName_; ///< The name of the airline.
    string callSign_; ///< Airline call sign.
    string country_; ///< Country where the airline is based.

public:
    /**
     * @brief Parameterized constructor for the Airline class.
     * @param airlineCode The code of the airline.
     * @param airlineName The name of the airline.
     * @param callSign The call sign of the airline.
     * @param country The country where the airline is based.
     */
    Airline(string airlineCode, string airlineName, string callSign, string country);

    /**
     * @brief Getter function for the airline code.
     * @return The airline code.
     */
    string get_AirlineCode() const;

    /**
     * @brief Getter function for the airline name.
     * @return The airline name.
     */
    string get_AirlineName() const;

    /**
     * @brief Getter function for the call sign of the airline.
     * @return The call sign.
     */
    string get_CallSign() const;

    /**
     * @brief Getter function for the country where the airline is based.
     * @return The country.
     */
    string get_Country() const;
};

#endif //Project_Air_AIRLINE_H