// Name: James Small
// Program: 3A
// Class: CSE455
// Description: ClassInfo class Implementation File

#include "ClassInfo.h"

using namespace std;

// This is the default constructor

ClassInfo::ClassInfo(string className, int methodCount, int lineCount)
{
    this->className = className;
    this->methodCount = methodCount;
    this->lineCount = lineCount;
}

// This is the getter method for className

string ClassInfo::getClassName()
{
    return className;
}

// This is the getter method for methodCount

int ClassInfo::getMethodCount()
{
    return methodCount;
}

// This is the getter method for lineCount

int ClassInfo::getLineCount()
{
    return lineCount;
}
