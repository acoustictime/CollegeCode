//**************************************************** 
// Program: Warning Message
// This program reads a value and prints a warning 
// message when a value falls outside a given range.
//****************************************************

#include <iostream>

using namespace std;

const int low = 60;
const int high = 100;

int main ()
{
   int pressure;

   do
       cin >> pressure;
   while ((pressure > low) && (pressure < high));

   cout << "Help" << endl;

   return 0;
}
