// Name: James Small
// Program: 4a
// Class: CSE455
// Description: Class to calculate the linear regression of a set of numbers

#ifndef LINEARREGRESSION_H
#define LINEARREGRESSION_H

#include <string>
#include <vector>
#include "FileCheck.h"

using namespace std;

class LinearRegression
{
	public:
        LinearRegression();
        bool getGood();
        void report();
    
    private:
        float b0Value;
        float b1Value;
        bool fileNamesGood;
        string fileName1;
        string fileName2;
        FileCheck fileCheck;
        vector<float> vector1;
        vector<float> vector2;
        void calculate();
        void readInValues(string fileName, vector<float> &vector);
        float averageOfVector(vector<float> vector);
        vector<float> multiplyValues(vector<float> vector1, vector<float> vector2);
        float sumValues(vector<float> vector);
        bool enterNewFileName(string &fileName);
};
#endif