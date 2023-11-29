//
// Created by psclr on 29/11/2023.
//

#ifndef AVIÕES_FLIGHTS_H
#define AVIÕES_FLIGHTS_H


class Flight {
private:
    string source_;
    string target_;
    string airline_;

public:
    Flight(string source, string target, string airline);
    string get_Source();
    string get_Target();
    string get_Airline();
};


#endif //AVIÕES_FLIGHTS_H
