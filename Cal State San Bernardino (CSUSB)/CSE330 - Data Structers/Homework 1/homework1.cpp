/**************************************************************************
 James Small
 Date Start: 1-14-12  Date End: 1-16-12
 Filename: homework1.cpp
 Description: Program takes as input values of type double until end of file
 is reached and stores them in a array.  If the array begins to fill up, a
 new array is dynamically allocated to hold the values.  This process is
 repeated until done entering values.  It then passes the values to a 
 function, variance, which returns the variance of the values entered.
 **************************************************************************/
 
#include <iostream>
#include <cmath>

using namespace std;

const int ARRAY_INCREASE = 25;

double variance(int n,double values[]);

int main()
{
    int count = 0;
    double current = 0;
    int arraySize = ARRAY_INCREASE;
    
    double * values = new double[arraySize];
    
    cout << "Enter Values One at a time, press Ctrl D when done";
    cout << "\nValue " << count + 1 << ": ";
    cin >> current;
        
    while (!cin.eof()) {
        count++;
        
        values[count - 1] = current;
        
        if (count == arraySize) {
           
            arraySize += ARRAY_INCREASE;
            
            double * temp = new double[arraySize]; 
            
            for (int i = 0; i < count; i++)
                temp[i] = values[i];
            
            delete [] values;
            values = temp;            
        }
        
        cout << "\nValue " << count + 1 << ": ";
        cin >> current;
    }
    
    cout << "\n\nVariance = " << variance(count,values) << endl << endl;
    
} //main

/**************************************************************************
 Function Name: variance
 Description: variance takes as parameters an int for the amount doubles and
 a array of type double containing the actual values.  First, calculates
 the average of the values entered.  Next, calculates the variance using the
 average of the values.  Lastly, returns the variance back to main.
 **************************************************************************/

double variance(int n,double values[])
{
    double average = 0;
    double variance = 0;
    
    for (int i = 0; i < n; i++ )
        average += values[i];
    
    average /= n;
    
    for (int i =0; i < n; i++ )
        variance += pow((values[i] - average),2);
    
    variance /= (n-1);
    
    return variance;
    
} //variance