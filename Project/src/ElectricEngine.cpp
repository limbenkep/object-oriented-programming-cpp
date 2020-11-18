//
// Created by limbe on 2020-11-16.
//

#include "ElectricEngine.h"

ElectricEngine::ElectricEngine(int pMaxSpeed, int pMaxPower) : Engine(pMaxSpeed), maxPower(pMaxPower)
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

string ElectricEngine::getEngineType() const
{
    return "Electrical";
}
