#ifndef _Filesys_h
#define _Filesys_h

#include "Sdisk.h"
#include <string>
#include <vector>

using namespace std;

class Filesys : public Sdisk
{
public :
    Filesys(string diskname);
    ~Filesys();
    int fsclose();
    int fssynch();
    int newfile(string file);
    int rmfile(string file);
    int getfirstblock(string file);
    int addblock(string file, string buffer);
    int delblock(string file, int blocknumber);
    int getblock(string file, int blocknumber, string& buffer);
    int putblock(string file, int blocknumber, string buffer);
    int nextblock(string file, int blocknumber);
    
    vector<string> block(string s, int b);

    void outputtest();
    
private :
    bool belongstofile(string file, int blocknumber);
    
    int rootsize;           
    int fatsize;            
    vector<string> filename;  
    vector<int> firstblock; 
    vector<int> fat;   
};
#endif
