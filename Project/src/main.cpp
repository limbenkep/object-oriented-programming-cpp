#include "Prototypes.h"
#include "memstat.hpp"
#include "Car.h"
#include "Coach.h"


int main() {
    Coach mio("c1", 20, false);
    cout<<"Type: " << mio.getCarType() << "\nNr of chairs: "<< mio.getNrOfChairs() << "\nInternets: "<< mio.getInternet() << endl;
    return 0;
}
