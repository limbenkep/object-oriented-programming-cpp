#include "Prototypes.h"
#include "Queue.h"
#include "memstat.hpp"
#include "TestApp.h"

int main() {
   /* Queue q(12);

    const int iterations = 12;
    cout << "Size of queue before adding stuff " << q.length() << ", capacity " << q.capacity() <<  endl;
    for (int i = 1; i <= iterations; ++i)
    {
        q.enqueue(i);
        //cout << "Added " << i << " into queue\n";
    }
    cout << "Size of queue after adding "  << iterations << " items " <<  q.length() << " capacity " << q.capacity() << endl;
    for (int i = 1; i <= iterations; ++i)
    {
        int item;
        q.dequeue(item);
        //cout << "Dequeued " << item << " into queue\n";
    }

    cout << "Size of queue after removing "  << iterations << " items " <<  q.length() << " capacity " << q.capacity() << endl;
*/
   TestApp a;
   a.run();
    return 0;
}
