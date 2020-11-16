//
// Created by limbe on 2020-11-16.
//

#ifndef TRAINS_COACH_H
#define TRAINS_COACH_H
#include "Car.h"

class Coach:public Car
{
private:
    int nrOfChairs;
    bool internet;
public:
    Coach(const string &id, int nrOfChairs, bool internet);

    virtual ~Coach();



/*
* returns car type
*/
    virtual string getCarType()const;
/*
* returns number of chairs in the coach car
*/
    virtual int getNrOfChairs() const;

/*
* returns a bool true if Car has internet or false if it doesnot
*/
    virtual bool getInternet() const;

    /*
* returns a bool true if Car has internet options or false if it doesnot
*/
    virtual bool hasInternet(){return true;};
/*
* returns a bool true if Car has beds or false if it doesnot
*/
    virtual bool hasBeds(){return false;};
/*
* returns a bool true if Car has chairs or false if it doesnot
*/
    virtual bool hasChairs(){return true;};
/*
* returns a bool true if Car has capacity propertty or false if it doesnot
*/
    virtual bool hasCapacity(){return false;};
/*
* returns a bool true if Car has opened floor or false if it doesnot
*/
    virtual bool hasFloorArea(){return false;};




};


#endif //TRAINS_COACH_H
