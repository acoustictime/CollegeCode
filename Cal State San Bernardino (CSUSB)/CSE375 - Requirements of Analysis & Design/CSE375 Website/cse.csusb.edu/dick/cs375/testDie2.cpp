/* Unit test of a Die class */

#include <iostream>
#include <cassert>
using namespace std;

#include "Die2.cpp"

int main()
{
	Die * die= new Die2;

	const int SAMPLE =10;
	for(int i=0; i<SAMPLE; i++)
	{
		die -> roll();
		int fv = die -> getFaceValue();
		cout << fv << endl;
	}
	

}
