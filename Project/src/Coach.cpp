//
// Created by limbe on 2020-11-16.
//

#include "Coach.h"

Coach::Coach(int id, int nrOfChairs, bool internet) : Vehicle(id), nrOfChairs(nrOfChairs), internet(internet)
{
}

Coach::~Coach()
{

}

int Coach::getVehicleType() const
{
    return 0;
}

int Coach::getNrOfChairs() const
{
    return nrOfChairs;
}

bool Coach::getInternet() const
{
    return internet;
}

void Coach::printVehicle() const
{
    cout<< "Coach Vehicle Type:" << getVehicleType() <<  ", id: " << id << ", Nunber of Chairs: " << nrOfChairs << ", Internet: " << internet << endl;

}

/*void Coach::readVehicle(ifstream &inputFile)
{
    string pType;
    inputFile>>id;
    inputFile>>pType;
    inputFile>> nrOfChairs;
    inputFile>> internet;
}*/
