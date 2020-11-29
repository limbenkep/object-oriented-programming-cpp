//
// Created by limbe on 2020-11-27.
//

#ifndef LIST_MANIPULATOR_LISTMANIPULATOR_H
#define LIST_MANIPULATOR_LISTMANIPULATOR_H

//#include <chrono>
#include "Helper.h"
#include <iomanip>

template<typename T>
class ListManipulator
{
private:
    list<T> *theList;
public:
/**
 * constructor takes a pointer to a list
 * @param theList
 */
    ListManipulator(list<T> *theList);

    virtual ~ListManipulator();
/**
 * fills list with random numbers
 */
    void fillList();
/**
 *
 * @return returns the sum of all the elements in the list
 */
    T sumList() const;
/**
 *
 * @return returns the average of all the elements in the list
 */
    T listAverage() const;
/**
 * gets the first number between 1500 to 1900
 * @param num first number between 1500 to 1900 return by reference
 * @return return true if a number if found or false if no number if found
 */
    bool findFirst1500_1900(T &num) const;
/**
 * divides the number on the list by 2
 */
    void dividedByTwo();
/**
 * swap the elements on the list swapping the first and the last the next to first
 * and next to last until all numbers are swpped
 */
    void swapPlaces();
/**
 * finds the minimum and maximum values on the list and pass by reference
 */
    void findMinMax(T &min, T &max) const;
/**
 * sort list in ascending order
 */
    void sortList();
/**
 * empty list
 */
    void clearList();
/**
 *
 * @return the list
 */
    list<T> getList() const;
/**
 * writes numbers on the list to a file
 */
    void saveToFile() const;
/**
 * reads numbers to the list from a file
 */
    void readFromFile();
/**
 * prints the numbers on the list on the screen
 */
    void printList();
/**
 *
 * @return true if list is empty and false if not empty
 */
    bool listIsEmpty();


};

template<typename T>
ListManipulator<T>::ListManipulator(list<T> *theList):theList(theList)
{
}

template<typename T>
ListManipulator<T>::~ListManipulator()
{

}

template<typename T>
void ListManipulator<T>::fillList()
{
    clearList();
    theList->resize(20);
    //default_random_engine dre (chrono::steady_clock::now().time_since_epoch().count());

    generate(theList->begin(), theList->end(), randomNumber<T>);
}

template<typename T>
T ListManipulator<T>::sumList() const
{
    if(theList->empty())
    {
        cout << "The list is empty." << endl;
    }
    T sum = accumulate(theList->begin(), theList->end(), T(0));
    return sum;
}

template<typename T>
T ListManipulator<T>::listAverage() const
{
    return accumulate(theList->begin(), theList->end(), T(0))/theList->size();
}

template<typename T>
bool ListManipulator<T>::findFirst1500_1900(T &num) const
{
    if(theList->empty())
    {
        cout << "The list is empty." << endl;
    }
    auto it = find_if(theList->begin(), theList->end(), [](T a) { return a >= 1500 && a <= 1900; });
    if (it != theList->end())
    {
        num = *it;
        return true;
    }
    return false;// if no value is found returns false
}

template<typename T>
void ListManipulator<T>::dividedByTwo()
{
    transform(theList->begin(), theList->end(), theList->begin(), bind(divides<T>(), placeholders::_1, 2));
}

template<typename T>
void ListManipulator<T>::swapPlaces()
{
    if(theList->empty())
    {
        cout << "The list is empty." << endl;
    }
    else{
        auto fIt = theList->begin();
        auto bIt = theList->end();
        auto mySize = theList->size();

        for (size_t i = 0; i < mySize/2; i++)
        {
            bIt--; // makes sure theList->end() is not swapped as part of the list
            iter_swap(fIt, bIt);
            fIt++;
        }
    }

}

template<typename T>
void ListManipulator<T>::findMinMax(T &min, T &max) const
{
    if(theList->empty())
    {
        cout << "The list is empty." << endl;
    }
    else
    {
        min = *min_element(theList->begin(), theList->end());
        max = *max_element(theList->begin(), theList->end());
    }
}

template<typename T>
void ListManipulator<T>::sortList()
{
    if(theList->empty())
    {
        cout << "The list is empty." << endl;
    }
    else{
        theList->sort();
    }

}

template<typename T>
void ListManipulator<T>::clearList()
{
    theList->clear();
}

template<typename T>
list<T> ListManipulator<T>::getList() const
{
    return theList;
}

template<typename T>
void ListManipulator<T>::saveToFile() const
{
    if(theList->empty())
    {
        cout << "The list is empty and can not be rad to file." << endl;
    } else{
        ofstream outFile("list.txt");
        if(!outFile.is_open())
        {
            cout << "The file could not be opened" << endl;
        }
        else{
            copy(theList->begin(), theList->end(), ostream_iterator<T>(outFile, "\n"));
        }
    }
}

template<typename T>
void ListManipulator<T>::readFromFile()
{
    clearList();
    ifstream inFile("list.txt");
    if(!inFile.is_open())
    {
        cout << "File  'list.dat' not found." << endl;
    }
    else{
        istream_iterator<T> eos;
        istream_iterator<T> iit(inFile);
        copy(iit, eos, back_inserter(*theList));
        cout << "The list has been read from file." << endl;
    }

}

template<typename T>
void ListManipulator<T>::printList()
{
    if(theList->empty())
    {
        cout << "The list is empty." << endl;
    }
    else{
        int i = 0;
        for_each(theList->begin(), theList->end(), [&i](const T &number)
        {cout <<"\t"<<setw(2) << ++i << ": " << number << endl; });
    }
}

template<typename T>
bool ListManipulator<T>::listIsEmpty()
{
    return theList->empty();
}

//



#endif //LIST_MANIPULATOR_LISTMANIPULATOR_H
