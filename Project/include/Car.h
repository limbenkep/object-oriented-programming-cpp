//
// Created by limbe on 2020-11-16.
//

#ifndef TRAINS_CAR_H
#define TRAINS_CAR_H

#include <iostream>
#include <string>
using namespace std;
class Car
{
private:
    string id;
public:
    Car(const string &id);

    virtual ~Car();
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
    virtual string getCarType()const = 0;
/*
* returns number of chairs in the coach car
*/
    virtual int getNrOfChairs() const{return 0;};
/*
* returns number of beds in the sleeping car
*/
    virtual int getNrOfBeds() const{return 0;};
/*
* returns a bool true if Car has internet or false if it doesnot
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
/*
* returns a bool true if Car has internet options or false if it doesnot
*/
    virtual bool hasInternet(){return false;};
/*
* returns a bool true if Car has beds or false if it doesnot
*/
    virtual bool hasBeds(){return false;};
/*
* returns a bool true if Car has chairs or false if it doesnot
*/
    virtual bool hasChairs(){return false;};
/*
* returns a bool true if Car has capacity propertty or false if it doesnot
*/
    virtual bool hasCapacity(){return false;};
/*
* returns a bool true if Car has opened floor or false if it doesnot
*/
    virtual bool hasFloorArea(){return false;};





};


#endif //TRAINS_CAR_H
