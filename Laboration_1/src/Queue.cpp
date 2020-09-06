//
// Created by limbe on 2020-09-03.
//

#include "Queue.h"


Queue::Queue(int n):maxElem(n),nElem(0), head(-1), tail(-1)
{
    queue = unique_ptr<Type[]>(new Type[n]);
}

void Queue::enqueue(Type elem)
{
    if(full())
    {
        cout<<"Queue is full"<<endl;
        return;
    }
    else if(empty()) //
    {//insert first element which becomes both the head and the tail of the queue.
        head = tail = 0;
        queue[tail] = elem;
        nElem++;
    }
    else if(!empty() && tail == maxElem-1)
    {
        tail=0;
        queue[tail] = elem;
        nElem++;
    }
    else
    {
        tail++;
        queue[tail] = elem;
        nElem++;
    }


}

bool Queue::empty() const
{
    return nElem == 0;
}

bool Queue::full() const
{
    return nElem == maxElem;
}

void Queue::dequeue(Type &elem)// elem is used to return by reference the value of the element that is plocked from the queue
{
    if(empty())
    {
        cout<<"Queue is empty!" <<endl;
    }
    else if(head==tail)
    {
        elem = queue[head];
        queue[head] = -1;
        head = tail =-1;
        nElem--;
    }
    else if(head == maxElem-1)
    {
        elem = queue[head];
        head = 0;
        nElem--;
    } else{
        elem = queue[head];
        queue[head] = -1;
        head++;
        nElem--;
    }

}

int Queue::length() const
{
    return nElem;
}

int Queue::capacity() const
{
    return maxElem;
}

void Queue::display()
{
    std::cout << "Items in queue " << length() << std::endl;
    while (!empty()){
        Type item{};
        dequeue(item);
        std::cout << "Item: " <<item << ", " << endl;
        std::cout << "The value of head is " << head << std::endl;
    }
}


