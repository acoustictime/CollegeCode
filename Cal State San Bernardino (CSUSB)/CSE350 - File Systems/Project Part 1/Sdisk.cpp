#include "Sdisk.h"
#include <fstream>
#include <string>

using namespace std;

Sdisk::Sdisk(string diskname) {

    	this->diskname = diskname;

	string temp = diskname + ".spc";

	ifstream infile;
	infile.open(temp.c_str());
	
	infile >> numberofblocks >> blocksize;
	
	infile.close();
}


Sdisk::Sdisk(string diskname, int numberofblocks, int blocksize) {

	this->diskname = diskname;
	this->numberofblocks = numberofblocks;
	this->blocksize = blocksize;

	string temp = diskname + ".spc";

	ofstream outfile;
	outfile.open(temp.c_str());
	outfile << numberofblocks << " " << blocksize;
	outfile.close();

	temp = diskname + ".dat";

	outfile.open(temp.c_str());

	for (int i = 0;i < numberofblocks * blocksize;i++)
		outfile.put('#');

	outfile.close();
}



Sdisk::~Sdisk() {


}


int Sdisk::getblock(int blocknumber, string & buffer) {

	// check if block number is valid
	// check if buffer is big enough

	string temp = diskname + ".dat";
	
	ifstream infile;
	infile.open(temp.c_str());

	//check if file correctly opened

	infile.seekg(blocknumber * this->blocksize);
	
	char x;
	string temp2;

	for (int i = 0;i < blocksize;i++) {
		
		infile.get(x);
		
		temp2 += x;		
	}


	infile.close();	

	buffer = temp2;		

	return 1;
}

int Sdisk::putblock(int blocknumber, string & buffer) {

	// check if block number is valid
	// check if buffer is big enough

	string temp = diskname + ".dat";
	
	fstream outfile;
	outfile.open(temp.c_str(),ios::in | ios::out);

	//check if file correctly opened

	outfile.seekp(blocknumber * this->blocksize);

	
	for (int i = 0;i < blocksize;i++)
		outfile.put(buffer[i]); 
				
	outfile.close();		


	return 1;
}
