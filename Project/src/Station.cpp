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

void Station::addVehicle(string &pType, shared_ptr<Vehicle> &vehicle)
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

bool Station::getVehicle(string &type, shared_ptr<Vehicle> &vehicle)
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


