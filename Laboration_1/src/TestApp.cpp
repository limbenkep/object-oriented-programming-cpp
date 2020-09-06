/*TestApp.cpp
* Honorine Lima
* Holi1900
* DT060G_Laboration_1
* 2020-09-03.
*/

#include "TestApp.h"
#include "memory"
#include <sstream>
TestApp::TestApp(): intQueue(new Queue()), done(false)
{

}

TestApp::~TestApp()
{

}

void TestApp::showMenu()
{
    cout<< "\n1. Create new queue. 0ld queue will be deleted"
    <<"\n2. Enqueue object." <<"\n3. Dequeue object."
    <<"\n4. Test if queue is empty." << "\n5. Test if queue is full."
    << "\n6. Nr of elements in queue." <<"\n7. Maximum size of queue."
    << "\n8. Quit." <<endl;
}

char TestApp::getChoice()
{
    cout <<"\nmake your choice: ";
    char choice;
    cin >> choice;
    return choice;
}

char TestApp::getMenuOption()
{
    char options[] = {'1', '2', '3', '4', '5', '6', '7', '8'};
    char choice{'a'};
    bool valid = false;

    while(!valid)
    {
        choice = getChoice();
        for(auto & option : options) // using range-base for loop. same as for(int i=0; i<8; i++)...if(options[i]==choice)
        {
            if(option==choice)
            {
                valid =true;
            }

        }

        if(!valid)
        {
            cout << "Invalid choice." << endl;
        }

    }
    return choice;
}

void TestApp::doMenuOption(char option)
{
    switch (option)
    {
        case '1':
            createQueue();
            break;
        case '2':
            enqueue();
            break;
        case '3':
            dequeue();
            break;
        case '4':
            isEmpty();
            break;
        case '5':
            isFull();
            break;
        case '6':
            nrElements();
            break;
        case '7':
            maxCapacity();
            break;
        case '8':
            done = true;
            break;
        default:
            cout << "\nInvalid choice." << endl;
            break;

    }
}


void TestApp::createQueue()
{
    cout << "Number of elements in queue: ";
    int size=0;
    cin >> size;
    while (!cin||size<1)// control that the entry is an integer greater than 0
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid entry. Number of queue must be an integer greater than 0.\nNumber of elements in queue: ";
        cin >> size;
    }
    cin.ignore(1000, '\n');

    intQueue = unique_ptr<Queue>(new Queue(size));// creates a new Queue object of capacity "size" held by intQueue
    cout << "A queue with a maximum size of "<< size << " has been created."<<endl;

    while(!done)
    {
        showMenu();
        doMenuOption(getMenuOption());
    }

}

/*
 * prompts user for a number and add the number to the queue
 */
void TestApp::enqueue()
{
    int qCapacity = intQueue->capacity();
    int qLength = intQueue->length();
    if (qLength ==qCapacity)
    {
        cout << "\nThe queue is full." << endl;
    }
    else
    {
        cout << "Enter a number to add to queue: ";
        int number;
        cin>> number;
        intQueue->enqueue(number);//enqueue here a Queue class member function
        cout << "The number '"<< number << "' has been added to the queue." << endl;
    }
}

/*
 * remove an element from the queue
 */
void TestApp::dequeue()
{
    if(intQueue->empty())
    {
        cout<< "\nThe queue is empty" <<endl;
    }
    else
    {
        int plocked;
        intQueue ->dequeue(plocked);//dequeue here a Queue class member function
        cout << "\nThe element '" << plocked << "' has been removed from the queue." << endl;
    }

}

/*
 * Checks if queue is empty and prints a corresponding message on the screen
 */
void TestApp::isEmpty() const
{
    if(intQueue->empty())
    {
        cout << "\nThe queue is empty." << endl;
    }
    else
    {
        cout << "\nThe queue is Not empty." << endl;
    }
}

/*
 * Checks if queue is full and prints a corresponding message on the screen
 */
void TestApp::isFull() const
{
    int qCapacity = intQueue->capacity();
    int qLength = intQueue->length();
    if (qLength ==qCapacity)
    {
        cout << "\nThe queue is full." << endl;
    }
    else
    {
        cout << "\nThe queue is Not full." << endl;
    }
}

/*
 * Prints the number of elements in the queue on the screen
 */
void TestApp::nrElements() const
{
    cout << "\nThe queue contains " << intQueue->length()<< " elements." <<endl;
}

/*
 * Prints the maximum capacity of the queue on the screen
 */
void TestApp::maxCapacity() const
{
    cout << "\nThe maximum capacity of the queue is " << intQueue->capacity() << endl;
}

void TestApp::run()
{
    cout << "\n1. Create queue.\n2. Quit" <<endl;
    char choice = getChoice();
    while (choice!='1' && choice!='2')
    {
        cout << "Invalid choice.";
        choice = getChoice();
    }

    while(!done)
    {
        switch (choice)
        {
            case '1':
                createQueue();
                //showMenu();
                //doMenuOption(getMenuOption());
                break;
            case '2':
                done =true;
            default:
                cout << "\nInvalid choice." << endl;
                break;
        }
    }
}


