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

void Station::addVehicle(shared_ptr<Vehicle> &vehicle)
{
    vehicles[vehicle->getVehicleType()].push_back(vehicle);
}

/*void Station::addEngine(string &pType, shared_ptr<Engine> &engine)
{
    engines[pType].push_back(engine);
}*/

template<typename T>
void Station::sortVector(vector<T> &vec)
{
    sort(vec.begin(), vec.end(), [&vec](const T &lhs, const T &rhs) {
        return lhs < rhs;
    });

}

bool Station::getVehicle(int type, shared_ptr<Vehicle> &vehicle)
{
    auto it = vehicles.find(type);
    if (it == vehicles.end())
    {
        return false;
    } else
    {
        vector<shared_ptr<Vehicle>> vec;
        vec = vehicles[type];
        if (vec.empty())
        {
            return false;
        }
        sortVector(vec);
        vehicle = vec[0];
        auto toDelete = vec[0];
        return true;
    }

}

/*void Station::readFromFile(istream &inputFile)
{
    string line;
    getline(inputFile, line);
    std::replace(line.begin(), line.end(), ')', ' ');  // replace ':' by ' '
    std::replace(line.begin(), line.end(), '(', ' ');  // replace ':' by ' '
    istringstream iss(line);
    iss >> name;

    int tmpType, tmpId;
    int parameter1;
    int parameter2;
    while (iss >> tmpId >> tmpType >> parameter1 >> parameter2)
    {
      *//*  if (tmpType == 0)
        {
            shared_ptr<Vehicle> vehicle(new Coach(tmpId, parameter1, parameter2));
            addVehicle(vehicle);
        } else if (tmpType == 1)
        {
            shared_ptr<Vehicle> vehicle(new SleepingCar(tmpId, parameter1));
            addVehicle(vehicle);
        } else if (tmpType == 2)
        {
            shared_ptr<Vehicle> vehicle(new OpenFreightCar(tmpId, parameter1, parameter2));
            addVehicle(vehicle);
        } else if (tmpType == 3)
        {
            shared_ptr<Vehicle> vehicle(new CoveredFreightCar(tmpId, parameter1));
            addVehicle(tmpType, vehicle);
        } else if (tmpType == 4)
        {
            shared_ptr<Vehicle> vehicle(new ElectricEngine(tmpId, parameter1, parameter2));
            addVehicle(tmpType, vehicle);
        } else if (tmpType == 5)
        {
            shared_ptr<Vehicle> vehicle(new DieselEngine(tmpId, parameter1, parameter2));
            addVehicle(tmpType, vehicle);
        } else
        {
            cout << "An unknowm Car type " << tmpType << " was read from file" << endl;
        }
    }*//*
}*/

void Station::readFromFile(ifstream &ifs)
{

    string line;
    getline(ifs, line);
    //if(line.empty()) return;
    // get the station name: substring from beginning to first space
    name = line.substr(0, line.find_first_of(' '));
    //Station (x c f d) (x s f f 6)
    shared_ptr<Vehicle> vehicle;
    const char openBracke{'('}, closeBracket{')'};
    while (line.find(openBracke) != std::string::npos)
    {
        try
        {
            // extract rest of line without station name
            line = line.substr(line.find(openBracke));

            size_t openPos = line.find(openBracke);

            size_t closePos = line.find(closeBracket);

            // make sure these positions are defined
            if (openPos != std::string::npos && closePos != std::string::npos)
            {
                // extract numbers withing brackets as string
                string groupOfNumbers = line.substr(openPos + 1, closePos - 1);

                /* std::cout << "Group of numbers " << groupOfNumbers << " Open pos " << openPos << " closePose "
                           << closePos
                           << endl;*/

                // parse numbers with isstringstream object
                istringstream iss(groupOfNumbers);
                int tmpId;

                // tokenize the numbers and store into a vector
                vector<int> numbers;
                while (iss >> tmpId)
                {
                    numbers.push_back(tmpId);
                }
                // iss >>  tmpId >> tmpType>>parameter1>>parameter2;

                if (numbers.at(1) == 0)
                {
                    //iss >> parameter1 >> parameter1;
                     vehicle =  shared_ptr<Vehicle>(new Coach(numbers.at(0), numbers.at(2), numbers.at(3)));
                    addVehicle(vehicle);
                } else if (numbers.at(1) == 1)
                {
                    vehicle = shared_ptr<Vehicle>(new SleepingCar(numbers.at(0), numbers.at(2)));
                    addVehicle(vehicle);
                } else if (numbers.at(1) == 2)
                {
                    vehicle= shared_ptr<Vehicle> (new OpenFreightCar(numbers.at(0), numbers.at(2), numbers.at(3)));
                    addVehicle(vehicle);
                } else if (numbers.at(1) == 3)
                {
                    vehicle= shared_ptr<Vehicle>(new CoveredFreightCar(numbers.at(0), numbers.at(2)));
                    addVehicle(vehicle);
                } else if (numbers.at(1) == 4)
                {
                    vehicle= shared_ptr<Vehicle>(new ElectricEngine(numbers.at(0), numbers.at(2), numbers.at(3)));
                    addVehicle(vehicle);
                } else if (numbers.at(1) == 5)
                {
                    vehicle= shared_ptr<Vehicle>(new DieselEngine(numbers.at(0), numbers.at(2), numbers.at(3)));
                    addVehicle(vehicle);
                } else
                {
                    cout << "An unknowm Car type  was read from file" << endl;
                }
                line = line.substr(closePos);
            }
        } catch (const exception &e)
        {
            cerr << "Exception " << e.what() << endl;
        }
        if(vehicle){
          //  vehicle->printVehicle();
        }
    }


}

VehicleMap Station::getStationVehicles() const
{
    return vehicles;
}


