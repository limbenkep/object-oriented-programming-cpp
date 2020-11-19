//
// Created by limbe on 2020-11-16.
//

#include "SleepingCar.h"

SleepingCar::SleepingCar(const string &pId, int pNrOfBeds) : Vehicle(pId), nrOfBeds(pNrOfBeds)
{
}

SleepingCar::~SleepingCar()
{

}

string SleepingCar::getVehicleType() const
{
    return "Sleeping car";
}

int SleepingCar::getNrOfBeds() const
{
    return nrOfBeds;
}
