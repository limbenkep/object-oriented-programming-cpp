//
// Created by limbe on 2020-11-16.
//

#include "Station.h"

Station::Station()
{
}

Station::Station(const string &pName) : name(pName)
{
}

Station::~Station()
{

}

const string &Station::getName() const
{
    return name;
}

void Station::setName(const string &pName)
{
    name = pName;
}

void Station::addVehicle(int pType, shared_ptr<Vehicle> &vehicle)
{
    vehicles[pType].push_back(vehicle);
}

/*void Station::addEngine(string &pType, shared_ptr<Engine> &engine)
{
    engines[pType].push_back(engine);
}*/

template<typename T>
void Station::sortVector(vector<T> &vec)
{
    sort( vec.begin( ), vec.end( ), [&vec]( const T& lhs, const T& rhs )
    {
        return lhs < rhs;
    });

}

bool Station::getVehicle(int type, shared_ptr<Vehicle> &vehicle)
{
    auto it = vehicles.find(type);
    if(it==vehicles.end())
    {
        return false;
    }
    else{
        vector<shared_ptr<Vehicle>>vec;
        vec = vehicles[type];
        if(vec.empty())
        {
            return false;
        }
        sortVector(vec);
        vehicle = vec[0];
        auto toDelete = vec[0];
        return true;
    }

}

void Station::readFromFile(istream &inputFile)
{

    string tmpId, waste;
    int tmpType;
    int parameter1;
    int parameter2;
    inputFile >> name;
    inputFile>>waste;
    inputFile >> tmpId;
    inputFile >> tmpType;
    inputFile>> parameter1;
    inputFile>> parameter2;
    inputFile>>waste;

    if(tmpType==0)
    {
        shared_ptr<Vehicle> vehicle(new Coach(tmpId, parameter1, parameter2));
        addVehicle(tmpType, vehicle);
    }
    else if(tmpType ==1)
    {
        shared_ptr<Vehicle> vehicle(new SleepingCar(tmpId, parameter1));
        addVehicle(tmpType, vehicle);
    }
    else if(tmpType==2)
    {
        shared_ptr<Vehicle> vehicle(new OpenFreightCar(tmpId, parameter1, parameter2));
        addVehicle(tmpType, vehicle);
    }
    else if(tmpType==3)
    {
        shared_ptr<Vehicle> vehicle(new CoveredFreightCar(tmpId, parameter1));
        addVehicle(tmpType, vehicle);
    }
    else if(tmpType==4)
    {
        shared_ptr<Vehicle> vehicle(new ElectricEngine(tmpId, parameter1, parameter2));
        addVehicle(tmpType, vehicle);
    }
    else if(tmpType==5)
    {
        shared_ptr<Vehicle> vehicle(new DieselEngine(tmpId, parameter1, parameter2));
        addVehicle(tmpType, vehicle);
    } else{
        cout << "An unknowm Car type " << tmpType << " was read from file" << endl;
    }

}


