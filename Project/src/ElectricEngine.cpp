//
// Created by limbe on 2020-11-16.
//

#include "ElectricEngine.h"

ElectricEngine::ElectricEngine(int id, int maxSpeed, int maxPower) : Vehicle(id), maxSpeed(maxSpeed), maxPower(maxPower)

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

int ElectricEngine::getVehicleType() const
{
    return 4;
}

int ElectricEngine::getMaxSpeed() const
{
    return maxSpeed;
}

void ElectricEngine::setMaxSpeed(int pMaxSpeed)
{
    maxSpeed = pMaxSpeed;
}

void ElectricEngine::printVehicle() const
{
    cout<< "Electric engine, Type:" << getVehicleType() <<  ", id: " << id << ", Max speed: " << maxSpeed<< "km/h, Power: " << maxPower <<"kW" <<endl;
}

/*void ElectricEngine::readVehicle(ifstream &inputFile)
{
    string pType;
    inputFile>>id;
    inputFile>>pType;
    inputFile>> maxSpeed;
    inputFile>> maxPower;
}*/


