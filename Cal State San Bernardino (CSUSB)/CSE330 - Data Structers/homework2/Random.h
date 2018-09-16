/********************************************************************************
 James Small
 Date Start: 2-1-12  Date End: 2-1-12
 Filename: Random.h
 Description: This class header file was taken directly from the war program with
              no modification to it.   
 *******************************************************************************/

#ifndef _Random_h
#define _Random_h

#include <stdlib.h>
#include <algorithm>
#include <time.h>

class Random {
public:
    Random();
    unsigned int operator()(unsigned int max);
}; // RandomInteger



#endif
