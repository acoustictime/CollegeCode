/********************************************************************************
 James Small
 Date Start: 1-27-12  Date End: 1-28-12
 Filename: String.h
 Description: This is the header file for my own String class.  This is 
              created without using the built in C++ string class.  Instead of 
	      using null terminated strings, we maintain the size of the buffer
	      ourselves.  The functions were defined based on the test.cpp file
	      that was given to us.
 *******************************************************************************/

#ifndef _String_h
#define _String_h

class String {
private:
    int size;
    char * buffer;

public:
    String();
    String(const char *);
    String(const String &);
    ~String();
    int length();
    String operator=(const char *);
    String operator=(const String &);
    bool operator==(const char *);
    bool operator==(const String &);
    String operator+=(const char *);
    String operator+=(const String &);
    char operator[](int index);
};

#endif
