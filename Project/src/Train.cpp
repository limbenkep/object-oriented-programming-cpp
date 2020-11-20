//
// Created by limbe on 2020-11-18.
//

#include "Train.h"

Train::Train(int pTrainId) : trainId(pTrainId), maxSpeed(0)
{
}

Train::Train(int trainId, const string &departure, const string &arrival, const MyTime &departureTime,
             const MyTime &arrivalTime, int maxSpeed) : trainId(trainId), departure(departure), destination(arrival),
                                                        departureTime(departureTime), arrivalTime(arrivalTime),
                                                        maxSpeed(maxSpeed)
{
}

Train::~Train()
{

}

int Train::getTrainId() const
{
    return trainId;
}

void Train::setTrainId(int pTrainId)
{
    trainId = pTrainId;
}

const string &Train::getDeparture() const
{
    return departure;
}

void Train::setDeparture(const string &station)
{
    departure = station;
}

const string &Train::getDestination() const
{
    return destination;
}

void Train::setDestination(const string &station)
{
    destination = station;
}

const MyTime &Train::getDepartureTime() const
{
    return departureTime;
}

void Train::setDepartureTime(const MyTime &time)
{
    departureTime = time;
}

const MyTime &Train::getArrivalTime() const
{
    return arrivalTime;
}

void Train::setArrivalTime(const MyTime &time)
{
    arrivalTime = time;
}

int Train::getMaxSpeed() const
{
    return maxSpeed;
}

void Train::setMaxSpeed(int speed)
{
    maxSpeed = speed;
}

void Train::addVehicleType(int pType)
{
    vehicleType.push_back(pType);
}

void Train::readTrainFromFile(ifstream &inFile)
{


    std::string line;
    std::getline(inFile, line);

    std::istringstream iss(line);
    iss >> trainId >> departure >> destination >> departureTime >> arrivalTime >> maxSpeed;
    int type;
    while (iss >> type)
    {
        addVehicleType(type);
    }
}


