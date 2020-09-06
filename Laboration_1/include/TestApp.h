/* TestApp.h
 * Honorine Lima
 * Holi1900
 * DT060G_Laboration_1
 * 2020-09-03.
*/
/*
 * The TestApp class has a pointer to a dynamically generated Queue object as a data member and this class prompt
 * user for entries and have functions to execute the user's requests.
 */

#ifndef LABORATION_1_TESTAPP_H
#define LABORATION_1_TESTAPP_H
#include "Queue.h"


class TestApp
{
private:
    unique_ptr<Queue>intQueue; //pointer to hold dynamically generated Queue object.
    bool done;//used to exit program
// Main menu
    void showMenu();

/*
 * Prompts user to enter a choice and returns it as a char
 */
    char getChoice();

/*
 * prompts user for a choice
 * *Checks if option is valid
 * returns option as a char.
 */
    char getMenuOption();
    /*
 * Receives a menu option as a char
 * executes the corresponding function
 */
    void doMenuOption(char option);
// Menu-alternativ

/*
 * prompts user to enter desired queue capacity and
 * creates a queue object of that capacity
 * calls function to display menu and the  function to execute user's choice.
 */
    void createQueue(); // Creates a queue of desired length

/*
 * Checks that queue is not full, prompts user for a number and add the number to the queue
 */
    void enqueue();

/*
 * Check that queue is not empty, deletes an element from the queue and prints the deleted element
 */
    void dequeue();

/*
 * Checks if queue is empty or not and prints out a message
 */
    void isEmpty() const;

    /*
 * Checks if queue is full or not and prints out a message
 */
    void isFull() const;

/*
 * prints out the number of elements in a queue
 */
    void nrElements() const;

/*
 * prints out a maximum capacity of the current queue object.
 */
    void maxCapacity() const;
public:
    TestApp();
/*
 * prints startup menu which prompts user to create queue or quit and contain implementation to quit and calls funtions
 * that creates queue and options.
 */
    void run();

    virtual ~TestApp();

};


#endif //LABORATION_1_TESTAPP_H
