//
// Created by limbe on 2020-11-16.
//

#include "Engine.h"

Engine::Engine(int pMaxSpeed) : maxSpeed(pMaxSpeed)
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
