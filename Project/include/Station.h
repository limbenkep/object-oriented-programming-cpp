//
// Created by limbe on 2020-11-16.
//

#ifndef TRAINS_STATION_H
#define TRAINS_STATION_H
#include "Vehicle.h"
#include "Coach.h"
#include "SleepingCar.h"
#include "CoveredFreightCar.h"
#include "OpenFreightCar.h"
#include "ElectricEngine.h"
#include "DieselEngine.h"
#include "Engine.h"
#include <iostream>
#include <sstream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>
using namespace std;
typedef map<int, vector<shared_ptr<Vehicle>>> VehicleMap;
class Station
{
private:

    string name;
    //vector<shared_ptr<Vehicle>>cars;
    //vector<shared_ptr<Engine>>engines;
    VehicleMap vehicles;
   // map<string, vector<shared_ptr<Engine>>>engines;
public:
    Station();

    explicit Station(const string &pName);

    virtual ~Station();
/**
 * returns the station name
 * @return
 */
    const string &getName() const;
/**
 * sets station name with value passed
 * @param pName
 */
    void setName(const string &pName);
/**
 * receives a Vehicle object and the type of engine and stores it in a container containing the stations engines
 * @param pType type of Vehicle
 * @param engine Engine object with all its properties
 */
    void addVehicle(shared_ptr<Vehicle>&vehicle);
/**
 * receives an engine and the type of engine and stores it in a container containing the stations engines
 * @param pType type of Engine
 * @param engine Engine object with all its properties
 */
   // void addEngine(string &pType, shared_ptr<Engine>&engine);
/**
 * This function checks for the received type of engine and if found returns by reference the engine object of that type with the lowest ID
 * @param type engine type
 * @param engine pointer to hold the engine found to be returned
 * @return true if the engine of the given type if found and false if not found
 */
    //bool getEngine(string &type, shared_ptr<Engine>&engine);
/**
 * This function checks for the received type of Vehicle and if found returns by reference the car object of that type with the lowest ID
 * @param type Vehicle type
 * @param engine pointer to hold the engine found to be returned
 * @return true if the vehicle of the given type if found and false if not found
 */
    bool getVehicle(int type, shared_ptr<Vehicle>&vehicle);

    template<typename T>
    void sortVector(vector<T>&vec);
    //virtual void readFromFile(istream &inputFile){};

    void readFromFile(ifstream &ifs) ;

    VehicleMap getStationVehicles() const;

};


#endif //TRAINS_STATION_H
