/* Unit test of a Die class */

#include <iostream>
#include <cassert>
using namespace std;

#include "Die.cpp"

int main()
{
	Die die;

	const int SAMPLE =1000;
	for(int i=0; i<SAMPLE; i++)
	{
		die . roll();
		int fv = die . getFaceValue();
		cout << fv << endl;
	}
	

}
