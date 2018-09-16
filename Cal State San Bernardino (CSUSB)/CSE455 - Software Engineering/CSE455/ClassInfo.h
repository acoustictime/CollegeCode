// Name: James Small
// Program: 3A
// Class: CSE455
// Description: ClassInfo class Header File

#ifndef CLASSINFO_H
#define CLASSINFO_H

#include <string>

using namespace std;

class ClassInfo
{
    public:
        ClassInfo(string className, int methodCount, int lineCount);
        string getClassName();
        int getMethodCount();
        int getLineCount();

    private :
        string className;
        int methodCount;
        int lineCount;
};
#endif
