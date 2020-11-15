//
// Created by limbe on 2020-11-15.
//

#include "DataFileReader.h"

template<typename T>
DataFileReader<T>::DataFileReader(const string &fileName, const string &errorFileName):fileName(fileName),
                                                                                       errorFileName(errorFileName)
{
}