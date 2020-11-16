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





};


#endif //TRAINS_CAR_H
