//
// Created by limbe on 2020-11-16.
//

#include "Coach.h"

Coach::Coach(const string &id, int nrOfChairs, bool internet) : Car(id), nrOfChairs(nrOfChairs), internet(internet)
{
}

Coach::~Coach()
{

}

string Coach::getCarType() const
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
