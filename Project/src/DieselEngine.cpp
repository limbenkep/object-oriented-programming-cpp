//
// Created by limbe on 2020-11-16.
//

#include "DieselEngine.h"

DieselEngine::DieselEngine(int id, int maxSpeed, int consumption) : Vehicle(id), maxSpeed(maxSpeed),
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

int DieselEngine::getVehicleType() const
{
    return 5;
}

int DieselEngine::getMaxSpeed() const
{
    return maxSpeed;
}

void DieselEngine::setMaxSpeed(int pMaxSpeed)
{
    maxSpeed = pMaxSpeed;
}

void DieselEngine::printVehicle() const
{
    cout<< "Diesel engine, Type:" << getVehicleType() <<  ", id: " << id << ", Max speed: " << maxSpeed<< "km/h, Fuel consumption: " << consumption <<"liters/h" <<endl;
}

/*void DieselEngine::readVehicle(ifstream &inputFile)
{
    string pType;
    inputFile>>id;
    inputFile>>pType;
    inputFile>> maxSpeed;
    inputFile>> consumption;
}*/

