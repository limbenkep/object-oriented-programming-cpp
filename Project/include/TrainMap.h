//
// Created by limbe on 2020-11-20.
//

#ifndef TRAINS_TRAINMAP_H
#define TRAINS_TRAINMAP_H
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


class TrainMap
{
private:
    string station1; //Name of first station
    string station2; //Name of second station
    int distance;//distance between the two stations

public:
    TrainMap(const string &name1, const string &name2, int pDistance);

    virtual ~TrainMap();

    const string &getStation1() const;

    void setStation1(const string &pStation1);

    const string &getStation2() const;

    void setStation2(const string &pStation2);

    int getDistance() const;

    void setDistance(int pDistance);
    void readFromFile(ifstream &inFile);

};


#endif //TRAINS_TRAINMAP_H
