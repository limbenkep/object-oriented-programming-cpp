//
// Created by limbe on 2020-11-16.
//

#include "CoveredFreightCar.h"

CoveredFreightCar::CoveredFreightCar(const string &pId, int Capacity) : Vehicle(pId), capacity(Capacity)
{
}

CoveredFreightCar::~CoveredFreightCar()
{

}

string CoveredFreightCar::getVehicleType() const
{
    return "Covered freight";
}

int CoveredFreightCar::getCapacity() const
{
    return capacity;
}
