/********************************************************************************
 James Small
 Date Start: 2-10-12  Date End: 2-13-12
 Filename: List.h
 Description: This is the template class for my own List class.  The functions
              used were based ont he List_test.cpp file that was given to us.  This
              template class also contains the definition and functions for the
              Link class and the List_iterator class that the List class actively
              uses.   
 *******************************************************************************/

#ifndef LIST_H
#define LIST_H

// List.h - a doubly-linked list

#include <iostream>
#include <algorithm>

using namespace std;

// forward declaration of classes defined in this header
template <class T> class Link;
template <class T> class List_iterator;

template <class T> 
class List
{
public:
    typedef List_iterator<T> iterator;
    
    List();
    List(const List<T> & l);
    ~List(); 
    
    bool empty() const; 
    unsigned int size() const; 
    T & back() const; 
    T & front() const; 
    void push_front(const T & x); 
    void push_back(const T & x); 
    void pop_front(); 
    void pop_back(); 
    iterator begin() const; 
    iterator end() const; 
    void insert(iterator pos, const T & x); // insert x before pos
    void erase(iterator & pos);             // pos must be valid after erase() returns
    List<T> & operator=(const List<T> & l);
    
protected:
    Link<T> * first_link;
    Link<T> * last_link;
    unsigned int my_size;
};

/**************************************************************************
 Function Name: List()
 Description: Default constructor with no parameters that initializes variables.
 **************************************************************************/

template <class T>
List<T>::List()
{
    first_link = 0;
    last_link = 0;
    my_size = 0;
}

/**************************************************************************
 Function Name: List(const List & l)
 Description: Default constructor with with list object parameter that
              intitalizes object based on passed in object
 **************************************************************************/

template <class T>
List<T>::List(const List & l) {
    first_link = 0;
    last_link = 0;
    my_size = 0;
    for (Link<T> * current = l.first_link; current != 0; current = current -> next_link)
        push_back(current -> value);
}

/**************************************************************************
 Function Name: ~List()
 Description: Deconstructor that deletes dynamically created links
 **************************************************************************/

template <class T>
List<T>::~List() {
    Link<T> * first = first_link;
    
    while (first != 0) {
        Link<T> * next = first -> next_link;
        if (first != 0) {
            delete first;
        }
        first = next;
    }
    first_link = 0;
    last_link = 0;
    my_size = 0;
}

/**************************************************************************
 Function Name: empty()
 Description: Returns true if list is empty
 **************************************************************************/

template <class T>
bool List<T>::empty() const {
    return my_size == 0;
}

/**************************************************************************
 Function Name: size()
 Description: returns the size of the list
 **************************************************************************/

template <class T>
unsigned int List<T>::size() const {
    return my_size;
}

/**************************************************************************
 Function Name: back()
 Description: Returns the last value in the list
 **************************************************************************/

template <class T>
T & List<T>::back() const {
    return last_link -> value;
}

/**************************************************************************
 Function Name: front()
 Description: returns the first value in the list
 **************************************************************************/

template <class T>
T & List<T>::front() const {
    return first_link -> value;
}

/**************************************************************************
 Function Name: begin()
 Description: returns an iterator to the first item in the list
 **************************************************************************/

template <class T>
typename List<T>::iterator List<T>::begin() const {
    return iterator(first_link);
}

/**************************************************************************
 Function Name: end()
 Description: Default returns an iterator to one past the last item in the list
 **************************************************************************/

template <class T>
typename List<T>::iterator List<T>::end() const {
	return iterator(); 
}

/**************************************************************************
 Function Name: insert(iterator pos, const T & x)
 Description: Takes as parameters an iterator and value.  Inserts the value
              in a new link before the position of the iterator
 **************************************************************************/

template <class T>
void List<T>::insert(iterator pos, const T & x) {
    Link<T> * new_link = new Link<T>(x);
    
    if (my_size == 0)
        first_link = last_link = new_link;
    else if (pos == begin())
        push_front(x);
    else if (pos == end())
        push_back(x);
    else {         
        Link<T> * temp_link = pos.current_link -> prev_link;        
        new_link -> prev_link = pos.current_link -> prev_link;
        new_link -> next_link = pos.current_link;
        pos.current_link -> prev_link = new_link;
        temp_link -> next_link = new_link;
    } 
    my_size++;
}

/**************************************************************************
 Function Name: erase(iterator & pos)
 Description: Takes as a parameter an iterator and then deletes the link
              at that location.
 **************************************************************************/

template <class T>
void List<T>::erase(iterator & pos) {
    if (my_size <= 1) {
        if (first_link != 0) {
            delete first_link;
        }
        first_link = last_link = 0;
    }
    else {
        if (pos == begin()) {
            pop_front();
        }
        else if (pos.current_link == last_link) {
            pop_back();
        }
        else {  
            Link<T> * next = pos.current_link -> next_link;
            Link<T> * previous = pos.current_link -> prev_link;
            if (pos.current_link != 0) {
                delete pos.current_link;
            }
            pos.current_link = next;
            previous -> next_link = next;
            next -> prev_link = previous;
        }
    }
    my_size--;
}

/**************************************************************************
 Function Name: push_back(const T & x)
 Description: adds new link with passed in value at the end of the list
 **************************************************************************/

template <class T>
void List<T>::push_back(const T & x) {
    Link<T> * new_link = new Link<T>(x);
    
    if (first_link == 0) {
        first_link = last_link = new_link;
    }
    else {
        new_link -> prev_link = last_link;
        last_link -> next_link = new_link;
        last_link = new_link;
    }
    my_size++;
}

