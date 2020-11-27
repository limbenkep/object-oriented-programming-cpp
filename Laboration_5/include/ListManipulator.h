//
// Created by limbe on 2020-11-27.
//

#ifndef LIST_MANIPULATOR_LISTMANIPULATOR_H
#define LIST_MANIPULATOR_LISTMANIPULATOR_H
#include <iostream>
#include <list>
using namespace std;
template<typename T>
class ListManipulator
{
private:
    list<T> *theList;
public:
    ListManipulator(list<T> *theList);
};

template<typename T>
ListManipulator<T>::ListManipulator(list<T> *theList):theList(theList)
{
}


#endif //LIST_MANIPULATOR_LISTMANIPULATOR_H
