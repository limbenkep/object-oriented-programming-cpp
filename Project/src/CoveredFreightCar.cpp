//
// Created by limbe on 2020-11-16.
//

#include "CoveredFreightCar.h"

CoveredFreightCar::CoveredFreightCar(int pId, int Capacity) : Vehicle(pId), capacity(Capacity)
{
}

CoveredFreightCar::~CoveredFreightCar()
{

}

int CoveredFreightCar::getVehicleType() const
{
    return 3;
}

int CoveredFreightCar::getCapacity() const
{
    return capacity;
}

void CoveredFreightCar::printVehicle() const
{
    cout<< "Covered Freight Vehicle Type:" << getVehicleType() <<  ", id: " << id << ", Capacity: " << capacity<< "cubic meter" << endl;
}

/*
void CoveredFreightCar::readVehicle(ifstream &inputFile)
{
    string pType;
    string waste;
    inputFile>>id;
    inputFile>>pType;
    inputFile>> capacity;
    inputFile>> waste;
}
*/
