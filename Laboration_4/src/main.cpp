#include "Prototypes.h"
#include "memstat.hpp"
#include "DataFilter.h"
int main() {

    DataFileReader<double> dataFileReader("values.dat", "ReadErrors.dat");
    DataFilter<double>filter(&dataFileReader, 0.0, 10.0);

    double sum = 0;
    double average = 0;
    int nrOfValues = 0;
    int outSideRange = 0;
    ofstream rangeError("RangeErrors.dat");

    try
    {
        dataFileReader.openFiles();
    }
    catch (runtime_error &e)
    {
        cout << e.what()<<endl;
    }
    bool notEndOfFile = true;
    double value{-1};
    while (notEndOfFile)
    {
        try{
            notEndOfFile= (filter.getNextValue(value));

            if(notEndOfFile)
            {
                sum += value;
                nrOfValues++;
                average = sum/nrOfValues;
            }
        }
        catch (range_error &e)
        {
            outSideRange++;
            rangeError<<e.what()<<endl;//write value to rangerror
        }
    }
    rangeError.close();
    cout << "Number of values read: " << nrOfValues << endl;
    cout << "Number of values out of range: " << outSideRange << endl;
    cout << "Sum of values read: " << sum << endl;
    cout << "Average of values read: " << average << endl;
    return 0;
}
