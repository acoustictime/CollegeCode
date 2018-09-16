/********************************************************************************
 James Small
 Date Start: 3-15-12 Date End: 3-16-12
 Filename: Pair.h
 Description: This is the template class for my own Pair Class.  This entire
 class was given to us in the lab.  It basically stores the two types for the pair
 and overloads some comparison operators inline.
 *******************************************************************************/

#ifndef PAIR_H
#define PAIR_H

// Pair.h

using namespace std;

template < class T1, class T2 >
class Pair
{
public:
    Pair(): first(), second() {}
    Pair(const T1 & first, const T2 & second): first(first), second(second) { }
    
    bool operator==(const Pair & rhs) const { return first == rhs.first; }
    bool operator<=(const Pair & rhs) const { return first <= rhs.first; }
    bool operator<(const Pair & rhs) const { return first < rhs.first; }
    bool operator>(const Pair & rhs) const { return first > rhs.first; }
    
    T1 first;
    T2 second;
};

#endif