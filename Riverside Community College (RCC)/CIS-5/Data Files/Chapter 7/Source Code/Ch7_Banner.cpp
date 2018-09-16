

#include <iostream>

using namespace std;

void printStars();

int main()
{
	printStars();										//Line 1
	cout << "********** Annual  ***********" << endl;	//Line 2
	printStars();										//Line 3
	cout << "******* Spring Sale **********" << endl;	//Line 4
	printStars();										//Line 5

	return 0;
}

void printStars()
{
     cout << "******************************" << endl;
     cout << "******************************" << endl;
}
