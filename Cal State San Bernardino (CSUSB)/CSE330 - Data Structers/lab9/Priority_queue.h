/********************************************************************************
 James Small
 Date Start: 3-12-12 Date End: 3-15-12
 Filename: Priority_queue.h
 Description: This is the template class for my own Priority Queue Class.  The 
 functions used were based on the Priority_queue.cpp file that was given to us.
 The information for the priority queue is stored in a vector.  Just basic
 functions exist, and almost all can be done in line.
 *******************************************************************************/

#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

// Priority_queue.h  -- a priority_queue implemented as a heap

#include <vector>

using namespace std;

template <class T> 
class Priority_queue {
public:
    Priority_queue() : c() { }
    Priority_queue(const Priority_queue<T> & p);
    ~Priority_queue();
    bool empty() { return c.empty(); }
    unsigned int size() { return c.size(); }
    void push(const T & x);
    void pop(); 
    T & top() { return c.front(); }
    Priority_queue<T> & operator=(const Priority_queue<T> & p);
private:
    vector<T> c;
};

/**************************************************************************
 Function Name: Priority_queue(const Priority_queue<T> & p)
 Description: Copy constructor
 **************************************************************************/

template <class T>
Priority_queue<T>::Priority_queue(const Priority_queue<T> & p) {
    
    for (int i = 0; i < p.c.size() ; i++) 
        push(p.c[i]);  
}

/**************************************************************************
 Function Name: ~Priority_queue()
 Description: Deconstructor.  Doesn't do anything for this implementation.
 **************************************************************************/

template <class T>
Priority_queue<T>::~Priority_queue() {
        
}

/**************************************************************************
 Function Name: push(const T & x)
 Description: Pushes value x into the priority queue.  First adds the value
              into the vector at the end.  Second, it moves the value up
              in the heap until it's in it's proper location
 **************************************************************************/

template <class T>
void Priority_queue<T>::push(const T & x) {

    c.push_back(x);

    int temp = c.size() - 1;

    if (c.size() < 0)
        return;

    while(c[temp] > c[(temp - 1) / 2]) {
        T hold = c[(temp - 1) / 2];
        c[(temp - 1) / 2] = c[temp];
        c[temp] = hold;
        temp = (temp - 1) / 2;
    }
}

/**************************************************************************
 Function Name: pop()
 Description: Pop takes off the largest and root element of the heap.  It
              first swaps the first and last elements.  It then moves the 
              new root item down the heap until it finds it's correct spot.
              Lastly, pops the last element of the vector.
 **************************************************************************/

template <class T>
void Priority_queue<T>::pop() {

    int size = c.size();
    int parent = 0;
    
    if (size == 0)
        return;
        
    c[parent] = c.back();
    
    while (parent < size) {
            
        int firstChildPos = parent * 2 + 1;
          
        if (firstChildPos < size) {
            if (firstChildPos + 1 && c[firstChildPos + 1] > c[firstChildPos])
                firstChildPos++;
            
            if (c[parent] > c[firstChildPos])
                return;
            else {
                T temp = c[firstChildPos];
                c[firstChildPos] = c[parent];
                c[parent] = temp;
            }
        }
        parent = firstChildPos;  
    }   
    c.pop_back();
}

/**************************************************************************
 Function Name: operator=(const Priority_queue<T> & p)
 Description: assignment operator.  Clears out vector, and copies in new values
 **************************************************************************/

template <class T>
Priority_queue<T> & Priority_queue<T>::operator=(const Priority_queue<T> & p) {
   
    c.clear();
    
    for (int i = 0; i < p.c.size() ; i++) 
        push(p.c[i]);     
}

#endif

