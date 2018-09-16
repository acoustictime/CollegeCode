// Exercise on polymorphism
// (1) Draw the classes in this program using a UML class diagram.
// (2) Predict what this program does: compile? crash? output?

#include <iostream>
#include <cassert>
using namespace std;

class A
{ public:
    virtual void v()=0;
};
class B : public A
{ public:
    void v(){ cout << "B::v\n"; }
};
class C : public A
{ public:
    void v(){ cout << "C::v\n"; }
};

int main()
{
   A* p;
   p=new B;
   p->v();
   p=new C;
   p->v();

   return 0;
}
