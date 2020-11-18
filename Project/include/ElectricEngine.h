//
// Created by limbe on 2020-11-16.
//

#ifndef TRAINS_ELECTRICENGINE_H
#define TRAINS_ELECTRICENGINE_H
#include "Engine.h"

class ElectricEngine: public Engine
{
private:
    int maxPower;

public:
    ElectricEngine(int pMaxSpeed, int pMaxPower);

    virtual ~ElectricEngine();

    /**
 * sets the maximum power
 * @param pMaxPower
 */
    virtual void setMaxPower(int pMaxPower);
/**
 * sets the fuel consumption
 * @param amount
 */
    //virtual void setConsumption(int amount){};
/**
 *
 * @return fuel consumption as an integer
 */
    //virtual int getConsumption() const{return 0;};
/**
 *
 * @return maximum speed as an integer
 */
    virtual int getMaxPower() const;
/**
 *
 * @return maximum speed as an integer
 */
    virtual string getEngineType() const;


};


#endif //TRAINS_ELECTRICENGINE_H
