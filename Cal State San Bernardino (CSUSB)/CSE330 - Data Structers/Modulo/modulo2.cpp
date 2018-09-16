/*****************************************************************************
 Kay Zemoudeh
 Jan 28, 2009
 mod.cpp
 
 A simple modulo n arithmetic class.
 An object of this class is a modulo n variable where n > 0 and value of 
 the variable is always >= 0 and < n.
 Only increment and add operations are implemented here.
 ******************************************************************************/

#include <iostream>
#include <cassert>

using namespace std;

class Modulo {
    int n;
    int value;
public:
    Modulo(); // default constructor creates a binary (mod 2) object and initializes it to 0
    Modulo(int m); // mod m object init to 0
    Modulo(int m, int op); // mod m object init to op
    
    Modulo operator=(Modulo);
    Modulo operator=(int);
    Modulo operator+(Modulo);
    Modulo operator+(int);
    int getValue();
    Modulo operator++(); // pre increment
    Modulo operator++(int); // post increment
}; // Modulo

Modulo::Modulo(): n(2), value(0) { }

Modulo::Modulo(int m): n(m), value(0) { assert(n > 0); }

Modulo::Modulo(int m, int op): n(m), value(op) { assert(n > 0 and value >= 0); value %= n; }

Modulo Modulo::operator=(Modulo op) 
{ 
    value = op.value; 
    value %= n; 
    return *this; 
}

Modulo Modulo::operator=(int op) 
{ 
    value = op;
    value %= n;
    return *this; 
}

Modulo Modulo::operator+(Modulo op) 
{
    Modulo temp = *this;
    temp.value += op.value;
    temp.value %= temp.n;
    return temp; 
}

Modulo Modulo::operator+(int op) 
{
    Modulo temp = *this;
    temp.value += op;
    temp.value %= temp.n;
    return temp; 
}

int Modulo::getValue() 
{
    return value; 
}

// pre increment
Modulo Modulo::operator++() 
{
    value++;
    value %= n;
    return *this; 
}

// post increment
Modulo Modulo::operator++(int) 
{
    Modulo temp = *this;
    ++(*this);
    return temp; 
}

ostream& operator<<(ostream& out, Modulo n) 
{
    out << n.getValue();
    return out; 
}

main()
{
    Modulo p(5, 2);
    cout << p << endl;
    p = p + 7;
    cout << p << endl;
    p = p + 15;
    cout << p << endl;
    ++p;
    cout << p << endl;
    
    Modulo q(4), r(3,1);
    q = 2;
    r = r + q;
    cout << r << endl;
    r = q++;
    cout << q << endl;
    cout << r << endl;
} // main