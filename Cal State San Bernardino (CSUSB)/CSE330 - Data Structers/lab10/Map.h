/********************************************************************************
 James Small
 Date Start: 3-15-12 Date End: 3-16-12
 Filename: Map.h
 Description: This is the template class for my own Map Class.  The functions
 used were based on the Map_test.cpp file that was given to us.
 This map class is implemented using a Set of Pairs.  All functions are done inline
 This class also inherits from the Set class.
 *******************************************************************************/

#ifndef MAP_H
#define MAP_H

// Map.h

#include "Set.h"
#include "Pair.h"
#include <iostream>
#include "String.h"

using namespace std;

template < class key, class value >
class Map : public Set < Pair < key, value > >
{
public:
    typedef Set < Pair < key, value > > parent;
    typedef Set_iterator < Pair < key, value > > iterator;
    
    Map(): parent() {}
    
    iterator find(const key & k) {return parent::find(Pair<key,value>(k,value())); }
    value & operator[](const key & k) { return (*(insert(Pair<key,value>(k,value())))).second; }
    void erase(const key & k) {return parent::erase(Pair<key,value>(k,value())); }
};

#endif