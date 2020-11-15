/*DataFileReader.h
* Honorine Lima
* Holi1900
* DT060G_Laboration_4
* 2020-11-15.
*/
/**============short description=================================
 * This class has data members;
 * the name a file containing data to be read,
 * the name a file to which to write error values to,
 * an ifstrean and ofstream object.
 * This class reads values from the given file and filter values for values with non numeric characters.
 */

#ifndef INPUT_FILTER_DATAFILEREADER_H
#define INPUT_FILTER_DATAFILEREADER_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

template<typename T>
class DataFileReader
{
public:
    DataFileReader(const string &aFileName, const string &aErrorFileName) : fileName(aFileName),
                                                                            errorFileName(aErrorFileName)
    {
    }

    virtual ~DataFileReader();

/** pre: A file named aDataFile contains values to read.
*/

/* post: Files are closed */
    void openFiles();

/* post: An input stream from the file named aDataFile and
an output stream to the file named aErrorFile are
opened. If either of these operations fails a
runtime_error exception is thrown. */
    bool readNextValue(T &aValue);
/* pre: openFiles has been successfully called.
post: If a value has been successfully read, aValue
holds that value and true is returned.
Else, the read operation encountered an
end-of-file and false is returned. */
private:
    string fileName;
    string errorFileName;
    ofstream outputstream;
    ifstream inputstream;
    bool isOpenFileCalled{false};

};

template<typename T>
DataFileReader<T>::~DataFileReader()
{
    outputstream.close();
    inputstream.close();
}

template<typename T>
void DataFileReader<T>::openFiles()
{
    isOpenFileCalled = true;
    outputstream.open(errorFileName);
    inputstream.open(fileName);

    if (!inputstream.is_open())
    {
        throw runtime_error(fileName + " could not be opened");
    }
    if (!outputstream.is_open())
    {
        throw runtime_error(errorFileName + " could not be opened");
    }

}

template<typename T>
bool DataFileReader<T>::readNextValue(T &aValue)
{
    /*if (!isOpenFileCalled)
    {
        throw runtime_error("Function to open files has not be called");
    }*/

    ios_base::iostate mask = ios::eofbit| ios::failbit | ios::badbit;
    inputstream.exceptions(mask);
    while(true)
    {
        try
        {
            inputstream>>aValue;
            return true;
        } catch (ios_base::failure&eo)
        {
            ios_base::iostate flags = inputstream.rdstate();
            if(flags & ios::eofbit)
            {
                inputstream.clear();
                return false;
            } else{
                string error;
                inputstream.clear();
                getline(inputstream,error);
                outputstream << error << endl;
            }
        }
    }

}


#endif //INPUT_FILTER_DATAFILEREADER_H
