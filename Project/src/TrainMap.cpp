//
// Created by limbe on 2020-11-20.
//

#include "TrainMap.h"

TrainMap::TrainMap()
{
}

TrainMap::TrainMap(const string &name1, const string &name2, int pDistance) : station1(name1),
                                                                              station2(name2),
                                                                              distance(pDistance)
{
}

TrainMap::~TrainMap()
{

}

const string &TrainMap::getStation1() const
{
    return station1;
}

void TrainMap::setStation1(const string &pStation1)
{
    station1 = pStation1;
}

const string &TrainMap::getStation2() const
{
    return station2;
}

void TrainMap::setStation2(const string &pStation2)
{
    station2 = pStation2;
}

int TrainMap::getDistance() const
{
    return distance;
}

void TrainMap::setDistance(int pDistance)
{
    distance = pDistance;
}

void TrainMap::readMapFromFile(ifstream &inFile)
{
    inFile >> station1;
    inFile >> station2;
    inFile >> distance;
}

void TrainMap::printMap()
{
    cout << "Station 1: " << station1 << ", Station 2: " << station2 << ", Distance: " << distance << endl;
}

int TrainMap::getDistanceFromDestinations(const string &departure, const string &arrival)
{
    if ((departure == station1 && arrival == station2) ||(departure == station2 && arrival == station1))
    {
        return distance;
    }
}




