//
// Created by limbe on 2020-11-18.
//

#include "Train.h"

Train::Train() : trainId(0), maxSpeed(0), speed(0)
{
}

Train::Train(int trainId, const string &departure, const string &arrival, const MyTime &departureTime,
             const MyTime &arrivalTime, int maxSpeed) : trainId(trainId), departure(departure), destination(arrival),
                                                        departureTime(departureTime), arrivalTime(arrivalTime),
                                                        maxSpeed(maxSpeed)
{
    status = TrainState::Not_assembled;
    speed = 0;
    delay.setTime(0);

}

Train::~Train()
{

}

int Train::getTrainId() const
{
    return trainId;
}

void Train::setTrainId(int pTrainId)
{
    trainId = pTrainId;
}

const string &Train::getDeparture() const
{
    return departure;
}

void Train::setDeparture(const string &station)
{
    departure = station;
}

const string &Train::getDestination() const
{
    return destination;
}

void Train::setDestination(const string &station)
{
    destination = station;
}

MyTime Train::getDepartureTime()
{

    return (departureTime + delay);
}

void Train::setDepartureTime(const MyTime &time)
{
    departureTime = time;
}

MyTime Train::getArrivalTime()
{
    return arrivalTime + delay;
}

void Train::setArrivalTime(const MyTime &time)
{
    arrivalTime = time;
}

int Train::getSpeed() const
{
    return speed;
}

void Train::setSpeed()
{
    double travelTime = (arrivalTime.timeToSeconds() - departureTime.timeToSeconds())/216000.0;
    cout << " Travel time" << travelTime << endl;
    double travelSpeed = distance/travelTime;
    cout << " Travel speed" << travelSpeed << endl;
    double max_speed = static_cast<double >(maxSpeed);
    if(travelSpeed<max_speed)
    {
        speed= static_cast<int>(travelSpeed);
    }
    else{
        speed = maxSpeed;
        double newTravelTime = distance/max_speed;
        int pDelay = static_cast<int>((newTravelTime-travelTime)*216000.0);
        MyTime newDelay;
        newDelay.setTime(pDelay);
        setDelay(newDelay);
    }

}

int Train::getMaxSpeed() const
{
    return maxSpeed;
}

void Train::setMaxSpeed(int speed)
{
    maxSpeed = speed;
}

void Train::addVehicleType(int pType)
{
    vehicleType.push_back(pType);
}

void Train::readTrainFromFile(ifstream &inFile)
{


    std::string line;
    std::getline(inFile, line);

    std::istringstream iss(line);
    iss >> trainId >> departure >> destination >> departureTime >> arrivalTime >> maxSpeed;
    int type;
    while (iss >> type)
    {
        addVehicleType(type);
    }
}

 void Train::printTrain()
{
    cout << "Train id: " << trainId << ", Departure: " << departure << ", Destination: " << destination
    << ", Departure time: " << departureTime << ", Arrival time: " << arrivalTime << endl;
    cout << departureTime << " Train [" << trainId << "] " << stateDetail[status] << " from " << departure << " "
    << departureTime << " (" << getDepartureTime() << ") delay (" << delay << ") speed = " << speed << "km/h is now "
    << " Distance " << distance << " max speed " << maxSpeed <<endl;

}

const vector<int> &Train::getVehicleType() const
{
    return vehicleType;
}

const vector<shared_ptr<Vehicle>> &Train::getAssembled() const
{
    return assembled;
}

void Train::addAssembled(const shared_ptr<Vehicle> &vehicle)
{
    assembled.push_back(vehicle);
}

TrainState Train::getStatus() const
{
    return status;
}

void Train::setStatus(TrainState pStatus)
{
    status = pStatus;
}

const MyTime & Train::getDelay() const
{
    return delay;
}

void Train::setDelay(MyTime &pTime)
{

    delay =delay + pTime;
}

bool Train::trainIsComplete()
{
    return vehicleType.size() == assembled.size();
}

int Train::getDistance() const
{
    return distance;
}

void Train::setDistance(int pDistance)
{
    distance = pDistance;
}


