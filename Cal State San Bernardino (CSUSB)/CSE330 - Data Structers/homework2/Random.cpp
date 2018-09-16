/********************************************************************************
 James Small
 Date Start: 2-1-12  Date End: 2-1-12
 Filename: Random.cpp
 Description: This class file was taken directly from the war2 program with
              no modification to it.   
 *******************************************************************************/

#include "Random.h"
#include <stdlib.h>

Random::Random() {
    srand(time(0));
}

unsigned int Random::operator()(unsigned int max) {
    unsigned int rval = rand();
    return rval % max;
}

Random randomizer; 
