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
    int stars, lines;

    for (lines = 1; lines <= 2; lines++)			//Line 6
    {
        for (stars = 1; stars <= 30; stars++)		//Line 7
            cout << '*';							//Line 8
        cout << endl;								//Line 9
    }
}	

