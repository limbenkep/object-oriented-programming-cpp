//
// Created by limbe on 2020-11-16.
//

#include "Coach.h"

Coach::Coach(const string &id, int nrOfChairs, bool internet) : Vehicle(id), nrOfChairs(nrOfChairs), internet(internet)
{
}

Coach::~Coach()
{

}

string Coach::getVehicleType() const
{
    return "Coach";
}

int Coach::getNrOfChairs() const
{
    return nrOfChairs;
}

bool Coach::getInternet() const
{
    return internet;
}

/*void Coach::readVehicle(ifstream &inputFile)
{
    string pType;
    inputFile>>id;
    inputFile>>pType;
    inputFile>> nrOfChairs;
    inputFile>> internet;
}*/
