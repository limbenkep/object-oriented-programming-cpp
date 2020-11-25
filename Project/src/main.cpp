#include "Prototypes.h"
#include "memstat.hpp"
#include "Vehicle.h"
#include "Coach.h"
#include "Station.h"
#include "Train.h"
#include "TrainMap.h"
#include "TrainCompany.h"
#include "Simulation.h"
#include <numeric>
#include <algorithm>
int main()
{
    /*Coach mio(1, 20, false);
    cout << "Type: " << mio.getVehicleType() << "\nNr of chairs: " << mio.getNrOfChairs() << "\nInternets: "
         << mio.getInternet() << endl;
    const string stationFile("TrainStations.txt");
    std::ifstream ifstream1(stationFile);
    vector<Station> stations;
    Station station;
    if (ifstream1)
    {
        while (!ifstream1.eof())
        {
            station.readFromFile(ifstream1);
            stations.push_back(station);
        }
        //VehicleMap vehicles = station.getStationVehicles();
        cout << "Nr of stations: " << stations.size() << endl;

        for_each(stations.begin(), stations.end(), [&](const Station &s){
            cout << "Station name: " << s.getName() << endl;
        });
    } else
    {
        std::cerr << "Error reading station file\n";
    }*/
    shared_ptr<TrainCompany>theCom(new TrainCompany());
    Simulation *theSim = new Simulation();
    const string trainFile("Trains.txt");
    std::ifstream ifstream1(trainFile);
    vector<Train> trains;
    Train train;
    if (ifstream1)
    {
        while (!ifstream1.eof())
        {
            train.readTrainFromFile(ifstream1);
            trains.push_back(train);
            train.printTrain();
            train.setDistance(theCom->getDistanceOfTrainStations(train));
            shared_ptr<Event>e(new NotAssembledEvent(train.getDepartureTime(), train, theSim, theCom));
            theSim->scheduleEvent(e);
            cout << "The distance to travel: " <<train.getDistance() << " km" <<endl;
        }
        //VehicleMap vehicles = station.getStationVehicles();
        cout << "Nr of trains: " << trains.size() << endl;

        for_each(trains.begin(), trains.end(), [&](const Train &s){
            //cout << "Train ID: " << s.getTrainId() << endl;

        });
    } else
    {
        std::cerr << "Error reading station file\n";
    }
    theSim->run();
    return 0;
}
