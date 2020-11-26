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
/**
 * reads trains from predefined file and stores in a vector
 */
    void readTrainsFromFile();
/**
 * reads train maps containing information on distance between two stations
 * from predefined file and stores in a vector
 */
    void readTrainMapsFromFile();
/**
 * reads stations from predefined file and stores in a vector
 */
    void readStationsFromFile();
/**
 * receives a station name and vehicle type and search for vehicle in specified
 * station's pool and return vehicle by assigning it to passed pointer
 * @param stationName name of station
 * @param type vehicle type
 * @param vehicle
 * @return true if vehicle is found or false if vehicle is not found
 */
    bool getVehicle(string &stationName, int type, shared_ptr<Vehicle> &vehicle);

/**
 * This function receives a train and add the vehicles coupled to the train to the destination station's pool of vehicles
 * @param train
 */
    void returnVehicleToStation(Train &train);
/**
 * This function receives a train, finds the TrainMap object whose two stations is
 * same as the train departure and destination and returns the distance between the two stationss
 * @param train
 * @return distance between departure and destination
 */
    int getDistanceOfTrainStations(const Train &train);
    void scheduleNotAssembledTrains();

};


#endif //TRAINS_TRAINCOMPANY_H
