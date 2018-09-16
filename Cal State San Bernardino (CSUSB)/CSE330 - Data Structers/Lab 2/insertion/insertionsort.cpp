/********************************************************************************
 James Small
 Date Start: 1-23-12  Date End: 1-26-12
 Filename: insertionsort.cpp
 Description: Program allows user to enter the size of the vector, and the 
              system will generate n amount of random numbers.  It will then pass 
	      the vector to a function called sort that will sort the vector
	      using the insertion sort method.
 *******************************************************************************/

#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

void sort(vector<int> & v);

int main()
{
    int n;
    vector<int> v;
    srand(time(0));
 
    cin >> n;

    for (int i = 0;i < n;i++)
        v.push_back(rand() % 1000);
 
    sort(v);

    for (int i = 0; i < n;i++)
        cout << endl << v[i];
}

/**************************************************************************
 Function Name: sort
 Description: Sort takes as it's a argument a vector of ints passed by
	      reference and then sorts it using the insertionsort algorithm.
 **************************************************************************/

void sort(vector<int> & v)
{
    int elem,j;
    
    for (int i = 1; i < v.size(); i++) {
        for (elem = v[i], j = i-1; j >=0 and elem < v[j]; j--) {
            v[j+1] = v[j];
        }
        v[j+1] = elem;  
    }
}



