//
// Created by limbe on 2020-11-22.
//

#ifndef TRAINS_EVENT_H
#define TRAINS_EVENT_H
//Forward declarations

#include "Train.h"
#include "MyTime.h"
#include "Vehicle.h"
#include <memory>

class Simulation;

class TrainCompany;

typedef shared_ptr<TrainCompany> TrainCompany_ptr;
class Event
{
protected:
    // Time for this event
    MyTime time;
    Train train;
public:
// Constructor requires time of event and train
    Event(const MyTime &time, const Train &train) : time(time), train(train)
    {
    }

    virtual ~Event()
    {
    }

    // Process event by invoking this method
    virtual void processEvent() = 0;

    MyTime getTime() const
    {
        return time;
    }

    // Get time for this event
    int getTimeInSec() const
    {
        return time.timeToSeconds();
    }

    const Train &getTrain() const
    {
        return train;
    }
};

// Used to compare to Events with respect to time
class EventComparison
{
public:
    bool operator()(shared_ptr<Event> &left, shared_ptr<Event> &right)
    {
        return left->getTimeInSec() < right->getTimeInSec();
    }
};

//--- Derived Event-classes ----------------------------------------------------
class NotAssembledEvent : public Event
{
protected:
    Simulation *theSim;
    //TrainCompany *theCom;
    TrainCompany_ptr theCom;

public:
    NotAssembledEvent(const MyTime &time, const Train &train, Simulation *theSim, TrainCompany_ptr &theCom)
            : Event(time, train), theSim(theSim), theCom(theCom)
    {
    }

    virtual ~NotAssembledEvent()
    {

    }

    virtual void processEvent();
};

class AssembledEvent : public Event
{
protected:
    Simulation *theSim;
    TrainCompany_ptr theCom;


public:
    AssembledEvent(const MyTime &time, const Train &train, Simulation *theSim, TrainCompany_ptr &theCom) : Event(time, train), theSim(theSim), theCom(theCom)
    {
    }

    virtual ~AssembledEvent()
    {

    }

    virtual void processEvent();
};

class IncompleteEvent : public Event
{
protected:
    Simulation *theSim;
    TrainCompany_ptr theCom;
    vector<int>missingVehicle;

public:
    IncompleteEvent(const MyTime &time, const Train &train, Simulation *theSim, TrainCompany_ptr &theCom,
                    const vector<int> &missingVehicle) : Event(time, train), theSim(theSim), theCom(theCom),
                                                         missingVehicle(missingVehicle)
    {
    }

    virtual ~IncompleteEvent()
    {

    }

    virtual void processEvent();
};


class ReadyEvent : public Event
{
protected:
    Simulation *theSim;
    //TrainCompany *theCom;

    //Train *train;

public:
    ReadyEvent(const MyTime &time, const Train &train, Simulation *theSim) : Event(time, train), theSim(theSim)
    {
    }

    virtual ~ReadyEvent()
    {

    }

    virtual void processEvent();
};

class RunningEvent : public Event
{

protected:
    Simulation *theSim;
    //TrainCompany *theCom;

public:
    RunningEvent(const MyTime &time, const Train &train, Simulation *theSim) : Event(time, train), theSim(theSim)
    {
    }

    virtual ~RunningEvent()
    {

    }

    virtual void processEvent();
};

class ArrivedEvent : public Event
{
protected:
    Simulation *theSim;
    TrainCompany_ptr theCom;

    //Train *train;

public:
    ArrivedEvent(const MyTime &time, const Train &train, Simulation *theSim, TrainCompany_ptr &theCom) : Event(time, train),
                                                                                                     theSim(theSim),
                                                                                                     theCom(theCom)
    {
    }

    virtual ~ArrivedEvent()
    {

    }

    virtual void processEvent();
};

class FinishEvent : public Event
{
protected:
    Simulation *theSim;
    TrainCompany_ptr theCom;
    //Train *train;

public:
    FinishEvent(const MyTime &time, const Train &train, Simulation *theSim, TrainCompany_ptr &theCom) : Event(time, train),
                                                                                                    theSim(theSim),
                                                                                                    theCom(theCom)
    {
    }

    virtual ~FinishEvent()
    {
    }

    virtual void processEvent();
};


#endif //TRAINS_EVENT_H
