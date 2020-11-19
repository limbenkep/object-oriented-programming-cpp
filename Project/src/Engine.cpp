//
// Created by limbe on 2020-11-16.
//

#include "Engine.h"

Engine::Engine(const string &id, int maxSpeed) : Vehicle(id), maxSpeed(maxSpeed)
{
}

Engine::~Engine()
{

}

int Engine::getMaxSpeed() const
{
    return maxSpeed;
}

void Engine::setMaxSpeed(int pMaxSpeed)
{
    maxSpeed = pMaxSpeed;
}



