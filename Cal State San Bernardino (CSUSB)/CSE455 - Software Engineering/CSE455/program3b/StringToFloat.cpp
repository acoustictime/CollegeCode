// Name: James Small
// Program: 3B
// Class: CSE455
// Description: StringToFloat class implementation file

#include "StringToFloat.h"
#include <stdlib.h> // for atof
#include <ctype.h> // for isdigit

StringToFloat::StringToFloat()
{
	currentFloat = 0;
}

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

float StringToFloat::getFloatValue()
{
	return currentFloat;
}
