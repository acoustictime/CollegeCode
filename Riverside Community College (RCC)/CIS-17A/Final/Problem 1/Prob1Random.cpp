// Prob1Random.cpp: implementation of the Prob1Random class.
//
//////////////////////////////////////////////////////////////////////

#include "Prob1Random.h"
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Prob1Random::Prob1Random(const char a,const char *s)
{
	nset = a;
	
	set = const_cast<char*>(s);

	srand(time(NULL));
	freq = new int[a];
	numRand = 0;

	for (int i = 0; i < a; i++)
	{
		freq[i] = 0;
	}
}

Prob1Random::~Prob1Random()
{
	
}

//Returns a random number from the set


char Prob1Random::randFromSet()
{
	char a = 'b';
	int temp;
	numRand++;
	temp = 1 + (6 - 1) * rand() * (1.0 / RAND_MAX);
			

	if (temp == 1)
	{
		freq[0]++;
	}
	else if (temp == 2)
	{
		freq[1]++;
	}
	else if (temp == 3)
	{
		freq[2]++;
	}
	else if (temp == 4)
	{
		freq[3]++;
	}
	else if (temp == 5)
	{
		freq[4]++;
	}

return a;
}

int *Prob1Random::getFreq(void) const
{
	return freq;
}

char *Prob1Random::getSet(void) const
{
	return set;
}

int Prob1Random::getNumRand(void) const
{
	return numRand;
}
