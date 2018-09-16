#include "Filesys.h"
#include "Btnode.h"
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

Btnode::Btnode(string nbuffer) { // creates datastructure from block on disk
        
    this->nbuffer = nbuffer;

    istringstream instream;

    instream.str(nbuffer);

    int size = 0;

    instream >> size;

    values.push_back("unused");
    int lvalue;
    string svalue;

    instream >> lvalue;

    links.push_back(lvalue);

    for (int i = 1; i < size; i++) {
        instream >> svalue >> lvalue;
        values.push_back(svalue);
        links.push_back(lvalue);
    }
}

Btnode::Btnode(vector<string> v, vector<int> k) {  // creates blcok on disk from datastructure

    ostringstream outstream;

    outstream << v.size() << " ";

    outstream << k[0] << " ";

    for (int i = 1; i < v.size(); i++) 
        outstream << v[i] << " " << k[i] << " ";
                      
    string buffer = outstream.str();
    
    Filesys temp("disk");
    
    vector<string> b = temp.block(buffer,temp.getblocksize());
        
    values = v;
    links = k;
    nbuffer = b[0];
}



