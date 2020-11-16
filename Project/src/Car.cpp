//
// Created by limbe on 2020-11-16.
//

#include "Car.h"

Car::Car(const string &id) : id(id)
{
}

Car::~Car()
{

}

const string &Car::getId() const
{
    return id;
}

void Car::setId(const string &pId)
{
    id = pId;
}
