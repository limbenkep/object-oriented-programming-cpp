//
// Created by limbe on 2020-11-16.
//

#ifndef TRAINS_DIESELENGINE_H
#define TRAINS_DIESELENGINE_H
#include "Vehicle.h"


class DieselEngine:public Vehicle
{
private:
    int maxSpeed;
    int consumption;
public:
    DieselEngine(int id, int maxSpeed, int consumption);

    virtual ~DieselEngine();

    virtual int getMaxSpeed() const;

    virtual void setMaxSpeed(int pMaxSpeed);
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
    virtual int getVehicleType() const;

/**
 * reads vehicle from a file
 */
    //virtual void readVehicle(ifstream &inputFile);
    void printVehicle() const override;
};


#endif //TRAINS_DIESELENGINE_H
