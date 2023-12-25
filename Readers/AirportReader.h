//
// Created by psclr on 29/11/2023.
//

#ifndef Project_Air_AIRPORTREADER_H
#define Project_Air_AIRPORTREADER_H


#include <list>
#include <fstream>
#include <iostream>
#include "../Classes/Airport.h"

using namespace std;

void AirportReader() {


    vector<Airport> airports;


    string FILENAME = "dataset/airports.csv";
    ifstream file;
    string file_text;
    file.open(FILENAME);

    getline(file, file_text);

    while(!file.eof()) {

        getline(file, file_text, ',');
        string AirportCode = file_text;

        getline(file, file_text, ',');
        string AirportName = file_text;

        getline(file, file_text, ',');
        string City = file_text;

        getline(file, file_text, ',');
        string Country = file_text;

        getline(file, file_text, ',');
        string helper = file_text;
        double Latitude = atof(helper.c_str());

        getline(file, file_text);
        helper = file_text;
        double Longitude = atof(helper.c_str());

        airports.emplace_back(AirportCode,AirportName,City,Country,Latitude,Longitude);

    }
    cout << airports.size() << endl;
    file.close();


}


#endif //Project_Air_AIRPORTREADER_H
