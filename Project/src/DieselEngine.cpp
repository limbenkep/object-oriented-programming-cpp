//
// Created by limbe on 2020-11-16.
//

#include "DieselEngine.h"

DieselEngine::DieselEngine(const string &id, int maxSpeed, int consumption) : Vehicle(id), maxSpeed(maxSpeed),
                                                                              consumption(consumption)
{
}


DieselEngine::~DieselEngine()
{

}

int DieselEngine::getConsumption() const
{
    return consumption;
}

void DieselEngine::setConsumption(int amount)
{
    consumption= amount;
}

string DieselEngine::getVehicleType() const
{
    return "Diesel engine";
}

int DieselEngine::getMaxSpeed() const
{
    return maxSpeed;
}

void DieselEngine::setMaxSpeed(int pMaxSpeed)
{
    maxSpeed = pMaxSpeed;
}

