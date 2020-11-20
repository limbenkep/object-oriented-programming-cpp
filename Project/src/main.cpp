#include "Prototypes.h"
#include "memstat.hpp"
#include "Vehicle.h"
#include "Coach.h"
#include "Station.h"
#include <numeric>
#include <algorithm>
int main()
{
    Coach mio(1, 20, false);
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
    }

    

    return 0;
}
