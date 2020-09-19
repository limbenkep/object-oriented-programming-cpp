/* main.cpp
 * Honorine Lima
 * Holi1900
 * DT060G_Laboration_1
 * 2020-09-03.
*/

/*
 * This program uses two classes, the Queue class and TestApp class and is designed to allow the user to create and
 * manage a  queue of desired size to store integers.
 * Only one queue is generated at a time and the old queues is deleted when  new queue is created.
 * When this program starts, the user have the option to create a queue or quit. If the user chooses to create a queue,
 * then a  queue is created and the user then have 8 options, to create a new queue, Enqueue, Dequeue, Test if queue is
 * empty, Test if queue is full, Nr of elements in queue, Maximum size of queue  and Quit.
 */

#include "Queue.h"
#include "memstat.hpp"
#include "TestApp.h"

int main()
{
   TestApp test;
   test.run();
   return 0;
}
