//
// Created by limbe on 2020-11-22.
//

#ifndef TRAINS_UTILITIES_H
#define TRAINS_UTILITIES_H

#endif //TRAINS_UTILITIES_H

#include <map>
#include <string>



using namespace std;

const string trainFile("Trains.txt");
const string stationFile("TrainStations.txt");
const string mapFile("TrainMap.txt");

enum class TrainState{Not_assembled,Incomplete, Assembled, Ready, Running, Arrived, Finished};
enum class VehicleType{ Coach, SleepingCar, OpenFreight, CoveredFreight, ElectricEngine, DieselEngine};
