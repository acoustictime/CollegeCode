/********************************************************************************
 James Small
 Date Start: 1-23-12  Date End: 1-26-12
 Filename: bubblesort.cpp
 Description: Program allows user to enter the size of the vector, and the 
              system will generate n amount of random numbers.  It will then pass 
	      the vector to a function called sort that will sort the vector
	      using the bubblesort method.
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
	      reference and then sorts it using the bubblesort algorithm.
 **************************************************************************/

void sort(vector<int> & v)
{
    for (int i = v.size()-1; i > 0; i--)
        for (int j = 0; j < i; j++)
            if (v[j] > v[j+1])
                swap(v[j], v[j+1]);
}

