/* Test for a simple Singleton -- a counter object that can be called from anywhere in a program
*/
#include <iostream>
using namespace std;

#include "singleton.cpp"


int main()
{
 // The normal way to access and use the singleton is like this
   cout<< Singleton::getInstance()->value() << endl;
   Singleton::getInstance()->count();
   cout<< Singleton::getInstance()->value() << endl;
   Singleton::getInstance()->reset();
   cout<< Singleton::getInstance()->value() << endl;

   cout << "----------------------\n";

//The following ilustrate that attempts to get more than one Singleton fail.

//ILLEGAL	Singleton stolen;

   Singleton * thesingleton = Singleton::getInstance();

   cout << thesingleton->value() << endl;
   thesingleton->count();
   cout << thesingleton->value() << endl;


   Singleton * secondSingleton=Singleton::getInstance();  // LIES

   cout << secondSingleton->value() << endl;
   secondSingleton->count();
   cout << secondSingleton->value() << endl;

   cout << thesingleton->value() << endl;
   thesingleton->count();
   cout << thesingleton->value() << endl;


   return 0;
}
