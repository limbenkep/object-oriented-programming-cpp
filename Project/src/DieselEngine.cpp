//
// Created by limbe on 2020-11-16.
//

#include "DieselEngine.h"

DieselEngine::DieselEngine(int pMaxSpeed, int amount) : Engine(pMaxSpeed), consumption(amount)
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

string DieselEngine::getEngineType() const
{
    return "Diesel";
}
