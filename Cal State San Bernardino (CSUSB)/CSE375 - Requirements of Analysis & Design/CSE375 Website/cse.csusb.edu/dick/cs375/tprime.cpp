/* Test Driven Development of a prime number function
*/
#include <iostream>
#include <cassert>
using namespace std;

bool prime(int n);

int main(int argc, char* argv[])
{// test prime number function
	assert( prime(2) );
	assert( prime(3) );
	assert( not prime(4) );
	assert( prime(5) );
	assert( not prime(9) );
	assert( not prime(42));
	cout << "Success!\n";
}//end main
