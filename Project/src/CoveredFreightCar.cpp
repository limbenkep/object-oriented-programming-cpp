//
// Created by limbe on 2020-11-16.
//

#include "CoveredFreightCar.h"

CoveredFreightCar::CoveredFreightCar(const string &pId, int Capacity) : Car(pId), capacity(Capacity)
{
}

CoveredFreightCar::~CoveredFreightCar()
{

}

string CoveredFreightCar::getCarType() const
{
    return "Covered freight";
}

int CoveredFreightCar::getCapacity() const
{
    return capacity;
}
