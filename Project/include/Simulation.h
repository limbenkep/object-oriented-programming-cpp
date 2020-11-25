//
// Created by limbe on 2020-11-25.
//

#ifndef TRAINS_SIMULATION_H
#define TRAINS_SIMULATION_H

#include <queue>
#include <vector>
#include "Event.h"
#include <MyTime.h>

using std::priority_queue;
using std::vector;
typedef shared_ptr<Event> Event_ptr;

class Simulation
{
public:
    Simulation() : currentTime(0, 0, 0), eventQueue()
    {
    }

    ~Simulation() = default;

    // Add a new event to event queue.
    void scheduleEvent(Event_ptr &newEvent);

    int getTimeInSec() const
    {
        return currentTime.timeToSeconds();
    }

    MyTime getTime() const
    {
        return currentTime;
    }

    void run();


private:
    MyTime currentTime; // Time for last processed event

    /* The event queue. Always sorted with respect to the times
       for the events. The event with the 'smallest' time is always
       placed first in queue and will be processed next. */

    priority_queue<Event_ptr, vector<Event_ptr>, EventComparison> eventQueue;
};


#endif //TRAINS_SIMULATION_H
