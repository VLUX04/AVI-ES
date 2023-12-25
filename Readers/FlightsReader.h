
#ifndef Project_Air_FLIGHTSREADER_H
#define Project_Air_FLIGHTSREADER_H


#include <list>
#include <fstream>
#include <iostream>
#include "../Classes/Flights.h"

using namespace std;

void FlightsReader() {

    vector<Flight> flights;


    string FILENAME = "dataset/flights.csv";
    ifstream file;
    string file_text;
    file.open(FILENAME);

    getline(file, file_text);

    while(!file.eof()) {

        getline(file, file_text, ',');
        string Source = file_text;

        getline(file, file_text, ',');
        string Target = file_text;

        getline(file, file_text);
        string Airline = file_text;

        flights.emplace_back(Source,Target,Airline);

    }
    file.close();

    cout << flights.size()<<endl;

}

#endif //Project_Air_FLIGHTSREADER_H
