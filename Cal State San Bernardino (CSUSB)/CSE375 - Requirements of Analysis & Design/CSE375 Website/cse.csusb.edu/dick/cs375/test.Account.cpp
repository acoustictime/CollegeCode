// test the Account class

#include <iostream>
#include <string>
#include <cassert>
using namespace std;

#include "Account.cpp"

int main()
{

   Account acct(1234, 1111, 1000, 2000);

   assert (acct.getAvailableBalance() == 1000);
   assert (acct.getTotalBalance() == 2000);
   assert (acct.validatePIN(1111) );
   assert (! acct.validatePIN(111) );
   acct.debit(500);
   assert (acct.getAvailableBalance() == 500);
   assert (acct.getTotalBalance() == 1500);
   acct.credit(1000);
   assert (acct.getAvailableBalance() == 500);
   assert (acct.getTotalBalance() == 2500);


   cout << "\n\n*******************\n* All tests pass! *\n*******************\n";
   return 0;
}
