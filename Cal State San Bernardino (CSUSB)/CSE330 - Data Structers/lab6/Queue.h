#ifndef QUEUE_H
#define QUEUE_H

#include "../lab5/List.h"

using namespace std;

//Use the following line for STL containers.
//template <class T, template <class T, class = allocator<T> > class Container = list>
template <class T, template <class T> class Container = List>
class Queue
{
public:

    bool empty() const { return container.empty(); }
    unsigned int size() const { return container.size(); }
    void push(const T & x) { container.push_back(x); }
    void pop() {container.pop_front(); }
    T & top() {return container.front(); }
    
private:
    Container<T> container;
};


#endif
