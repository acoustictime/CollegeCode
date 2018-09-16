
#include <iostream>
#include "ptrDataClass.h"

using namespace std;

void pointerDataClass::print() const
{
      cout << "x = " << x << endl;

      cout << "p = ";

      for (int i = 0; i < lenP; i++)
           cout << p[i] << " ";
      cout << endl;
}

void pointerDataClass::setData()
{
      cout << "Enter an integer for x: ";
      cin >> x;
      cout << endl;

      cout << "Enter " << lenP << " numbers: ";

      for (int i = 0; i < lenP; i++)
           cin >> p[i];
  
      cout << endl;
}

void pointerDataClass::destroyP()
{
      lenP = 0;
      delete [] p;
      p = NULL;
}

pointerDataClass::pointerDataClass(int sizeP)
{
      x = 0;

      if (sizeP <= 0)
      {
          cout << "The array size must be positive." << endl;
          cout << "Creating an array of size 10." << endl;

          lenP = 10;
      }
      else
          lenP = sizeP;

      p = new int[lenP];
}

pointerDataClass::~pointerDataClass()
{
      delete [] p;
}

         //copy constructor
pointerDataClass::pointerDataClass 
                  (const pointerDataClass& otherObject)
{
      x = otherObject.x;

      lenP = otherObject.lenP;
      p = new int[lenP];

      for (int i = 0; i < lenP; i++)
           p[i] = otherObject.p[i];

}
