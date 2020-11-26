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
#include <memory>
#include "MyTime.h"
#include "Vehicle.h"
#include "Utilities.h"
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
    int speed;
    int distance;
    vector<int>vehicleType; //states the types of vehicle and engine that makes the train
    vector<shared_ptr<Vehicle>>assembled; // vector to hold vehicles assembled to train
    TrainState status;
    MyTime delay;
    map<TrainState, string> stateDetail {
            {TrainState::Not_assembled, "(NOT ASSEMBLED)"},
            {TrainState::Assembled, "(ASSEMBLED)"},
            {TrainState::Incomplete, "(INCOMPLETE)"},
            {TrainState::Ready, "(READY)"},
            {TrainState::Running, "(RUNNING)"},
            {TrainState::Arrived, "(ARRIVED)"},
            {TrainState::Finished, "(FINISHED)"}
    };


public:
    Train();

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

    const vector<int> &getVehicleType() const;

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
    MyTime getDepartureTime();

/**
 * receives the departure time as an argument and assigns it to the corresponding data member
 * @param
 */
    void setDepartureTime(const MyTime &time);

/**
 *
 * @return arrival time of the train
 */
    MyTime getArrivalTime();

/**
 * receives the time of arrival at destination as an argument and assigns it to the corresponding data member
 * @param time
 */
    void setArrivalTime(const MyTime &time);

/**
 *
 * @return speed
 */
    int getSpeed() const;

/**
 * sets speed
 * @param speed
 */
    void setSpeed();

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

    int getDistance() const;

    void setDistance(int pDistance);

    const vector<shared_ptr<Vehicle>> &getAssembled() const;

    void addAssembled(const shared_ptr<Vehicle> &vehicle);

    TrainState getStatus() const;

    void setStatus(TrainState pStatus);

    const MyTime & getDelay() const;

    void setDelay(MyTime &pTime);
    bool trainIsComplete();


    void printTrain();
    void readTrainFromFile(ifstream &inFile);
};


#endif //TRAINS_TRAIN_H
