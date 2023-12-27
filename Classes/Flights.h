#ifndef Project_Air_FLIGHTS_H
#define Project_Air_FLIGHTS_H

#include <string>
using namespace std;


class Flight {
private:
    string source_;
    string target_;
    string airline_;

public:
    Flight(string source, string target, string airline);
    string get_Source() const;
    string get_Target() const;
    string get_Airline() const;
};


#endif //Project_Air_FLIGHTS_H
