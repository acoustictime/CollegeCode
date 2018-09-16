void Hanoi (int n, char a, char b, char c);

#include <iostream>

using namespace std;



int main()
{

    char a, b,c;
    int size = 3;
    
    Hanoi(size,'a','b','c');
 
    
    return 1;
}

void Hanoi (int n, char a, char b, char c)
{
    if (n==1)
    {
        cout << "move disk from tower " << a << " to " << b <<  " N = " << n << endl;
    }
    else
    {    
    
        Hanoi (n-1,a,c,b);
    
        cout << "move disk from tower " << a << " to " << b <<  " N = " << n << endl;
    
        Hanoi (n-1,c,b,a);
    }    
}