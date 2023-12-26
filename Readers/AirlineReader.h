#ifndef Project_Air_AIRLINEREADER_H
#define Project_Air_AIRLINEREADER_H

#include <fstream>
#include <iostream>
#include <string>
#include <list>
#include <map>
#include <fstream>
#include "../Classes/Airline.h"
#include <list>
#include <map>
#include <vector>
#include <set>
#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;

vector<Airline> airlines;

void AirlineReader() {

    string FILENAME = "dataset/airlines.csv";
    ifstream file;
    string file_text;
    file.open(FILENAME);

    getline(file, file_text);

    while(!file.eof()) {

        getline(file, file_text, ',');
        string AirlineCode = file_text;

        getline(file, file_text, ',');
        string AirlineName = file_text;

        getline(file, file_text, ',');
        string Callsign = file_text;

        getline(file, file_text);
        string Country = file_text;

        airlines.emplace_back(AirlineCode,AirlineName,Callsign,Country);

    }
    file.close();
}



#endif //Project_Air_AIRLINEREADER_H
