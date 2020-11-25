//
// Created by limbe on 2020-11-22.
//

#ifndef TRAINS_TRAINCOMPANY_H
#define TRAINS_TRAINCOMPANY_H

#include <vector>
#include <map>
#include "Train.h"
#include "Station.h"
#include "TrainMap.h"
#include "Vehicle.h"
#include "Event.h"

class Simulation;

class TrainCompany
{
    vector<Train> trains;
    map<string, Station>stations;
    vector<TrainMap> trainMaps;
    Simulation *theSim;
public:
    TrainCompany();

    TrainCompany(Simulation *sim);

    virtual ~TrainCompany();

    void readTrainsFromFile();
    void readTrainMapsFromFile();
    void readStationsFromFile();
    bool getVehicle(string &stationName, int type, shared_ptr<Vehicle> &vehicle);

    int getDistanceOfTrainStations(const Train &train);
    void scheduleNotAssembledTrains();

};


#endif //TRAINS_TRAINCOMPANY_H
