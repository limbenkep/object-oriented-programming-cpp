//
// Created by limbe on 2020-11-15.
//

#ifndef INPUT_FILTER_DATAFILTER_H
#define INPUT_FILTER_DATAFILTER_H
#include "DataFileReader.h"
template<typename T>
class DataFilter
{
public:
    DataFilter(DataFileReader <T> *aReader, T aMin, T aMax);

/* pre: aReader points to an instance of DataFileReader<T>
for which openFiles() has been succesfully called.
*/
    bool getNextValue(T &aValue);
/* pre: an earlier call to getNextValue() has not returned
false.
post: true is returned if aValue holds a value read from
aReader. If a value could not be read, false
is returned. If a value is read but is not within
the interval specified by aMin and aMax parameters
to the constructor, a range_error exception is
thrown.
*/
private:
    T min;
    T max;
    DataFileReader<T> *dataFileReader;

};

template<typename T>
DataFilter<T>::DataFilter(DataFileReader<T> *aReader, T aMin, T aMax): dataFileReader(aReader),min(aMin), max(aMax)
{
}

template<typename T>
bool DataFilter<T>::getNextValue(T &value)
{
    if(dataFileReader->readNextValue(value))
    {
        if(value<min||value>max)
        {
            throw range_error(to_string(value));
        }
        return true;
    }
    return false;
}


#endif //INPUT_FILTER_DATAFILTER_H
