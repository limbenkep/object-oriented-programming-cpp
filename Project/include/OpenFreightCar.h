//
// Created by limbe on 2020-11-16.
//

#ifndef TRAINS_OPENFREIGHTCAR_H
#define TRAINS_OPENFREIGHTCAR_H
#include "CoveredFreightCar.h"

class OpenFreightCar:public CoveredFreightCar
{
private:
    int floorArea;
public:
    OpenFreightCar(const string &pId, int pCapacity, int floorArea);

    virtual ~OpenFreightCar();

/*
* returns car type
*/
    virtual string getCarType()const;
/*
* returns number of chairs in the coach car
*/
    //virtual int getNrOfChairs() const{return 0;};
/*
* returns number of beds in the sleeping car
*/
    //virtual int getNrOfBeds() const{return 0;};
/*
* returns a bool true if Car has internet or false if it doesnot
*/
    //virtual bool getInternet() const {return false;};
/*
* returns the capacity of the car
*/
    virtual int getCapacity() const;

/*
* returns the floor area of the car
*/
    virtual int getFloorArea() const;



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
    virtual bool hasCapacity(){return true;};
/*
* returns a bool true if Car has opened floor or false if it doesnot
*/
    virtual bool hasFloorArea(){return true;};

};


#endif //TRAINS_OPENFREIGHTCAR_H
