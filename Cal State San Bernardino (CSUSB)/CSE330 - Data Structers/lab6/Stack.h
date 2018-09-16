#ifndef STACK_H
#define STACK_H

// Stack.h  -- a stack implemented as an adapter (of vector or list or ...)

#include "../lab5/List.h"

using namespace std;

//Use the following line for STL containers.
//template <class T, template <class T, class = allocator<T> > class Container = list>
template <class T, template <class T> class Container = List>
class Stack
{
public:
    //We don't need a constructor or destructor because the Container has/should have one
    //Stack(): container() { }
    //~Stack() { ~container(); }
    bool empty() const { return container.empty(); }
    unsigned int size() const { return container.size(); }
    void push(const T & x) { container.push_back(x); }
    void pop() {container.pop_back(); }
    T & top() {return container.back(); }
    
private:
    Container<T> container;
};


#endif
