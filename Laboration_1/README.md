# Laboration 1

## Environment & Tools
windows 10 Operating system, CLion 2019.3.3 IDE, Microsoft C++ (MSVC) compiler, CMake version: 3.15.6, Git version: 2.25.0.windows.1

## Purpose
The purpose of this lab is to practice the use of unique pointers by using it in the implementation of an interactive 
menu-driven program that uses circular queue to store numbers.

## Procedures
This program is designed to allow the user to create and manage a  queue of desired size to store integers. Only one 
queue is generated at a time and the old queues is deleted when  new queue is created. 
 When this program starts, the user have the option to create a queue or quit. If the user chooses to create a queue, 
 then a  queue is created and the user then have 8 options, to create a new queue, Enqueue, Dequeue, Test if queue is 
 empty, Test if queue is full, Nr of elements in queue, Maximum size of queue  and Quit.
 When user chooses to create a queue, the user is prompt to enter the capacity of the queue which should be greater than Zero.
 For Enqueue option, the user is prompt to enter element to be added and all invalid entries generate error messages.
 This program uses two classes; the Queue class that stores the integers in a  circular queue, and a 
userinterface class TestApp which manages menu options and and execution of the user's request.
The Queue class stores numbers in an array and have data members to keep track of the head and tail of the queue as 
well as the number of elements in the queue. The Queue class also have function to add and remove elements from the 
Queue, to get the capacity and number of elements in the queue as well as functions to determine if the queue is 
full or empty. 
The TestApp class has a pointer to a dynamically generated Queue object as a data member and this class prompt user for entries and 
and have functions to execute the user's requests.

## Discussion
To meet the goals of this project, I have build a working program that allow the user to perform all the option stated above. 
To practice the use of unique pointers, I used a unique pointer a datamember in the queue
class to hold the dynamically allocated array which store the elements of the queue.
I also used smart pointer as a data member in the testApp class to hold the dynamically generated Queue object. I also 
revised the concepts of linked lists. The Lab description was very explicit and the course material was adequate to do the Lab.
