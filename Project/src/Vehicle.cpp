//
// Created by limbe on 2020-11-16.
//

#include "Vehicle.h"

Vehicle::Vehicle(const int id) : id(id)
{
}

Vehicle::~Vehicle()
{

}

int Vehicle::getId() const
{
    return id;
}

void Vehicle::setId(int pId)
{
    id = pId;
}

bool Vehicle::operator<(const Vehicle &car) const
{
    return id < car.id;
}
