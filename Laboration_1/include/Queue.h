//
/* Queue.h
 * Honorine Lima
 * Holi1900
 * DT060G_Laboration_1
 * 2020-09-03.
*/

/*The Queue class stores numbers in an array and have data members to keep track of the head and tail of the queue as
 *well as the number of elements in the queue. The Queue class also have function to add and remove elements from the
 *Queue, to get the capacity and number of elements in the queue as well as functions to determine if the queue is
 * full or empty.
 */
#ifndef LABORATION_1_QUEUE_H
#define LABORATION_1_QUEUE_H
#include<iostream>
#include <memory>
using namespace std;

typedef int Type; // Makes Type an alias for int
const int QSIZE = 10; // Default Queue size

class Queue
{
private:
    unique_ptr<Type[]>queue; //smart pointer object to hold the dynamically allocated array
    int head; // index in array for head
    int tail; // index in array for tail
    int nElem; // nr of items in queue
    int maxElem; // max capacity of queue
public:
    /* Pre: -
Post: A Queue object with capacity for n dataitems is created. */
    Queue(int n = QSIZE); // n = max capacity of queue

/* Pre: The Queue has not reached its maximum capacity.
Post: elem is inserted as the newest element in
Queue. */
    void enqueue(Type elem);

/* Pre: The Queue is not empty.
Post: elem contains the oldest element in Queuepre and elem is not contained in Queue. */
    void dequeue(Type &elem);

/* Pre: -
Post: Number of elements in Queue is returned. */
    int length() const;

/* Pre: -
Post: If Queue has reached its maximum capacity
true is returned, else false is returned. */
    bool full() const;

/* Pre: -
Post: If Queue is true is returned,
else false is returned. */
    bool empty() const;

/* Pre: -
Post: Maximal number of elements that the Queue can
hold Queue is returned. */
    int capacity() const;

    void display();

};


#endif //LABORATION_1_QUEUE_H
