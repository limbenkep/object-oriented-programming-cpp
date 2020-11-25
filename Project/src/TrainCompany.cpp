//
// Created by limbe on 2020-11-22.
//

#include "TrainCompany.h"

//#include <Utilities.h>
TrainCompany::TrainCompany()
{
    readTrainMapsFromFile();
    readStationsFromFile();
    readTrainsFromFile();
}


TrainCompany::TrainCompany(Simulation *sim) : theSim(sim)
{
    readTrainMapsFromFile();
    readStationsFromFile();
    readTrainsFromFile();
}

TrainCompany::~TrainCompany()
{

}

void TrainCompany::readTrainsFromFile()
{
    std::ifstream trainStream(trainFile);

    Train train;
    if (trainStream)
    {
        while (!trainStream.eof())
        {
            train.readTrainFromFile(trainStream);
            trains.push_back(train);
        }
    } else
    {
        throw runtime_error(trainFile + " file could not be opened");
    }

}

void TrainCompany::readTrainMapsFromFile()
{

    std::ifstream mapStream(mapFile);

    TrainMap trainMap;
    if (mapStream)
    {
        while (!mapStream.eof())
        {
            trainMap.readMapFromFile(mapStream);
            trainMaps.push_back(trainMap);

        }
    } else
    {
        throw runtime_error(mapFile + " file could not be opened");
    }
}

void TrainCompany::readStationsFromFile()
{
    std::ifstream stationStream(stationFile);
    Station station;
    if (stationStream)
    {
        while (!stationStream.eof())
        {
            station.readFromFile(stationStream);
            stations[station.getName()] = station;
        }
    } else
    {
        throw runtime_error(stationFile + " file could not be opened");
    }
}

bool TrainCompany::getVehicle(string &stationName, int type, shared_ptr<Vehicle> &vehicle)
{
    auto it = stations.find(stationName);
    if (it == stations.end())
    {
        return false;
    } else
    {
        return stations[stationName].getVehicle(type, vehicle);
    }
}

int TrainCompany::getDistanceOfTrainStations(const Train &train)
{
    TrainMap trainMap;
    for (auto &tm: trainMaps)
    {
        if ((train.getDestination() == tm.getStation1() && train.getDeparture() == tm.getStation2())
            || (train.getDestination() == tm.getStation2() && train.getDeparture() == tm.getStation1()))
        {
            return tm.getDistance();

        }
    }
    return trainMap.getDistance();
}

void TrainCompany::scheduleNotAssembledTrains()
{

}

