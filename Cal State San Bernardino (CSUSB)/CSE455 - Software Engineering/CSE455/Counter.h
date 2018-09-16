// Name: James Small
// Program: 3A
// Class: CSE455
// Description: Counter class Header File

#ifndef COUNTER_H
#define COUNTER_H

#include <string>
#include <vector>
#include "ClassInfo.h"

using namespace std;

class Counter
{
    public:
        Counter(string fileName);
        void calculateLOC();
        void displayReport();

    private :
        string currentFileName;
        int methodCount();
        vector<ClassInfo> classVector;
        vector<string> classListVector();
        string classNameWithoutExtension(string className);
};
#endif
