//Implementation file myStringImp.cpp
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cassert>
#include "myString.h"

using namespace std;

    //constructor: conversion from the char string to newString
newString::newString(const char *str) 
{
   strLength = strlen(str);
   strPtr = new char[strLength + 1]; //allocate memory to store 
  							         //the char string
   assert(strPtr != NULL);
   strcpy(strPtr,str);  //copy string into strPtr
}

//default constructor to store the null string
newString::newString() 
{
	strLength = 0;
	strPtr = new char[1];
	assert(strPtr != NULL);
	strcpy(strPtr,"");
}

newString::newString(const newString& rightStr)  //copy constructor
{
	strLength = rightStr.strLength;
	strPtr = new char[strLength + 1];
	assert(strPtr != NULL);
	strcpy(strPtr, rightStr.strPtr);
}

newString::~newString()  //destructor
{
	delete [] strPtr;
}

  	//overload the assignment operator
const newString& newString::operator=(const newString& rightStr)
{
	if (this != &rightStr) //avoid self-copy
	{
		delete [] strPtr;
		strLength = rightStr.strLength;
		strPtr = new char[strLength + 1];
		assert(strPtr != NULL);
		strcpy(strPtr, rightStr.strPtr);
	}
	return *this; 
}

char& newString::operator[] (int index)
{
	assert(0 <= index && index < strLength);
	return strPtr[index];
}

const char& newString::operator[](int index) const
{
	assert(0 <= index && index < strLength);
	return strPtr[index];
}

//overload the relational operators
bool newString::operator==(const newString& rightStr) const
{
	return (strcmp(strPtr, rightStr.strPtr) == 0);
}

bool newString::operator<(const newString& rightStr) const
{
	return (strcmp(strPtr, rightStr.strPtr) < 0);
}

bool newString::operator<=(const newString& rightStr) const
{
	return (strcmp(strPtr, rightStr.strPtr) <= 0);
}

bool newString::operator>(const newString& rightStr) const
{
	return (strcmp(strPtr, rightStr.strPtr) > 0);
}

bool newString::operator>=(const newString& rightStr) const
{
	return (strcmp(strPtr, rightStr.strPtr) >= 0);
}

bool newString::operator!=(const newString& rightStr) const
{
	return (strcmp(strPtr, rightStr.strPtr) != 0);
}

//overload the stream insertion operator  <<  
ostream& operator << (ostream& osObject, const newString& str)
{
	osObject << str.strPtr;
	return osObject;
}

//overload the stream extraction operator  >>  
istream& operator >> (istream& isObject, newString& str)
{
	char temp[81];

	isObject >> setw(81) >> temp;
	str = temp;
	return isObject;
}
