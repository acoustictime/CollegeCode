// Stack_test.cpp

#include <iostream>
#include <cassert>
#include "Queue.h"
#include "../lab3/String.h"
#include "../lab5/List.h"

using namespace std;

int main()
{
   Queue<int> s1;
   assert(s1.size() == 0);
   assert(s1.empty());

   s1.push(16);
   assert(s1.size() == 1);
   assert(s1.top() == 16);

   s1.pop();
   assert(s1.size() == 0);

   s1.push(11);
   assert(s1.size() == 1);
   assert(s1.top() == 11);

   s1.push(22);
   assert(s1.size() == 2);
   assert(s1.top() == 11);

   Queue<String, List> s2;
   s2.push("abc");
   s2.push("de");
   s2.pop();
   assert(s2.top() == "de");

   cout << "SUCCESS\n";
}
