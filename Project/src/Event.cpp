//
// Created by limbe on 2020-11-22.
//

#include "Event.h"
#include "TrainCompany.h"
#include "Simulation.h"

typedef shared_ptr<Event> Event_ptr;
void NotAssembledEvent::processEvent()
{
    vector<int>types = train.getVehicleType();
    string station = train.getDeparture();
    shared_ptr<Vehicle> vehicle;
    vector<int>missing;
    for(auto &idx: types)
    {
        if(theCom->getVehicle(station,idx,vehicle))
        {
            train.addAssembled(vehicle);
        }
        else
        {
            missing.push_back(idx);
        }
    }
    if(missing.empty()&&train.trainIsComplete())
    {
        MyTime t = train.getDepartureTime();
        t.subtractSecs(10*60);
        train.setStatus(TrainState::Assembled);
        Event_ptr e(new AssembledEvent(t, train,theSim, theCom));
        theSim->scheduleEvent(e);
        train.printTrain();
        cout << "is now assembled, arriving platform at " << t<<endl;
    } else{
        MyTime delay;
        delay.setTime(10*60);//converting 10mins delay to Time class MyTime format
        train.setDelay(delay);
        train.setStatus(TrainState::Incomplete);
        MyTime newTime = time + delay;
        Event_ptr e(new IncompleteEvent(newTime, train, theSim, theCom, missing));
        theSim->scheduleEvent(e);
        train.printTrain();
        cout << "is Incomplete, new departure time from platform at " << train.getDepartureTime() <<endl;
    }
}

void IncompleteEvent::processEvent()
{
    string station = train.getDeparture();
    shared_ptr<Vehicle> vehicle;
    vector<int>missing;
    for(auto &idx: missingVehicle)
    {
        if(theCom->getVehicle(station,idx,vehicle))
        {
            train.addAssembled(vehicle);
        }
        else
        {
            missing.push_back(idx);
        }
    }
    if(missing.empty()&&train.trainIsComplete())
    {
        train.setStatus(TrainState::Assembled);
        MyTime t = train.getDepartureTime();
        t.subtractSecs(10*60);
        Event_ptr e(new AssembledEvent(t, train,theSim, theCom));
        theSim->scheduleEvent(e);
        train.printTrain();
        cout << "is now assembled, arriving platform at " << t<<endl;
    } else{
        MyTime delay;
        delay.setTime(10*60);//converting 10mins delay to Time class MyTime format
        train.setDelay(delay);
        train.setStatus(TrainState::Incomplete);
        MyTime newTime = time + delay;
        Event_ptr e(new IncompleteEvent(newTime, train, theSim, theCom, missing));
        theSim->scheduleEvent(e);
        train.printTrain();
        cout << "is Incomplete, new departure time from platform at " << train.getDepartureTime() <<endl;
    }

}

void AssembledEvent::processEvent()
{
    train.setStatus(TrainState::Ready);
    Event_ptr e(new ReadyEvent(train.getDepartureTime(), train, theSim));
    theSim->scheduleEvent(e);
    train.printTrain();
    cout << "is ready for departure, departure from platform at " << train.getDepartureTime()<<endl;

}

void ReadyEvent::processEvent()
{
    train.setStatus(TrainState::Running);
    Event_ptr e(new RunningEvent(train.getArrivalTime(), train, theSim));
    theSim->scheduleEvent(e);
    train.printTrain();
    cout << "has departed, arriving destination at " << train.getArrivalTime() << endl;
}

void RunningEvent::processEvent()
{

}
