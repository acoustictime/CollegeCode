// Prob1Random.h: interface for the Prob1Random class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PROB1RANDOM_H__34B2CAB4_57FA_4744_8859_D0596FF80E0D__INCLUDED_)
#define AFX_PROB1RANDOM_H__34B2CAB4_57FA_4744_8859_D0596FF80E0D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <cstdlib>
#include <iostream>

using namespace std;

class Prob1Random
{
	private:
		char *set;      //The set of numbers to draw random numbers from
		char  nset;     //The number of variables in the sequence
		int  *freq;     //Frequency of all the random numbers returned
		int   numRand;  //The total number of times the random number function is called
	public:
		Prob1Random(const char,const char *);     //Constructor
		~Prob1Random(void);                       //Destructor
		char randFromSet(void);                   //Returns a random number from the set
		int *getFreq(void) const;                 //Returns the frequency histogram
		char *getSet(void) const;                 //Returns the set used
		int getNumRand(void) const;               //Gets the number of times randFromSet has
		                                          //been called
};

#endif // !defined(AFX_PROB1RANDOM_H__34B2CAB4_57FA_4744_8859_D0596FF80E0D__INCLUDED_)
