//
// Created by limbe on 2020-11-16.
//

#ifndef TRAINS_VEHICLE_H
#define TRAINS_VEHICLE_H

#include <iostream>
#include <string>
using namespace std;
class Vehicle
{
private:
    string id;
public:
    Vehicle(const string &id);

    virtual ~Vehicle();
/*
* returns car id
*/
    const string &getId() const;
/*
* sets the car id with passed value
*/
    void setId(const string &pId);
/*
* returns car type
*/
    virtual string getVehicleType()const = 0;
/*
* returns number of chairs in the coach car
*/
    virtual int getNrOfChairs() const{return 0;};
/*
* returns number of beds in the sleeping car
*/
    virtual int getNrOfBeds() const{return 0;};
/*
* returns a bool true if Vehicle has internet or false if it doesnot
*/
    virtual bool getInternet() const {return false;};
/*
* returns the capacity of the car
*/
    virtual int getCapacity() const{return 0;};

/*
* returns the floor area of the car
*/
    virtual int getFloorArea() const{return 0;};



    //virtual void setNrOfChairs(int pNrOfChairs){};

    /**
   *
   * @return maximum speed as an integer
   */
     virtual int getMaxSpeed() const{return 0;};
/**
 * sets the maximum speed
 * @param pMaxSpeed
 */
    virtual void setMaxSpeed(int pMaxSpeed){};
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
   // virtual string getEngineType() const=0;


/*
* returns a bool true if Vehicle has internet options or false if it doesnot
*/
    virtual bool hasInternet(){return false;};
/*
* returns a bool true if Vehicle has beds or false if it doesnot
*/
    virtual bool hasBeds(){return false;};
/*
* returns a bool true if Vehicle has chairs or false if it doesnot
*/
    virtual bool hasChairs(){return false;};
/*
* returns a bool true if Vehicle has capacity propertty or false if it doesnot
*/
    virtual bool hasCapacity(){return false;};
/*
* returns a bool true if Vehicle has opened floor or false if it doesnot
*/
    virtual bool hasFloorArea(){return false;};


/**
 *
 * @param car
 * @return
 */
    bool operator<(const Vehicle &car) const;





};


#endif //TRAINS_VEHICLE_H
