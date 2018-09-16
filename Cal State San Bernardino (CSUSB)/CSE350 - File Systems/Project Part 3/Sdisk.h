#ifndef _Sdisk_h
#define _Sdisk_h

#include <fstream>
#include <string>

using namespace std;

class Sdisk
{
public:
	Sdisk(string diskname);
	Sdisk(string diskname, int numberofblocks, int blocksize);

	int getblock(int blocknumber, string & buffer);
	int putblock(int blocknumber, string & buffer);
	string getdiskname() { return this->diskname; }
	int getnumberofblocks() { return this->numberofblocks; }
	int getblocksize() { return this-> blocksize; }

private:
	string diskname;
	int numberofblocks;
	int blocksize;
};

#endif
