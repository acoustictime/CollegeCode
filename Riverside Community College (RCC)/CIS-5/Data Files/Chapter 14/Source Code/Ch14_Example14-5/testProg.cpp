#include <iostream>
#include "ptrDataClass.h"

using namespace std;

void testCopyConst(pointerDataClass temp);

int main()
{
    pointerDataClass one(5);                             //Line 1

    one.setData();                                       //Line 2
    cout << "Line 3: ###Object one’s data###" << endl;   //Line 3
    one.print();                                         //Line 4
    cout << "Line 5:______________________________"             
         << "______________" << endl;                    //Line 5

    pointerDataClass two(one);                           //Line 6

    cout << "Line 7: ^^^Object two’s data^^^" << endl;   //Line 7
    two.print();                                         //Line 8
    cout << "Line 9:_______________________________"       
         << "_____________" << endl;                     //Line 9

    two.destroyP();                                      //Line 10
    
    cout << "Line 11: ~~~ Object one’s data after "
         << "destroying object two.p ~~~" << endl;       //Line 11 
    one.print();                                         //Line 12
    cout << "Line 13:_______________________________"
         << "_____________" << endl;                     //Line 13

    cout << "Line 14: Calling the function testCopyConst"
         << endl;                                        //Line 14

    testCopyConst(one);                                  //Line 15

    cout << "Line 16:_______________________________"
         << "_____________" << endl;                     //Line 16

    cout << "Line 17: After a call to the function "
         << "testCopyConst, object one is:" << endl;     //Line 17

    one.print();                                         //Line 18

    return 0;                                            //Line 19
}

void testCopyConst(pointerDataClass temp)
{
    cout << "Line 20: *** Inside the function "
         << "testCopyConst ***" << endl;                 //Line 20

    cout << "Line 21: Object temp data:" << endl;        //Line 21
    temp.print();                                        //Line 22

    temp.setData();                                      //Line 23
    cout << "Line 24: After changing the object "
         << "temp, its data is: " << endl;               //Line 24
    temp.print();                                        //Line 25

    cout << "Line 26: *** Exiting the function "
         << "testCopyConst ***" << endl;                 //Line 26
}
