/********************************************************************************
 James Small
 Date Start: 1-27-12  Date End: 1-28-12
 Filename: String.cpp
 Description: This is the implemenation file for my own String class.  This is 
              created without using the built in C++ string class.  Instead of 
	      using null terminated strings, we maintain the size of the buffer
	      ourselves.  The functions were defined based on the test.cpp file
	      that was given to us.  Implemenation for each function is below.
 *******************************************************************************/

#include <iostream>
#include "String.h"
#include <cstring>
#include <cassert>

/**************************************************************************
 Function Name: String()
 Description: Default constructor with no parameters that initializes variables.
 **************************************************************************/

String::String() {
    size = 0;
    buffer = 0;
}

/**************************************************************************
 Function Name: String(const char * p)
 Description: Constructor that initialzes variables based on passed in c String
 **************************************************************************/

String::String(const char * p) {
    size = strlen(p);
    buffer = new char[size];
    for (int i = 0; i < size; i++)
        buffer[i] = p[i];
}

/**************************************************************************
 Function Name: String(const String & source)
 Description: Constructor that initialzes variables based on passed in string
              object.
 **************************************************************************/

String::String(const String & source) {
    size = source.size;
    buffer = new char[size];
    for (int i = 0; i < size; i++)
        buffer[i] = source.buffer[i];
}

/**************************************************************************
 Function Name: ~String()
 Description: Deconstructor that deallocates the memory dynamically created.
 **************************************************************************/

String::~String() {
  delete [] buffer;
}

/**************************************************************************
 Function Name: length()
 Description: returns the length of the String from the size variable
 **************************************************************************/

int String::length() {
    return size;
}

/**************************************************************************
 Function Name: operator=(const char * p)
 Description: Overloaded = operator that assigns values based on passed in
                           c string
 **************************************************************************/

String String::operator=(const char * p) {
    delete [] buffer;
    size = strlen(p);
    buffer = new char[size];
    for (int i = 0; i < size; i++) 
        buffer[i] = p[i];
    return *this;
}

/**************************************************************************
 Function Name: operator=(const String & source)
 Description: Overloaded = operator that assigns values based on passed in
                           String object
 **************************************************************************/

String String::operator=(const String & source) {
    delete [] buffer;
    size = source.size;
    buffer = new char[size];
    for (int i = 0; i < size; i++) 
        buffer[i] = source.buffer[i];
    return *this;
}

/**************************************************************************
 Function Name: operator==(const char * p)
 Description: Overloaded == operator that returns true if passed in c string
              matches variables, false if doesnt.
 **************************************************************************/

bool String::operator==(const char * p) {
    if (size == strlen(p)) {
        for (int i = 0; i < size; i++) {
            if (buffer[i] != p[i]) 
                return false;
        }
        return true;
    }
    return false;
}

/**************************************************************************
 Function Name: operator==(const String & source)
 Description: Overloaded == operator that returns true if passed in string
              object matches variables, false if doesnt.
 **************************************************************************/

bool String::operator==(const String & source) {
    if (size == source.size) {
        for (int i = 0; i < size; i++) {
            if (buffer[i] != source.buffer[i])
                return false;
        }
        return true;
    }
    return false;
}

/**************************************************************************
 Function Name: operator+=(const char * p)
 Description: Overloaded += operator that combines passed in c string with
              current values in String.
 **************************************************************************/


String String::operator+=(const char * p) { 
    String temp = *this;
    size = temp.size + strlen(p);
    delete [] buffer;
    buffer = new char[size];
    
    for (int i = 0; i < temp.size; i++) 
        buffer[i] = temp.buffer[i];
    
    for (int i = size - strlen(p); i < size; i++)
        buffer[i] = p[i - temp.size];

    return *this;
}

/**************************************************************************
 Function Name: operator+=(const String & source)
 Description: Overloaded += operator that combines passed in string object
              with current values in String.
 **************************************************************************/

String String::operator+=(const String & source) { 
    String temp = *this;
    size = temp.size + source.size;
    delete [] buffer;
    buffer = new char[size];
    
    for (int i = 0; i < temp.size; i++) 
        buffer[i] = temp.buffer[i];

    for (int i = size - source.size; i < size; i++) 
        buffer[i] = source.buffer[i - temp.size];

    return *this;
}

/**************************************************************************
 Function Name: operator[](int index)
 Description: Overloaded [] operator.  Checks if the subscript requested does
              exist.  If so, returns the value at that subscript
 **************************************************************************/

char String::operator[](int index) {
    
    assert (index <= size);
    return buffer[index];
}




