/*********************************************************************
adapted from:   timothy budd
programmer:     kay zemoudeh
date:           8/22/98
file:           Random.cpp

description:    this module is the implementation of the class RandomInteger.

implementation: only one operator method is defined for this class.
		instances of this class are meant to be primarily used as
		a "function object".
		object randomizer an instance of RandomInteger is declared here.
		since Random.h includes an extern reference to this object,
		any module that includes Random.h has access to randomizer.
**********************************************************************/

#include <stdlib.h>       // for rand()
#include <time.h>         // kay 8/20/98, for time()

#include "Random.h"

using namespace std;

RandomInteger::RandomInteger()
{
    srand(time(0));       // kay 8/20/98
} // constructor

unsigned int RandomInteger::operator()(unsigned int max)
{
    unsigned int rval = rand();
    return rval % max;
} // operator()

RandomInteger randomizer;
