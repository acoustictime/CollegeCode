#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> intList;                     //Line 1
    unsigned int i;                          //Line 2

    intList.push_back(13);                   //Line 3
    intList.push_back(75);                   //Line 4
    intList.push_back(28);                   //Line 5
    intList.push_back(35);                   //Line 6

    cout << "Line 7: List Elements: ";       //Line 7

    for (i = 0; i < intList.size(); i++)     //Line 8
        cout << intList[i] << " ";           //Line 9
    cout << endl;                            //Line 10

    for (i = 0; i < intList.size(); i++)     //Line 11
        intList[i] = intList[i] * 2;         //Line 12

    cout << "Line 13: List Elements: ";      //Line 13

    for (i = 0; i < intList.size(); i++)     //Line 14
        cout << intList[i] << " ";           //Line 15

    cout << endl;                            //Line 16

    return 0;
}