/**************************************************************************
 Function Name: push_front(const T & x)
 Description: adds new link with passed in value at the beginning of the list
 **************************************************************************/

template <class T>
void List<T>::push_front(const T & x) {
    Link<T> * new_link = new Link<T>(x);
    
    if (first_link == 0) {
        first_link = last_link = new_link;
    }
    else {
        new_link -> next_link = first_link;
        first_link -> prev_link = new_link;
        first_link = new_link;        
    }
    my_size++;
}

/**************************************************************************
 Function Name: pop_front()
 Description: deletes link at the beginning of the list
 **************************************************************************/

template <class T>
void List<T>::pop_front() {
    if (my_size == 1) {
        if (first_link != 0) {
            delete first_link;
        }
        first_link = last_link = 0;
    }
    else {
        first_link = first_link -> next_link; 
        if (first_link -> prev_link != 0) {
            delete first_link -> prev_link;
        }
        first_link -> prev_link = 0;
    }
    my_size--;    
}

/**************************************************************************
 Function Name: pop_back()
 Description: deletes link at the end of the list
 **************************************************************************/

template <class T>
void List<T>::pop_back() {
    if (my_size == 1) {
        if (first_link != 0) {
            delete first_link;
        }
        first_link = last_link = 0;
    }
    else {
        last_link = last_link -> prev_link; 
        if (last_link -> next_link != 0) {
            delete last_link -> next_link;
        }
        last_link -> next_link = 0;
    }
    my_size--;
}

/**************************************************************************
 Function Name: operator=(const List<T> & l)
 Description: assignment operator.  Deletes current links in list and then
              creates new links based on  passed in List
 **************************************************************************/

template <class T>
List<T> & List<T>::operator=(const List<T> & l) {
    
    if (!empty()) { // deletes Links if not empty
        Link<T> * first = first_link;
        while (first != 0) {
            Link<T> * next = first -> next_link;
            if (first != 0) {
                delete first;
            }
            first = next;
        }
        first_link = 0;
        last_link = 0;
        my_size = 0;
    }
    
    for (iterator it(l.begin()); it != l.end; it++)
        push_back(*it.value);
    return *this; 
}

/**************************************************************************
 Function Name: Link class
 Description: Definition and functions for the Link class used in List
 **************************************************************************/

template <class T> 
class Link 
{
private:
    Link(const T & x): value(x), next_link(0), prev_link(0) {}
    
    T value;     
    Link<T> * next_link;
    Link<T> * prev_link;
    
    friend class List<T>;
    friend class List_iterator<T>;
};

/**************************************************************************
 Function Name: List_iterator class
 Description: Definition and functions for the List_iterator class used in List
 **************************************************************************/

template <class T> class List_iterator
{
public:
    typedef List_iterator<T> iterator;
    
    List_iterator(Link<T> * source_link): current_link(source_link) { }
    List_iterator(): current_link(0) { }
    List_iterator(List_iterator<T> * source_iterator): current_link(source_iterator.current_link) { }
    
    T & operator*();  // dereferencing operator
    iterator & operator=(const iterator & rhs);
    bool operator==(const iterator & rhs) const;
    bool operator!=(const iterator & rhs) const;
    iterator & operator++();  // pre-increment, ex. ++it
    iterator operator++(int); // post-increment, ex. it++
    iterator & operator--();  // pre-decrement
    iterator operator--(int); // post-decrement
    
protected:
    Link<T> * current_link;
    
    friend class List<T>;
};

/**************************************************************************
 Function Name: operator*()
 Description: returns value where iterator is pointing to
 **************************************************************************/

template <class T>
T & List_iterator<T>::operator*()
{
    return current_link -> value;
}

/**************************************************************************
 Function Name: operator=(const iterator & rhs)
 Description: assigns current_link from passed in parameter to implicit 
              current_link
 **************************************************************************/

template <class T>
List_iterator<T> & List_iterator<T>::operator=(const iterator & rhs) {
    current_link = rhs.current_link;
}

/**************************************************************************
 Function Name: operato==(const iterator & rhs)
 Description: returns true if iterators point to same link
 **************************************************************************/

template <class T>
bool List_iterator<T>::operator==(const iterator & rhs) const {
    return current_link == rhs.current_link;
}

/**************************************************************************
 Function Name: operator!=(const iterator & rhs)
 Description: returns true if iterators don't point to same link
 **************************************************************************/

template <class T>
bool List_iterator<T>::operator!=(const iterator & rhs) const {
    
    return current_link != rhs.current_link;
}

/**************************************************************************
 Function Name: operator++()
 Description: pre increment operator that points iterator to next link
 **************************************************************************/

template <class T>
List_iterator<T> & List_iterator<T>::operator++() // pre
{
    current_link = current_link -> next_link;
    return *this;
}

/**************************************************************************
 Function Name: operator++(int)
 Description: post increment operator that points iterator to next link after
              returning *this
 **************************************************************************/

template <class T>
List_iterator<T> List_iterator<T>::operator++(int) // post
{
    List_iterator<T> temp = *this;    
    current_link = current_link -> next_link;
    return temp;
}

/**************************************************************************
 Function Name: operator--()
 Description: pre decrement operator that points iterator to previous link
 **************************************************************************/

template <class T>
List_iterator<T> & List_iterator<T>::operator--() // pre
{
    current_link = current_link -> prev_link;
    return *this;
}

/**************************************************************************
 Function Name: operator--(int)
 Description: post decrement operator that points iterator to previous link
              after returning *this
 **************************************************************************/

template <class T>
List_iterator<T> List_iterator<T>::operator--(int) // post
{
    List_iterator<T> temp = *this;    
    current_link = current_link -> prev_link;
    return temp;
}

#endif
