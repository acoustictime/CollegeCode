// Name: James Small
// Program: 3B
// Class: CSE455
// Description: StringToFloat class implementation file

#include "StringToFloat.h"
#include <stdlib.h> // for atof
#include <ctype.h> // for isdigit

// Constructor which sets the currentFloat to 0

StringToFloat::StringToFloat()
{
	currentFloat = 0;
}

// This method takes a string and returns true or false if a float

bool StringToFloat::isStringAFloat(string stringToTest)
{
	currentString = stringToTest;	
	int periodsCount = 0;
	bool nonDigitFound = false;
	bool isFloat = false;

	for (int i = 0;i < currentString.length(); i++) {
		if (!isdigit(currentString[i])) {
			if (currentString[i] == '.') {
				periodsCount++;
			}
			else if (currentString[i] == '-') { 
				if (i != 0)
					nonDigitFound = true;
			} else 
				nonDigitFound = true;			
		}	
	}

	if (!nonDigitFound && periodsCount < 2) {
		isFloat = true;
		currentFloat = atof(currentString.c_str());
	}

	return isFloat;
}

// This method returns the float value

float StringToFloat::getFloatValue()
{
	return currentFloat;
}