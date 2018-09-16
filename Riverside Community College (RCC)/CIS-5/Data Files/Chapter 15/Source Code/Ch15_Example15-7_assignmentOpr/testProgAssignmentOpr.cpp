#include <iostream>

#include "classAssignmentOverload.h"

using namespace std;

int main()
{
    cAssignmentOprOverload intList1(10);             //Line 10
    cAssignmentOprOverload intList2;                 //Line 11
    cAssignmentOprOverload intList3;                 //Line 12

    int i;                                           //Line 13
    int number;                                      //Line 14

    cout << "Line 15: Enter 5 integers: ";           //Line 15

    for (i = 0; i < 5; i++)                          //Line 16
    {
        cin >> number;                               //Line 17
        intList1.insertEnd(number);                  //Line 18
    }

    cout << endl << "Line 19: intList1: ";           //Line 19
    intList1.print();                                //Line 20

    intList3 = intList2 = intList1;                  //Line 21

    cout << "Line 22: intList2: ";                   //Line 22
    intList2.print();                                //Line 23

    intList2.destroyList();                          //Line 24

    cout << endl;                                    //Line 25
    cout << "Line 26: intList2: ";                   //Line 26
    intList2.print();                                //Line 27

    cout << "Line 28: After destroying intList2, "
         << "intList1: ";                            //Line 28
    intList1.print();                                //Line 29

    cout << "Line 30: After destroying intList2, "
         << "intList3: ";                            //Line 30
    intList3.print();                                //Line 31
    cout << endl;                                    //Line 32

    return 0;
}

