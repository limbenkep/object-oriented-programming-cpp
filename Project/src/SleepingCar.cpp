//
// Created by limbe on 2020-11-16.
//

#include "SleepingCar.h"

SleepingCar::SleepingCar(int pId, int pNrOfBeds) : Vehicle(pId), nrOfBeds(pNrOfBeds)
{
}

SleepingCar::~SleepingCar()
{

}

int SleepingCar::getVehicleType() const
{
    return 1;
}

int SleepingCar::getNrOfBeds() const
{
    return nrOfBeds;
}

void SleepingCar::printVehicle() const
{
    cout<< "Sleeping car, Type:" << getVehicleType() <<  ", id: " << id << ", Number of beds: " << nrOfBeds <<endl;

}
