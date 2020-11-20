//
// Created by limbe on 2020-11-16.
//

#include "OpenFreightCar.h"

OpenFreightCar::OpenFreightCar(int pId, int pCapacity, int floorArea) : CoveredFreightCar(pId, pCapacity),
                                                                                  floorArea(floorArea)
{
}

OpenFreightCar::~OpenFreightCar()
{

}

int OpenFreightCar::getVehicleType() const
{
    return 2;
}

int OpenFreightCar::getCapacity() const
{
    return CoveredFreightCar::getCapacity();
}

int OpenFreightCar::getFloorArea() const
{
    return floorArea;
}

void OpenFreightCar::printVehicle() const
{
    cout<< "Open freight car, Type:" << getVehicleType() <<  ", id: " << id << ", Capacity: " << capacity<< "cubic meters, Floor area: " << floorArea <<"liters/h" <<endl;
}

/*void OpenFreightCar::readVehicle(ifstream &inputFile)
{
    string pType;
    inputFile>>id;
    inputFile>>pType;
    inputFile>> capacity;
    inputFile>> floorArea;
}*/
