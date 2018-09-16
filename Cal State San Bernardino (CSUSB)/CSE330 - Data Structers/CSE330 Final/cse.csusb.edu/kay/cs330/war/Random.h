#ifndef RANDOM_H
#define RANDOM_H

/*********************************************************************
adapted from:   timothy budd
programmer:     kay zemoudeh
date:           8/17/98
file:           Random.h

description:    this module is the interface definition of the class
                RandomInteger.

implementation: note extern declaration for randomizer.
**********************************************************************/

class RandomInteger {
    public:
        RandomInteger();
        unsigned int operator()(unsigned int max);
}; // RandomInteger

#endif
