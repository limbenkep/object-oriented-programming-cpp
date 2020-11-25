//
// Created by limbe on 2020-11-25.
//

#include "Simulation.h"
#include "Event.h"

// Execute events until event queue is empty
void Simulation::run()

{
    while(!eventQueue.empty()) {
        Event_ptr nextEvent = eventQueue.top();
        eventQueue.pop();
        currentTime = nextEvent->getTime();
        nextEvent->processEvent();
    }
}


void Simulation::scheduleEvent (Event_ptr &newEvent) {
    eventQueue.push (newEvent);
}


