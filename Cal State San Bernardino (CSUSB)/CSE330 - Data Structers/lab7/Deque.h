/********************************************************************************
 James Small
 Date Start: 2-27-12  Date End: 3-4-12
 Filename: Deque.h
 Description: This is the template class for my own Deque Class.  The functions
 used were based on the Deque_test.cpp file that was given to us.  This
 template class also contains the definition and functions for the
 DequeIterator class that the Deque class actively.  This deque is implemented
 using two vectors.  The deque goes from the back of the first deque to the bottom
 of it.  Then from the front of the second vector to the top.  
 *******************************************************************************/

#ifndef DEQUE_H
#define DEQUE_H

// Deque.h - an implementation of double-ended queue

#include <vector>
#include <iostream>

using namespace std;

template <class T> class DequeIterator;

template <class T>
class Deque {
public:
    typedef DequeIterator<T> iterator;
	
    Deque(): vecOne(), vecTwo() { }
    Deque(unsigned int size, T& initial): vecOne(size/2, initial), vecTwo(size-(size/2), initial) { }
    Deque(Deque<T> & d): vecOne(d.vecOne), vecTwo(d.vecTwo) { }

    T & operator[](unsigned int);
    T & front();
    T & back();
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
    vector<T> vecOne;
    vector<T> vecTwo;
};

/**************************************************************************
 Function Name: operator[]
 Description: Subscript operator that returns the value at the passed in 
              index.  It doesn't do any bounds checking because the STL
              version of deque doesnt.
 **************************************************************************/

template <class T>
T & Deque<T>::operator[](unsigned int index) {
    // Didn't check for out of bounds because STL doesnt
    int n = vecOne.size();
    if (index < n)
        return vecOne[n - 1 - index];
    else
        return vecTwo[index - n];
}

/**************************************************************************
 Function Name: front()
 Description: Returns a reference to the first element in the deque.  Returns
              nothing if both vectors empty.
 **************************************************************************/

template <class T>
T & Deque<T>::front() {
    // if both vectors, empty, nothing is returned
    if (vecOne.empty()) {
        if (!vecTwo.empty()) 
            return vecTwo.front();
    }
    else
        return vecOne.back();
}

/**************************************************************************
 Function Name: back()
 Description: Returns a reference to the last element in the deque. Returns 
              nothing if both vectors emtpy.
 **************************************************************************/

template <class T>
T & Deque<T>::back() {
    // if both vectors, empty, nothing is returned
    if (vecTwo.empty()) {
        if (!vecOne.empty())
            return vecOne.front(); 
    }
    else
        return vecTwo.back();
}

/**************************************************************************
 Function Name: empty()
 Description: Returns true if both vectors are empty
 **************************************************************************/

template <class T>
bool Deque<T>::empty() {
    return vecOne.empty() && vecTwo.empty();
}

/**************************************************************************
 Function Name: begin()
 Description: Returns an iterator to the first element
 **************************************************************************/

template <class T>
typename Deque<T>::iterator Deque<T>::begin() {
    return iterator(this,0); 
}

/**************************************************************************
 Function Name: end()
 Description: Returns an iterator to one past the last element
 **************************************************************************/

template <class T>
typename Deque<T>::iterator Deque<T>::end() {
    return iterator(this,size()); 
}

/**************************************************************************
 Function Name: erase(const iterator &)
 Description: Erases value at passed in index. If index is out of bounds,
              it returns without doing anything.
 **************************************************************************/

template <class T>
void Deque<T>::erase(const iterator & itr) {

    if (itr.index < 0 || itr.index >= size()) // index bounds checking
        return;
    
    if (itr.index < vecOne.size())
        vecOne.erase(vecOne.begin() + ((vecOne.size() - 1) - itr.index));
    else
        vecTwo.erase(vecTwo.begin() + (itr.index - vecOne.size()));
}

/**************************************************************************
 Function Name: erase(const iterator &, const iterator &)
 Description: Erases value between passed in iterators up to but not including
              the second iterator.  Does lots of bounds checking before hand.
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
 Function Name: insert()
 Description: inserts value before passed in index.  If index is out of
              bounds, it returns without doing anything.
 **************************************************************************/

template <class T>
void Deque<T>::insert(const iterator & itr, const T & x) {
    if (itr.index > size() || itr.index < 0) 
        return;
    
    if (itr.index < vecOne.size()) 
        vecOne.insert(vecOne.begin() + vecOne.size() - itr.index,x);
    else 
        vecTwo.insert(vecTwo.begin() + itr.index - vecOne.size(),x);
}

/**************************************************************************
 Function Name: size()
 Description: Returns the size of the deque
 **************************************************************************/

template <class T>
int Deque<T>::size() {
    return vecOne.size() + vecTwo.size();
}

/**************************************************************************
 Function Name: push_front()
 Description: inserts value at front of deque
 **************************************************************************/

template <class T>
void Deque<T>::push_front(const T & value) {
    vecOne.push_back(value);
}

/**************************************************************************
 Function Name: push_back()
 Description: inserts value at back of deque
 **************************************************************************/

template <class T>
void Deque<T>::push_back(const T & value) {
    vecTwo.push_back(value);
}

/**************************************************************************
 Function Name: pop_front()
 Description: removes value at front of deque.  Checks if vector is empty
              beforehand so it pops from the correct vector
 **************************************************************************/

template <class T>
void Deque<T>::pop_front() {
    // if both vectors empty, no pop_front performed
    if (vecOne.empty()) {
        if (!vecTwo.empty()) {
            for (int i = 0; i < vecTwo.size() - 1; i++) 
                vecTwo[i] = vecTwo[i + 1];
            vecTwo.pop_back(); 
        }
    }
    else
        vecOne.pop_back();
}

/**************************************************************************
 Function Name: pop_back()
 Description: removes value at end of deque.  Checks if vector is empty
 beforehand so it pops from the correct vector
 **************************************************************************/

template <class T>
void Deque<T>::pop_back() {
    // if both vectors empty, no pop_back performed
    if (vecTwo.empty()) {
        if (!vecOne.empty()) {
            for (int i = 0; i < vecOne.size() - 1; i++)
                vecOne[i] = vecOne[i + 1];
            vecOne.pop_back();
        }
    }
    else
        vecTwo.pop_back();        
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
