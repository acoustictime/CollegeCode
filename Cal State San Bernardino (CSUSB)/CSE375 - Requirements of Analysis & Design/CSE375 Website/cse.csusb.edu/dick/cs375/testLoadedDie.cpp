/* Unit test of a Loaded Die class */

#include <iostream>
#include <cassert>
using namespace std;

#include "LoadedDie.cpp"

int main()
{

	Die *die=new LoadedDie;

	const int SAMPLE =10;
	for(int i=0; i<SAMPLE; i++)
	{
		die -> roll();
		int fv = die -> getFaceValue();
		cout << fv << " ";
	}

	die = new Die;
	for(int i=0; i<SAMPLE; i++)
	{
		die -> roll();
		int fv = die -> getFaceValue();
		cout << fv << " ";
	}
	

}
