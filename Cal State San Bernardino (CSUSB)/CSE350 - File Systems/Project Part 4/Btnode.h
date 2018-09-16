#ifndef _Btnode_h
#define _Btnode_h

#include <string>
#include <vector>
#include "Filesys.h"

using namespace std;

class Btnode {

public:
    Btnode(string nbuffer);
    Btnode(vector<string> v, vector<int> k);

    vector<string> getkeys() { return values; }
    vector<int> getlinks() { return links; }
    string getnbuffer() { return nbuffer; }

private:
    vector<string> values;
    vector<int> links;
    string nbuffer;    
};

#endif

