#include "Prototypes.h"
#include "memstat.hpp"
#include "Vehicle.h"
#include "Coach.h"


int main() {
    Coach mio("c1", 20, false);
    cout << "Type: " << mio.getVehicleType() << "\nNr of chairs: " << mio.getNrOfChairs() << "\nInternets: " << mio.getInternet() << endl;
    return 0;
}
