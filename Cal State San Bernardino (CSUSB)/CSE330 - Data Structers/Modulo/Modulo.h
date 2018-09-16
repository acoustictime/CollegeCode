#ifndef _Modulo_h
#define _Modulo_h

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



#endif
