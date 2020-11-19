//
// Created by limbe on 2020-11-16.
//

#include "ElectricEngine.h"

ElectricEngine::ElectricEngine(const string &id, int maxSpeed, int maxPower) : Vehicle(id), maxSpeed(maxSpeed), maxPower(maxPower)

{
}

ElectricEngine::~ElectricEngine()
{

}

int ElectricEngine::getMaxPower() const
{
    return maxPower;
}

void ElectricEngine::setMaxPower(int pMaxPower)
{
    maxPower = pMaxPower;
}

string ElectricEngine::getVehicleType() const
{
    return "Electrical";
}

int ElectricEngine::getMaxSpeed() const
{
    return maxSpeed;
}

void ElectricEngine::setMaxSpeed(int pMaxSpeed)
{
    maxSpeed = pMaxSpeed;
}


