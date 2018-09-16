/********************************************************************************
 James Small
 Date Start: 1-30-12  Date End: 2-1-12
 Filename: Vector.h
 Description: This is the template class for my own Vector class.  The functions
              used were based on the test.cpp file that was given to us.    
 *******************************************************************************/

#ifndef VECTOR_H
#define VECTOR_H

using namespace std;

template <class T>
class Vector
{
public:
    
    typedef T * iterator;
    
    Vector();
    Vector(unsigned int size);
    Vector(unsigned int size, const T & initial);
    Vector(const Vector<T> & v);           // copy constructor
    ~Vector();
    
    unsigned int capacity() const;         // return capacity of vector (in elements)
    unsigned int size() const;             // return the number of elements in the vector
    bool empty() const;
    
    iterator begin();                      // return an iterator pointing to the first element
    iterator end();                        // return an iterator pointing to one past the last element
    T & front();                           // return a reference to the first element
    T & back();                            // return a reference to the last element
    void push_back(const T & value);       // add a new element
    void pop_back();                       // remove the last element
    
    void reserve(unsigned int capacity);   // adjust capacity
    void resize(unsigned int size);        // adjust size
    
    T & operator[](unsigned int index);    // return reference to numbered element
    Vector<T> & operator=(const Vector<T> & source);
    
private:
    unsigned int my_size;
    unsigned int my_capacity;
    T * buffer;
};

/**************************************************************************
 Function Name: Vector()
 Description: Default constructor with no parameters that initializes variables.
 **************************************************************************/

template <class T>
Vector<T>::Vector() {
    my_size = 0;
    my_capacity = 0;
    buffer = 0;
}

/**************************************************************************
 Function Name: Vector(unsigned int size)
 Description: Default constructor with size.  Create buffer with T() values
 **************************************************************************/

template <class T>
Vector<T>::Vector(unsigned int size) {
    my_size = size;
    my_capacity = my_size;
    buffer = new T[my_capacity];
    for (int i = 0; i < my_size; i++) {
        buffer[i] = T();
    }
    
}

/**************************************************************************
 Function Name: Vector(unsigned int size, const T& initial)
 Description: Default constructor with size and initial value.  Create buffer
	      with initial values.
 **************************************************************************/

template <class T>
Vector<T>::Vector(unsigned int size, const T & initial) {
    my_size = size;
    my_capacity = my_size;
    buffer = new T[my_size];
    for (int i =0; i < my_size; i++)
        buffer[i] = initial;
}

/**************************************************************************
 Function Name: Vector(const Vector<T> & v)
 Description: Default constructor with Vector object parameter.  Creates
              buffer based on passed in Vector object
 **************************************************************************/

template <class T>
Vector<T>::Vector(const Vector<T> & v) {
    my_size = v.my_size;
    my_capacity = v.my_capacity;
    buffer = new T[my_capacity];
    for (int i = 0; i < my_capacity; i++)
        buffer[i] = v.buffer[i];
}

/**************************************************************************
 Function Name: ~Vector()
 Description: Deconstructor that deletes buffer from heap
 **************************************************************************/

template <class T>
Vector<T>::~Vector() {
    delete [] buffer;
}

/**************************************************************************
 Function Name: capacity()
 Description: Returns int for capacity
 **************************************************************************/

template <class T>
unsigned int Vector<T>::capacity() const {
    return my_capacity;
}

/**************************************************************************
 Function Name: size()
 Description: Returns int for size
 **************************************************************************/

template <class T>
unsigned int Vector<T>::size() const {
    return my_size;
}

/**************************************************************************
 Function Name: empty()
 Description: Returns true if buffer empty, false if not
 **************************************************************************/

template <class T>
bool Vector<T>::empty() const {
    if (my_size <= 0) 
        return true;

    return false;
}

/**************************************************************************
 Function Name: front()
 Description: Returns reference to first element in buffer
 **************************************************************************/

template <class T>
T & Vector<T>::front() { 
    return buffer[0];
}

/**************************************************************************
 Function Name: back()
 Description: Returns reference to alst element in buffer
 **************************************************************************/

template <class T>
T & Vector<T>::back() { 
    return buffer[my_size - 1];
}

/**************************************************************************
 Function Name: reserve(unsigned int capacity)
 Description: Increases capacity of buffer by passed in parameter. Deallocates
	      and allocates memory accordingly for buffer
 **************************************************************************/

template <class T>
void Vector<T>::reserve(unsigned int capacity) {
    Vector<T> temp = *this;
    my_capacity = capacity;
    delete [] buffer;
    buffer = new T[my_capacity];
    for (int i = 0; i < my_size; i++)
        buffer[i] = temp.buffer[i];

    for (int i = my_size; i < my_capacity; i++) 
        buffer[i] = T();
}

/**************************************************************************
 Function Name: resize(unsigned int size)
 Description: Increases size of buffer by passed in parameter.  If capacity
              is full, increases capacity by one.
 **************************************************************************/

template <class T>
void Vector<T>::resize(unsigned int size) { 
    if (my_size == my_capacity)
        reserve(my_capacity + 1 );
    my_size = size;
}

/**************************************************************************
 Function Name: operator=(const Vector<T> & source)
 Description: Assignemnet operator that copies source object parameter to 
              implicit object.
 **************************************************************************/

template <class T>
Vector<T> & Vector<T>::operator=(const Vector<T> & source) {
    delete [] buffer;
    my_capacity = source.my_capacity;
    my_size = source.my_size;
    buffer = new T[my_capacity];
    for (int i = 0; i < my_size; i++)
        buffer[i] = source.buffer[i];

    for	(int i = my_size; i < my_capacity; i++)
        buffer[i] = T();

    return *this;
}

/**************************************************************************
 Function Name: operator[](unsigned int index)
 Description: returns value at passed in parameter index.  Checks if index
              is valed before returning
 **************************************************************************/

template <class T>
T & Vector<T>::operator[](unsigned int index) {
    return buffer[index];
}

/**************************************************************************
 Function Name: pop_back()
 Description: Adds element to vector using resize function
 **************************************************************************/

template <class T>
void Vector<T>::pop_back() {
    resize(--my_size);
}

/**************************************************************************
 Function Name: push_back(const T & value)
 Description: Adds passed in value to end of buffer.  If capacity is full,
              uses the reserve function to increase capacity by 5.
 **************************************************************************/

template <class T>
void Vector<T>::push_back(const T & value) {
    if (my_size == my_capacity) 
        reserve(my_capacity + 5);
    
    buffer[my_size++] = value;
}

/**************************************************************************
 Function Name: iterator begin()
 Description: returns a pointer to beginning of buffer
 **************************************************************************/

template <class T>
typename Vector<T>::iterator Vector<T>::begin() {
    return buffer;
}

/**************************************************************************
 Function Name: iterator end()
 Description: returns a pointer to one past the end of buffer
 **************************************************************************/

template <class T>
typename Vector<T>::iterator Vector<T>::end() {
    return buffer + my_size;
}

#endif
