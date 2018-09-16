#include <iostream>
#include <cassert>

bool prime(int n)
{
	if((n>2) and (n%2==0))
		return false;
	else
		return true;
}
int main(int argc, char* argv[])
{// test prime number function
	assert( prime(2) );
	assert( prime(3) );
	assert( not prime(4) );
	assert( prime(5) );
	assert( not prime(9) );
	assert( not prime(42));
}//end main
