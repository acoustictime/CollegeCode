// **********************************************************************
// * James Small														*
// * Cis-17a															*
// * 9-11-06															*
// *																	*
// * This program takes as it's input, 20 numbers, and sorts them using	*
// * the bubble sort and selection sort methods.  It then displays		*
// * how many swaps it took each type of sort to accomplish it's goal.	*
// **********************************************************************

#include <iostream>
#include "Essay.h"

using namespace std;

int main()
{
	int grammer, spelling, length, content;

	cout << "Enter your score on grammer: ";
	cin >> grammer;
	cout << "Enter your score on spelling: ";
	cin >> spelling;
	cout << "Enter your score on the length: ";
	cin >> length;
	cout << "Enter your score on the content: ";
	cin >> content;

	Essay Grade(grammer, spelling, length, content);

	system("cls");

	cout << "\nGrammer		" << Grade.getgrammer();
	cout << "\nSpelling        " << Grade.getspelling();
	cout << "\nLength		" << Grade.getlength();
	cout << "\nContent		" << Grade.getcontent();
	cout << "\n\nTotal		" << Grade.gettotalscore();
	cout << "\n\nFinal Grade     " << Grade.getLetterGrade() << endl << endl;

return 0;
}