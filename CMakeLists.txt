cmake_minimum_required(VERSION 3.26)
project(Project_Air)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")

add_executable(Project_Air main.cpp Classes/Airline.cpp Classes/Airline.h Classes/Airport.cpp Classes/Airport.h Classes/Flights.cpp Classes/Flights.h
        Readers/AirlineReader.h Readers/AirportReader.h Readers/FlightsReader.h Readers/Graph.h
        data_storage/Displays.h)
