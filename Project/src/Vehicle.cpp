//
// Created by limbe on 2020-11-16.
//

#include "Vehicle.h"

Vehicle::Vehicle(const string &id) : id(id)
{
}

Vehicle::~Vehicle()
{

}

const string &Vehicle::getId() const
{
    return id;
}

void Vehicle::setId(const string &pId)
{
    id = pId;
}

bool Vehicle::operator<(const Vehicle &car) const
{
    return id < car.id;
}
