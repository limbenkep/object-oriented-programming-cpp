//
// Created by limbe on 2020-11-16.
//

#ifndef TRAINS_ENGINE_H
#define TRAINS_ENGINE_H
#include "Vehicle.h"
#include <iostream>
#include <string>
using namespace std;


class Engine: public Vehicle
{
private:
    int maxSpeed;
public:
    Engine(int id, int maxSpeed);


    virtual ~Engine();
/**
 *
 * @return maximum speed as an integer
 */
    int getMaxSpeed() const;
/**
 * sets the maximum speed
 * @param pMaxSpeed
 */
    void setMaxSpeed(int pMaxSpeed);
/**
 * sets the maximum power
 * @param pMaxPower
 */
    virtual void setMaxPower(int pMaxPower){};
/**
 * sets the fuel consumption
 * @param amount
 */
    virtual void setConsumption(int amount){};
/**
 *
 * @return fuel consumption as an integer
 */
    virtual int getConsumption() const{return 0;};
/**
 *
 * @return maximum speed as an integer
 */
    virtual int getMaxPower() const{return 0;};
/**
 *
 * @return maximum speed as an integer
 */
    virtual string getEngineType() const=0;



};


#endif //TRAINS_ENGINE_H
