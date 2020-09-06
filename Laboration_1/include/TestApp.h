//
// Created by limbe on 2020-09-03.
//

#ifndef LABORATION_1_TESTAPP_H
#define LABORATION_1_TESTAPP_H
#include "Queue.h"


class TestApp
{
private:
    unique_ptr<Queue>intQueue;
    bool done;
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
 */
    void createQueue(); // Creates a queue of desired length


    void enqueue(); // Asks for integer
    void dequeue(); // deleting integer, printing out
    void isEmpty() const;
    void isFull() const;
    void nrElements() const;
    void maxCapacity() const;
public:
    TestApp();

    void run();

    virtual ~TestApp();

};


#endif //LABORATION_1_TESTAPP_H
