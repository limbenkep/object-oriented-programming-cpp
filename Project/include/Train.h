//
// Created by limbe on 2020-11-18.
//

#ifndef TRAINS_TRAIN_H
#define TRAINS_TRAIN_H
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include "MyTime.h"
using namespace std;


class Train
{
private:
    int trainId; //the train number
    string departure; // name of the departure station
    string destination;//name of the destination station
    MyTime departureTime;// Train's time of departure
    MyTime arrivalTime;// Train's time of arrival
    int maxSpeed; //// Train's max speed
    vector<int>vehicleType; //states the types of vehicle and engine that makes the train

public:
    Train(int pTrainId);

    Train(int trainId, const string &departure, const string &arrival, const MyTime &departureTime,
          const MyTime &arrivalTime, int maxSpeed);

    virtual ~Train();

/**
 * returns the train number
 * @return int
 */
    int getTrainId() const;

/**
 * receives train nr as an argument and assigns it to data member "trainId"
 * @param pTrainId
 */
    void setTrainId(int pTrainId);

/**
 * returns the name of departure station as a string
 * @return
 */
    const string &getDeparture() const;

/**
 * receives name of the station of departure as an argument and assigns it to data member "departure"
 * @param station
 */
    void setDeparture(const string &station);

/**
 *
 * @return the name of destination station as a string
 */
    const string &getDestination() const;

/**
 * receives name of the station of destination as an argument and assigns it to the corresponding data member
 * @param station
 */
    void setDestination(const string &station);

/**
 *
 * @return the departure time of the train
 */
    const MyTime &getDepartureTime() const;

/**
 * receives the departure time as an argument and assigns it to the corresponding data member
 * @param
 */
    void setDepartureTime(const MyTime &time);

/**
 *
 * @return arrival time of the train
 */
    const MyTime &getArrivalTime() const;

/**
 * receives the time of arrival at destination as an argument and assigns it to the corresponding data member
 * @param time
 */
    void setArrivalTime(const MyTime &time);

/**
 *
 * @return maximum speed
 */
    int getMaxSpeed() const;

/**
 * sets maximum speed
 * @param speed
 */
    void setMaxSpeed(int speed);
/**
 * adds a vehicle type to the types of vehicle that makes up the train
 * @param pType a vehicle type
 */
    void addVehicleType(int pType);
    void readTrainFromFile(ifstream &inFile);
};


#endif //TRAINS_TRAIN_H
