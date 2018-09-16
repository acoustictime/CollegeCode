// Name: James Small
// Program: 3B
// Class: CSE455
// Description: Class to convert string to float, if possible

#ifndef STRINGTOFLOAT_H
#define STRINGTOFLOAT_H

#include <string>

using namespace std;

class StringToFloat
{
	public:
		StringToFloat();
		bool isStringAFloat(string stringToTest);
		float getFloatValue();

	private:
		string currentString;	
		float currentFloat;
};
#endif
