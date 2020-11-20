//
// Created by limbe on 2020-11-16.
//

#ifndef TRAINS_ELECTRICENGINE_H
#define TRAINS_ELECTRICENGINE_H
#include "Vehicle.h"

class ElectricEngine: public Vehicle
{
private:
    int maxSpeed;
    int maxPower;


public:
    ElectricEngine(const string &id, int maxSpeed, int maxPower);

    virtual ~ElectricEngine();

    virtual int getMaxSpeed() const;

    virtual void setMaxSpeed(int pMaxSpeed);

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
    virtual string getVehicleType() const;

/**
 * reads vehicle from a file
 */
   // virtual void readVehicle(ifstream &inputFile);


};


#endif //TRAINS_ELECTRICENGINE_H
