//
//  Modulo.cpp
//  
//
//  Created by James Small on 1/28/12.
//  Copyright 2012 None. All rights reserved.
//

#include <iostream>
#include <cassert>

using namespace std;

class Modulo {
private:
    int n;
    int value;
public:
    Modulo();
    Modulo(int m);
    Modulo(int m,int v);
    Modulo(const Modulo & m);
    Modulo operator=(int op);
    Modulo operator=(Modulo op);
    Modulo operator+(int op);
    Modulo operator+(Modulo op);
    int getValue();
    Modulo operator++();
    Modulo operator++(int);
};

Modulo::Modulo() {
    n = 2;
    value = 0;
}

Modulo::Modulo(int m) {
    n = m;
    value = 0;
    assert(n>0);
}

Modulo Modulo::operator=(int op) {
    value = op;
    value = value % n;
    return *this;
}

Modulo::Modulo(int m, int v) {
    n = m;
    value = v % m;
}

Modulo::Modulo(const Modulo & m) {
    n = m.n;
    value = m.value;
}

Modulo Modulo::operator=(Modulo op) {
    value = op.value;
    n = op.n;
    value %= n;
    return *this;
}

Modulo Modulo::operator++() {
    value++;
    value %= n;
    return *this;
}

Modulo Modulo::operator++(int) {
    Modulo temp = *this;
    ++(*this);
    return temp;
}

int Modulo::getValue() {
    return value;
}

Modulo Modulo::operator+(int op) {
    Modulo temp = *this;
    temp.value  += op;
    temp.value %= temp.n;
    return temp;
}

Modulo Modulo::operator+(Modulo op) {
    Modulo temp = *this;
    temp.value += op.value;
    temp.value %= temp.n;
    return temp;
}

ostream & operator<<(ostream & out, Modulo n) {
    out << n.getValue();
    return out;
}

int main()
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