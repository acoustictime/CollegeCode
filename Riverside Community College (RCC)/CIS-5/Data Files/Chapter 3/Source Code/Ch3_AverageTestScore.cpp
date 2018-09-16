//Program to calculate the average test score.
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{
        //Declare variables; Step 1
    ifstream inFile; //input file stream variable
    ofstream outFile; //output file stream variable

    int test1, test2, test3, test4, test5;
    double average;
    char studentId;

    inFile.open("a:\\test.txt");                   //Step 2
    outFile.open("a:\\testavg.out");               //Step 3

    outFile << fixed << showpoint;                 //Step 4
    outFile << setprecision(2);                    //Step 4

    cout << "Processing data" << endl;

    inFile >> studentId;                           //Step 5
    outFile << "Student ID: " << studentId 
            << endl;                               //Step 6

    inFile >> test1 >> test2 >> test3 
           >> test4 >> test5;                      //Step 7
    outFile << "Test scores: " << setw(4) << test1
            << setw(4) << test2 << setw(4) << test3
            << setw(4) << test4 << setw(4) << test5 
            << endl;                               //Step 8

    average = static_cast<double>(test1 + test2 + test3
                          + test4 + test5) / 5.0;  //Step 9
    outFile << "Average test score: " << setw(6) 
            << average << endl;                    //Step 10

    inFile.close();                                //Step 11
    outFile.close();                               //Step 11

    return 0;
}
