/********************************************************************************
 James Small
 Date Start: 3-9-12  Date End: 3-12-12
 Filename: Deque.h
 Description: This is the template class for my own Deque Class.  The functions
 used were based on the Deque_test.cpp file that was given to us.  This
 template class also contains the definition and functions for the
 DequeIterator class that the Deque class actively.  This deque is implemented
 using a single array.  The deque values are maintanined as close to the center
 of the array as possible.  If array becomes full, center_it() is called to 
 increase array size and recenter deque values in the array.
 *******************************************************************************/

#ifndef DEQUE_H
#define DEQUE_H

// Deque.h - an implementation of double-ended queue

#include <iostream>

using namespace std;

template <class T> class DequeIterator;

/**************************************************************************
 Class Name: DequeIterator
 **************************************************************************/

template <class T>
class Deque {
public:
    typedef DequeIterator<T> iterator;
    
    Deque(): my_capacity(5) { buffer = new T[4];  front_ptr = next_back = 5/2; }
    Deque(const unsigned int size, const T & initial): my_capacity(size), front_ptr(0), next_back(size) {
        buffer = new T[size];
        for (int i = front_ptr; i < next_back; i++)
            buffer[i] = initial;
    }
    Deque(Deque<T> & d);
    ~Deque();
    
    T & operator[](unsigned int);
    Deque<T> & operator=(const Deque<T> & d);
    T & front() { assert(front_ptr < next_back); return buffer[front_ptr]; }
    T & back() { assert(front_ptr < next_back); return buffer[next_back - 1]; }
    bool empty();
    iterator begin();
    iterator end();
    void erase(const iterator &);
    void erase(const iterator &, const iterator &);
    void insert(const iterator &, const T &);
    int size();
    void push_front(const T & value);
    void push_back(const T & value);
    void pop_front();
    void pop_back();

protected:
    T * buffer;
    int front_ptr, next_back;
    int my_capacity;
    void center_it();

};

/**************************************************************************
 Function Name: Deque(Deque<T> & d)
 Description: Copy constructor.  creates deque based on passed in deque
 **************************************************************************/

template <class T>
Deque<T>::Deque(Deque<T> & d) {
    buffer = new T[d.my_capacity];
    front_ptr = d.front_ptr;
    next_back = d.next_back;
    my_capacity = d.my_capacity;
    
    for (int i = front_ptr; i < next_back; i++) 
        buffer[i] = d.buffer[i];
}

/**************************************************************************
 Function Name: ~Deque()
 Description: deconstructor.  deletes buffer if allocated
 **************************************************************************/

template <class T>
Deque<T>::~Deque() {
    if (buffer) 
        delete [] buffer;
}
/**************************************************************************
 Function Name: operator[](unsigned int index)
 Description: subscript operator.  asserts index is in range, returns value
              at passed in index.
 **************************************************************************/
    
template <class T>
T & Deque<T>::operator[](unsigned int index) {
    assert(front_ptr + index < next_back);
    return buffer[front_ptr + index];
}

/**************************************************************************
 Function Name: operator=(const Deque<T> & d)
 Description: assignment operator.  Deletes current buffer, and copies passed
              in values.
 **************************************************************************/

template <class T>
Deque<T> & Deque<T>::operator=(const Deque<T> & d) {
    
    if (buffer) 
        delete [] buffer;
    
    my_capacity = d.my_capacity;
    front_ptr = d.front_ptr;
    next_back = d.next_back;
    buffer = new T(my_capacity);
    
    for (int i = front_ptr; i < next_back; i++) 
        buffer[i] = d.buffer[i]; 
}

/**************************************************************************
 Function Name: empty()
 Description: returns true if deque has no values in it, false if not
 **************************************************************************/

template <class T>
bool Deque<T>::empty() {    
    return (front_ptr - next_back > 0);
}

/**************************************************************************
 Function Name: begin()
 Description: returns iterator to the first element in deque
 **************************************************************************/

template <class T>
typename Deque<T>::iterator Deque<T>::begin() {
    return iterator(this,0);
}

/**************************************************************************
 Function Name: end()
 Description: returns iterator to one past the last element in deque
 **************************************************************************/

template <class T>
typename Deque<T>::iterator Deque<T>::end() {
    return iterator(this,size());
}

/**************************************************************************
 Function Name: erase(const iterator & itr1)
 Description: determines which way is best when shifting deque values for
 deleted value, then pop_front() or pop_back(), depending on shift
 **************************************************************************/

