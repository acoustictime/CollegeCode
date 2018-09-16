/* Test an example of a State pattern  -- using Singleton states */

#include <iostream>
using namespace std;

#include "State.table.cpp"

int main()
{
	Lamp lamp;

	for(int i = 1; i <=4; i++)
	{
		lamp.pullChain();
	}

}
