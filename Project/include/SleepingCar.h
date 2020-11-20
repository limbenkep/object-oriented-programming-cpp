//
// Created by limbe on 2020-11-16.
//

#ifndef TRAINS_SLEEPINGCAR_H
#define TRAINS_SLEEPINGCAR_H
#include "Vehicle.h"

class SleepingCar: public Vehicle
{
private:
    int nrOfBeds;
public:
    SleepingCar(const int pId, int pNrOfBeds);

    virtual ~SleepingCar();
    /*
* returns car type
*/
    virtual int getVehicleType()const;
/*
* returns number of chairs in the coach car
*/
    //virtual int getNrOfChairs() const{return 0;};
/*
* returns number of beds in the sleeping car
*/
    virtual int getNrOfBeds() const;
/*
* returns a bool true if Vehicle has internet or false if it doesnot
*/
    //virtual bool getInternet() const {return false;};
/*
* returns the capacity of the car
*/
    //virtual int getCapacity() const{return 0;};

/*
* returns the floor area of the car
*/
   // virtual int getFloorArea() const{return 0;};

    void printVehicle() const override;

    //virtual void setNrOfChairs(int pNrOfChairs){};
/*
* returns a bool true if Vehicle has internet options or false if it doesnot
*/
    virtual bool hasInternet(){return false;};
/*
* returns a bool true if Vehicle has beds or false if it doesnot
*/
    virtual bool hasBeds(){return true;};
/*
* returns a bool true if Vehicle has chairs or false if it doesnot
*/
    virtual bool hasChairs(){return false;};

    /* returns a bool true if Vehicle has capacity propertty or false if it doesnot
    */
    virtual bool hasCapacity(){return false;};
/*
* returns a bool true if Vehicle has opened floor or false if it doesnot
*/
    virtual bool hasFloorArea(){return false;};

};


#endif //TRAINS_SLEEPINGCAR_H
