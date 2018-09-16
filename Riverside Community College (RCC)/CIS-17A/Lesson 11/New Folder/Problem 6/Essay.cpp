// Essay.cpp: implementation of the Essay class.
//
//////////////////////////////////////////////////////////////////////

#include "Essay.h"
#include <iostream>

using namespace std;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Essay::Essay(double g, double s, double l, double c)
{
	Grammer.setScore(g);
	Spelling.setScore(s);
	Length.setScore(l);
	Content.setScore(c);

	Essay::checkvalid();
	Essay::calcgrade();
}

double Essay::getgrammer()
{ return Grammer.getScore();}

double Essay::getspelling()
{ return Spelling.getScore();}

double Essay::getlength()
{ return Length.getScore();}

double Essay::getcontent()
{ return Content.getScore();}

double Essay::gettotalscore()
{ return score;}

void Essay::calcgrade()
{
	score = Grammer.getScore() + Spelling.getScore() + Length.getScore() + Content.getScore();
}

char Essay::getLetterGrade()
{
   char letterGrade; // To hold the letter grade
   
   if (score > 89)
      letterGrade = 'A';
   else if (score > 79)
      letterGrade = 'B';
   else if (score > 69)
      letterGrade = 'C';
   else if (score > 59)
      letterGrade = 'D';
   else
      letterGrade = 'F';
   
return letterGrade;
}

void Essay::checkvalid()
{
	double temp;

	while (Grammer.getScore() > 30 || Grammer.getScore() < 0)
	{
		cout << "\nPlease enter a value between 0 and 30 for Grammer: ";
		cin >> temp;
		Grammer.setScore(temp);
	}

	while (Spelling.getScore() > 30 || Spelling.getScore() < 0)
	{
		cout << "\nPlease enter a value between 0 and 20 for Spelling: ";
		cin >> temp;
		Spelling.setScore(temp);
	}

	while (Length.getScore() > 20 || Length.getScore() < 0)
	{
		cout << "\nPlease enter a value between 0 and 20 for the Length: ";
		cin >> temp;
		Length.setScore(temp);
	}

	while (Content.getScore() > 20 || Content.getScore() < 0)
	{
		cout << "\nPlease enter a value between 0 and 30 for the Content: ";
		cin >> temp;
		Content.setScore(temp);
	}
}


