//
// Created by limbe on 2020-11-27.
//

#ifndef LIST_MANIPULATOR_USERINTERFACE_H
#define LIST_MANIPULATOR_USERINTERFACE_H
#include "ListManipulator.h"

template<typename T>
class UserInterface
{
private:
    ListManipulator<T> listManipulator;


public:
    UserInterface(list<T>*theList);

    virtual ~UserInterface();
    void printMenu();
    int getChoice();
    int getMenuChoice();
    void executeMenu();
    void nextMoveKey();
    void fillList();
    void printSumOfList();
    void printAverage();
    void printFirstValueBetween1500And1900();
    void divideListElementsBy2();
    void swapListElements();
    void printMaxAndMinValue();
    void sortList();
    void clearList();
    void writeToFile();

    void readFromFile();
    void printList();




    void run();

};

template<typename T>
UserInterface<T>::UserInterface(list<T>*theList): listManipulator(theList)
{
}

template<typename T>
UserInterface<T>::~UserInterface()
{

}

template<typename T>
void UserInterface<T>::printMenu()
{
    cout << "1. Fill list with random numbers.\n2. Summerize the values in the list."
            "\n3. Average of the numbers.\n4. Find first number between 1500 and 1900."
            "\n5. Divide by two. \n6. Swap places. \n7. Find largest and smallest number. \n8. Sort. \n9. Clear list."
            "\n10. write to file. \n11. Read from file. \n12. Print numbers. \n13. Quit." <<endl;
}

template<typename T>
int UserInterface<T>::getChoice()
{
    cout << "Make your choice:";
    int choice = 0;
    cin>>choice;
    if (!cin||choice<1)// this control ensures that number of albums, number of songs, song length for which is function is used to get can not be 0
    {
        cin.clear();
        cin.ignore(1000, '\n');
        return -1;
    }
    cin.ignore(1000, '\n');
    return choice;
}

template<typename T>
void UserInterface<T>::executeMenu()
{
    bool again = true;
    while(again)
    {
        switch(getMenuChoice())
        {
            case 1:
                fillList();
                nextMoveKey();
                break;
            case 2:
                printSumOfList();
                nextMoveKey();
                break;
            case 3:
                printAverage();
                nextMoveKey();
                break;
            case 4:
                printFirstValueBetween1500And1900();
                nextMoveKey();
                break;
            case 5:
                divideListElementsBy2();
                nextMoveKey();
                break;
            case 6:
                swapListElements();
                nextMoveKey();
                break;
            case 7:
                printMaxAndMinValue();
                nextMoveKey();
                break;
            case 8:
                sortList();
                nextMoveKey();
                break;
            case 9:
                clearList();
                nextMoveKey();
                break;
            case 10:
                writeToFile();
                nextMoveKey();
                break;
            case 11:
                readFromFile();
                nextMoveKey();
                break;
            case 12:
                printList();
                nextMoveKey();
                break;
            case 13:
                again=false;
                break;
            default:
                cout << "\nInvalid choice." << endl;
                break;
        }
    }

}

template<typename T>
void UserInterface<T>::nextMoveKey()
{
    cout << "\n\tPress 'ENTER' to continue!";
    cin.get();
}

template<typename T>
void UserInterface<T>::run()
{
    cout << "Choose the type of list. \n1. Int, \n2. Double." << endl;
    int choice = getChoice();
    while(choice<1||choice>2)
    {
        cout << "\nInvalid choice. Choice must be 1 0r 2." << endl;
        cout << "Choose the type of list. \n1. Int, \n2. Double." << endl;
        choice = getChoice();
    }
    if (choice==1)
    {
        list<int> *intList;
        //executeMenu()
    }
}

template<typename T>
int UserInterface<T>::getMenuChoice()
{
    printMenu();
    int choice = getChoice();
    while(choice<1||choice>13)
    {
        cout << "\nInvalid choice. Choice must be 1 0r 13." << endl;
        printMenu();
        choice = getChoice();
    }
    return choice;
}

template<typename T>
void UserInterface<T>::fillList()
{
    listManipulator.fillList();
    cout << "\nThe list has been filled with 20 random numbers." << endl;
}

template<typename T>
void UserInterface<T>::printSumOfList()
{
    if(listManipulator.listIsEmpty())
    {
        cout << "The list is empty." << endl;
    } else{
        cout << "The sum of the numbers in the list is " << listManipulator.sumList() << "." << endl;
    }

}

template<typename T>
void UserInterface<T>::printAverage()
{
    if(listManipulator.listIsEmpty())
    {
        cout << "The list is empty." << endl;
    }
    else{
        cout << "The average of the numbers in the list is " << listManipulator.listAverage() << "." << endl;
    }

}

template<typename T>
void UserInterface<T>::printFirstValueBetween1500And1900()
{
    if(listManipulator.listIsEmpty())
    {
        cout << "The list is empty." << endl;
    } else{
        T num;
        listManipulator.findFirst1500_1900(num);
        cout << "The first number between 1500 and 1900 is " << num<< "." << endl;
    }
}

template<typename T>
void UserInterface<T>::divideListElementsBy2()
{
    if(listManipulator.listIsEmpty())
    {
        cout << "The list is empty." << endl;
    } else{
        listManipulator.dividedByTwo();
        cout << "The numbers on the list have been divided by 2." << endl;
    }
}

template<typename T>
void UserInterface<T>::swapListElements()
{
    if(listManipulator.listIsEmpty())
    {
        cout << "The list is empty." << endl;
    }
    else{
        listManipulator.swapPlaces();
        cout << "The position of the numbers in the list have been swapped." << endl;
    }
}

template<typename T>
void UserInterface<T>::printMaxAndMinValue()
{
    if(listManipulator.listIsEmpty())
    {
        cout << "The list is empty." << endl;
    }
    else{
        T max, min;
        listManipulator.findMinMax(min, max);
        cout << "The largest number in the list is " << max << "." << endl;
        cout << "The smallest number in the list is " << min << "." << endl;
    }

}

template<typename T>
void UserInterface<T>::sortList()
{
    if(listManipulator.listIsEmpty())
    {
        cout << "The list is empty." << endl;
    }
    else{
        listManipulator.sortList();
        cout << "The list has been sorted." << endl;
    }

}

template<typename T>
void UserInterface<T>::clearList()
{
    listManipulator.clearList();
    cout << "The list has been emptied." << endl;
}

template<typename T>
void UserInterface<T>::writeToFile()
{
    if(listManipulator.listIsEmpty())
    {
        cout << "The list is empty." << endl;
    }
    else{
        listManipulator.saveToFile();
        cout << "The list has been written to file." << endl;
    }
}

template<typename T>
void UserInterface<T>::readFromFile()
{
    listManipulator.readFromFile();

}

template<typename T>
void UserInterface<T>::printList()
{
    listManipulator.printList();
}


#endif //LIST_MANIPULATOR_USERINTERFACE_H
