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
           // cout<< "Missing vehicle type " << idx << endl;
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
    MyTime endSim;
    endSim.setHours(23);
    endSim.setMinutes(49);
    endSim.setSeconds(0);
    if(time<endSim)
    {
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
    else{
        train.printTrain();
        cout << "Train never left station due to missing vehicle" << endl;
    }


}

void AssembledEvent::processEvent()
{
    train.setStatus(TrainState::Ready);
    Event_ptr e(new ReadyEvent(train.getDepartureTime(), train, theSim, theCom));
    theSim->scheduleEvent(e);
    train.printTrain();
    cout << "is ready for departure, departure from platform at " << train.getDepartureTime()<<endl;

}

void ReadyEvent::processEvent()
{
    train.setStatus(TrainState::Running);
    train.setSpeed();
    Event_ptr e(new RunningEvent(train.getArrivalTime(), train, theSim, theCom));
    theSim->scheduleEvent(e);
    train.printTrain();
    cout << "has departed, arriving destination at " << train.getArrivalTime() << endl;
}

void RunningEvent::processEvent()
{
    train.setStatus(TrainState::Arrived);
    Event_ptr e(new ArrivedEvent(train.getArrivalTime(), train, theSim, theCom));
    theSim->scheduleEvent(e);
    train.printTrain();
    cout << "has arrived destination at " << train.getArrivalTime() << endl;

}


void ArrivedEvent::processEvent()
{
    train.setStatus(TrainState::Finished);
    int finishTime = train.getArrivalTime().timeToSeconds() + (20*60);
    MyTime newTime;
    newTime.setTime(finishTime);
    Event_ptr e(new FinishEvent(newTime, train, theSim, theCom));
    theSim->scheduleEvent(e);
    train.printTrain();
    cout << "has arrived destination at " << train.getArrivalTime() << endl;

}

void FinishEvent::processEvent()
{
    theCom->returnVehicleToStation(train);
}
