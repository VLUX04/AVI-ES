/**
 * @file Airport.h
 * @brief Header file of the Airport class.
 */

#ifndef Project_Air_AIRPORT_H
#define Project_Air_AIRPORT_H

#include <string>
using namespace std;

/**
 * @class Airport
 * @brief Represents an airport and its respective relevant information.
 */
class Airport {
private:
    string airportCode_; ///< The code of the airport.
    string airportName_; ///< The name of the airport.
    string city_; ///< City where the airport is located.
    string country_; ///< Country where the airport is located.
    double latitude_; ///< Latitude of the airport's location.
    double longitude_; ///< Longitude of the airport's location.

public:
    /**
     * @brief Default constructor for the Airport class.
     */
    Airport();

    /**
     * @brief Parameterized constructor for the Airport class.
     * @param airportCode The code of the airport.
     * @param airportName The name of the airport.
     * @param city The city where the airport is located.
     * @param country The country where the airport is located.
     * @param latitude The latitude of the airport's location.
     * @param longitude The longitude of the airport's location.
     */
    Airport(string airportCode, string airportName, string city, string country, double latitude, double longitude);

    /**
     * @brief Getter function for the airport code.
     * @return The airport code.
     */
    string get_AirportCode() const;

    /**
    * @brief Getter function for the airport name.
    * @return The airport name.
    */
    string get_AirportName() const;

    /**
     * @brief Getter function for the city where the airport is located.
     * @return The city's name.
     */
    string get_City() const;

    /**
     * @brief Getter function for the country where the airport is located.
     * @return The country's name.
     */
    string get_Country() const;

    /**
     * @brief Getter function for the latitude of the airport's location.
     * @return The latitude.
     */
    double get_Latitude() const;

    /**
     * @brief Getter function for the longitude of the airport's location.
     * @return The longitude.
     */
    double get_Longitude() const;
};

#endif //Project_Air_AIRPORT_H
