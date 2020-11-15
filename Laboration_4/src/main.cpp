/*main.cpp
* Honorine Lima
* Holi1900
* DT060G_Laboration_4
* 2020-10-30.
*/
/**============short description=================================
 * This program reads values from a file generated a program that stores numerical values and filters the values for
 * two types of faults;
 *  values that falls outside the given range and
 *  values that contain non numeric characters.
 * The program then prints out data on;
 * Number of values read
 * Number of values out of range
 * Sum of values read
 * Average of values read
 */


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