template <class T>
void Deque<T>::erase(const iterator & itr) {

       //check for iterator out of bounds
    if (itr.index < 0 || itr.index >= size()) // index bounds checking
        return;
    
    if (front_ptr < my_capacity - next_back) { // checks which side to shift on erase
    
        //left shift
        for (int i = 0; i < itr.index; i++) 
            buffer[front_ptr + itr.index - i] = buffer[front_ptr + itr.index - i - 1];
        pop_front();
    }
    else {
        
        // right shift
        for (int i = 0; i < next_back - itr.index - front_ptr - 1; i++) 
            buffer[front_ptr + itr.index + i] = buffer[front_ptr + itr.index + i + 1];
        pop_back(); 
    }  
}

/**************************************************************************
 Function Name: erase(const iterator & itr1, const iterator & itr2)
 Description: Does bounds checking, then uses erase(iterator) function to
              delete all values between passed in iterators
 **************************************************************************/

template <class T>
void Deque<T>::erase(const iterator & itr1, const iterator & itr2) {
    
    //bounds checking  
    if (itr2.index - itr1.index <= 0) // if diff negative
        return;
    else if (itr1.index < 0 || itr2.index < 0) // if either are negative
        return;
    else if (itr1.index > size() || itr2.index > size()) // if either are too large
        return;
    
    for (int i = 0; i < itr2.index - itr1.index;i++)
        erase(itr1);
}

/**************************************************************************
 Function Name: insert(const iterator & itr, const T & x)
 Description: determines which way is best when shifting deque values for
              newly inserted value, then inserts value into deque
 **************************************************************************/

template <class T>
void Deque<T>::insert(const iterator & itr, const T & x) {
    
    //check for iterator out of bounds
    if (itr.index > size() || itr.index < 0) 
        return;
    
    if (front_ptr > my_capacity - next_back) { // checks which side to shift on insert
        
        //left shift
        for (int i = 0; i < itr.index; i++) 
            buffer[front_ptr - 1 + i] = buffer[front_ptr + i];
    
        buffer[front_ptr - 1 + itr.index] = x;
        
        if (front_ptr > 0) // front_ptr shouldn't be negative
            front_ptr--;
    }
    else {
        
        //right shift 
        for (int i = 0; i < next_back - itr.index - front_ptr; i++) 
            buffer[next_back - i] = buffer[next_back - i - 1];
    
        buffer[itr.index + front_ptr] = x;
        next_back++;
    } 
}

/**************************************************************************
 Function Name: size()
 Description: returns size of deque
 **************************************************************************/

template <class T>
int Deque<T>::size() {
    return next_back - front_ptr;
}

/**************************************************************************
 Function Name: push_front(const T & value)
 Description: cehcks if center_it needs to be called.  Adds value at begin
 **************************************************************************/

template <class T>
void Deque<T>::push_front(const T & value) {
   
    if (front_ptr == 0) {
        center_it();
    }
    
    if (front_ptr > 0) // front_ptr shouldn't be negative
        front_ptr--;
    
    buffer[front_ptr] = value;
}

/**************************************************************************
 Function Name: push_back(const T & value)
 Description: checks if center_it needs to be called.  Adds value at end
 **************************************************************************/

template <class T>
void Deque<T>::push_back(const T & value) {
   
    if (next_back - 1 == my_capacity - 1) {
        center_it();
    }
    
    buffer[next_back] = value;
    next_back++;
}

/**************************************************************************
 Function Name: pop_front()
 Description: shifts front_ptr index up one, which basically deletes first
 **************************************************************************/

template <class T>
void Deque<T>::pop_front() {
    front_ptr++;
}

/**************************************************************************
 Function Name: pop_back()
 Description: shifts next_back index less one, which basically deletes last
 **************************************************************************/

template <class T>
void Deque<T>::pop_back() {
    
    if (next_back > 0) // next_back shouldn't be negative
        next_back--;
}

/**************************************************************************
 Function Name: center_it()
 Description: Determines if buffer is full and increases capacity if so.  
              Determines center of buffer and copies values into new buffer
              at the centered values, deletes old buffer.
 **************************************************************************/

                  
template <class T>
void Deque<T>::center_it() {
     if (size() > my_capacity / 2) 
        my_capacity *= 2;
    
    int center = (my_capacity / 2) - (size() / 2);
    next_back = center + size();
    T * temp = new T[my_capacity];

    for (int i = 0; i < size(); i++)
        temp[center + i] = buffer[front_ptr + i];
    
    if (buffer) 
        delete [] buffer;
    
    buffer = temp;
    front_ptr = center;    
}

