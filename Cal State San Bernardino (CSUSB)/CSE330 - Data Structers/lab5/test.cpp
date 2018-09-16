#include <iostream>
#include "List.h"
#include <list>
using namespace std;

int main()
{
    List<int> l;

    l.push_back(44);  // list = 44
    l.push_back(33);  // list = 44, 33
    l.push_back(11);  // list = 44, 33, 11
    l.push_back(22);  // list = 44, 33, 11, 22
    
 
    List<int> m(l);
        
    List<int>::iterator itr(m.end());

   m.insert(itr,5);

List<int>::iterator itr2(m.begin());

    while (itr2 != m.end()) {
        cout << *itr2 << endl;
        itr2++;
   }
}
