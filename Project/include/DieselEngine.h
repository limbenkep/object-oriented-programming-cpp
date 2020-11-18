//
// Created by limbe on 2020-11-16.
//

#ifndef TRAINS_DIESELENGINE_H
#define TRAINS_DIESELENGINE_H
#include "Engine.h"


class DieselEngine:public Engine
{
private:
    int consumption;
public:
    DieselEngine(int pMaxSpeed, int amount);

    virtual ~DieselEngine();
/**
 * sets the maximum power
 * @param pMaxPower
 */
    //virtual void setMaxPower(int pMaxPower){};
/**
 * sets the fuel consumption
 * @param amount
 */
    virtual void setConsumption(int amount);
/**
 *
 * @return fuel consumption as an integer
 */
    virtual int getConsumption() const;
/**
 *
 * @return maximum speed as an integer
 */
    //virtual int getMaxPower() const{return 0;};
/**
 *
 * @return maximum speed as an integer
 */
    virtual string getEngineType() const;

};


#endif //TRAINS_DIESELENGINE_H
