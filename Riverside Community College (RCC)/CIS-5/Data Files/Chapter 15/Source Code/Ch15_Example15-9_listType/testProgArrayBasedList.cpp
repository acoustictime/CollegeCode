#include <iostream>

#include "myString.h"
#include "listType.h"

using namespace std;

int main()
{
    listType<int> intList(100);                     //Line 1
    listType<newString> stringList;                 //Line 2

    int index;                                      //Line 3
    int number;                                     //Line 4

    cout << "List 5: Processing the integer list"
         << endl;                                   //Line 5
    cout << "List 6: Enter 5 integers: ";           //Line 6
                                 
    for (index = 0; index < 5; index++)             //Line 7
    {    
        cin >> number;                              //Line 8
        intList.insertAt(number, index);            //Line 9
    }

    cout << endl;                                   //Line 10
    cout << "List 11: The list you entered is: "
         << endl;                                   //Line 11
    intList.print();                                //Line 12
    cout << endl;                                   //Line 13

    cout << "Line 14: After sorting, the list is: "
         << endl;                                   //Line 14
    intList.sort();                                 //Line 15
    intList.print();                                //Line 16
    cout << endl;                                   //Line 17

    newString str;                                  //Line 18

    cout << "Line 19: Processing the string list"
         << endl;                                   //Line 19

    cout << "Line 20: Enter 5 strings: ";           //Line 20

    for (index = 0; index < 5; index++)             //Line 21
    {
        cin >> str;                                 //Line 22
        stringList.insertAt(str, index);             //Line 23
    }

    cout << endl;                                   //Line 24
    cout << "Line 25: The list you entered is: "
         << endl;                                   //Line 25
    stringList.print();                             //Line 26
    cout << endl;                                   //Line 27
    cout << "Line 28: After sorting, the list is: "
         << endl;                                   //Line 28
    stringList.sort();                              //Line 29
    stringList.print();                             //Line 30
    cout << endl;                                   //Line 31    
    
    int intListSize;                                //Line 32

    cout << "Line 33: Enter the size of the integer "
         << "list: ";                               //Line 33
    cin >> intListSize;                             //Line 34
   
    listType<int> intList2(intListSize);            //Line 35

    cout << "Line 36: Processing the integer list"
         << endl;                                   //Line 36
    cout << "Line 37: Enter " << intListSize
         << " integers: ";                          //Line 37

    for (index = 0; index < intListSize; index++)   //Line 38
    {
        cin >> number;                              //Line 39
        intList2.insertAt(number, index);            //Line 40
    }

    cout << endl;                                   //Line 41
    cout << "Line 42: The list you entered is: " 
         << endl;                                   //Line 42
    intList2.print();                               //Line 43
    cout << endl;                                   //Line 44
    cout << "Line 45: After sorting, the list is: "
         << endl;                                   //Line 45
    intList2.sort();                                //Line 46
    intList2.print();                               //Line 47
    cout << endl;                                   //Line 48
    cout << "Line 49: Length of the list = "
         << intList2.getLength() << endl;           //Line 49
    cout << "Line 50: Maximum size of the list = "
         << intList2.getMaxSize() << endl;          //Line 50

    return 0;
}
