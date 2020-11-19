//
// Created by limbe on 2020-11-16.
//

#include "OpenFreightCar.h"

OpenFreightCar::OpenFreightCar(const string &pId, int pCapacity, int floorArea) : CoveredFreightCar(pId, pCapacity),
                                                                                  floorArea(floorArea)
{
}

OpenFreightCar::~OpenFreightCar()
{

}

string OpenFreightCar::getVehicleType() const
{
    return "Open frieght car";
}

int OpenFreightCar::getCapacity() const
{
    return CoveredFreightCar::getCapacity();
}

int OpenFreightCar::getFloorArea() const
{
    return floorArea;
}