/**************************************************************************
 Class Name: DequeIterator
 **************************************************************************/

template <class T>
class DequeIterator {
    friend class Deque<T>;
    typedef DequeIterator<T> iterator;
    
public:
    DequeIterator(): theDeque(0), index(0) { }
    DequeIterator(Deque<T> * d, int i): theDeque(d), index(i) { }
    DequeIterator(const iterator & d): theDeque(d.theDeque), index(d.index) { }
    
    T & operator*();
    iterator & operator++();
    iterator operator++(int);
    iterator & operator--();
    iterator operator--(int);
    bool operator==(const iterator & r);
    bool operator!=(const iterator & r);
    bool operator<(const iterator & r);
    T & operator[](unsigned int i);
    iterator operator=(const iterator & r);
    iterator operator+(int i);
    iterator operator-(int i);
    
protected:
    Deque<T> * theDeque;
    int index;
};

/**************************************************************************
 Function Name: operator*()
 Description: returns value at passed in index.
 **************************************************************************/

template <class T>
T & DequeIterator<T>::operator*() {
    return (*theDeque)[index];
}

/**************************************************************************
 Function Name: operator++()
 Description: increases iterator by one, pre increment
 **************************************************************************/

template <class T>
DequeIterator<T> & DequeIterator<T>::operator++() {
    
    ++index;
    return *this;
}

/**************************************************************************
 Function Name: operator++(int)
 Description: increases iterator by one, post increment
 **************************************************************************/

template <class T>
DequeIterator<T> DequeIterator<T>::operator++(int) {
    
    DequeIterator<T> temp = *this;
    ++(*this);
    return temp;
    
}

/**************************************************************************
 Function Name: operator--()
 Description: decreases iterator by one, pre decrement.  Checks if index 
 will go negative before performing
 **************************************************************************/

template <class T>
DequeIterator<T> & DequeIterator<T>::operator--() {
    if (index > 0)
        index--;
    return *this;
}

/**************************************************************************
 Function Name: operator--(int)
 Description: decreases iterator by one, post decrement.  Checks if index 
 will go negative before performing
 **************************************************************************/

template <class T>
DequeIterator<T> DequeIterator<T>::operator--(int) {    
    if (index > 0) {
        DequeIterator<T> temp = *this;
        --(*this);
        return temp;
    }
    return *this;
}

/**************************************************************************
 Function Name: operator==()
 Description: checks if iterators are equal
 **************************************************************************/

template <class T>
bool DequeIterator<T>::operator==(const iterator & r) {
    return theDeque == r.theDeque && index == r.index;
}

/**************************************************************************
 Function Name: operator!=()
 Description: checks if iterators are not equal
 **************************************************************************/

template <class T>
bool DequeIterator<T>::operator!=(const iterator & r) {
    return theDeque != r.theDeque || index != r.index;
}

/**************************************************************************
 Function Name: operator<()
 Description: checks if passed in iterator is greater than current one
 **************************************************************************/

template <class T>
bool DequeIterator<T>::operator<(const iterator & r) {
    return theDeque == r.theDeque && index < r.index;
}

/**************************************************************************
 Function Name: operator[]()
 Description: subscript operator, returns value at index, no bounds checking
 **************************************************************************/

template <class T>
T & DequeIterator<T>::operator[](unsigned int i) {
    return (*theDeque)[index + i];
}

/**************************************************************************
 Function Name: operator=()
 Description: iterator assignment operation
 **************************************************************************/

template <class T>
DequeIterator<T> DequeIterator<T>::operator=(const iterator & r) {
    theDeque = r.theDeque;
    index = r.index;
    return *this;
}

/**************************************************************************
 Function Name: operator+()
 Description: increases iterator by passed in int value
 **************************************************************************/

template <class T>
DequeIterator<T> DequeIterator<T>::operator+(int i) {
    index =+ i;
    return *this;
}

/**************************************************************************
 Function Name: operator-()
 Description: decreases iterator by passed in int value.  Checks if new value
 will be below 0 before performing operation.
 **************************************************************************/

template <class T>
DequeIterator<T> DequeIterator<T>::operator-(int i) {
    if (index - i >= 0)
        index -= i;
    return *this;
}

#endif
