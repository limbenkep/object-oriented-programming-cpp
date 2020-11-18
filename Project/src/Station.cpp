//
// Created by limbe on 2020-11-16.
//

#include "Station.h"

Station::Station()
{
}

Station::Station(const string &pName) : name(pName)
{
}

Station::~Station()
{

}

const string &Station::getName() const
{
    return name;
}

void Station::setName(const string &pName)
{
    name = pName;
}

void Station::addCar(string &pType, shared_ptr<Car>&car)
{
    cars.insert(make_pair(pType, car));
}

void Station::addEngine(string &pType, shared_ptr<Engine> &engine)
{
    engines.insert(make_pair(pType, engine));
}


