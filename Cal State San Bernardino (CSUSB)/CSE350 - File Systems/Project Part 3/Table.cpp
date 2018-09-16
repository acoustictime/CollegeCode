#include "Table.h"
#include "Indexrec.h"
#include "Filesys.h"
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

Table::Table(string filename, string flatfile, string indexfile) : Filesys(filename) {
	
	// This constructor creates the table object. It creates the new (empty) 
	// files flatfile and indexfile in the file system filesystem.
    
    this->flatfile = flatfile;
    this->indexfile = indexfile;
    
    // create flatfile on filesys
    
    int error = newfile(flatfile);
    
    
    // create indexfile on filesys
    
    error = newfile(indexfile);
    
    
    
	
}

int Table::Build_Table(string input_file) {
	
	// This module will read records from the input file (the raw data file 
	// described above), add the records to the flatfile and create index records 
	// consisting of the date and block number, and then add the index records 
	// to the index file. (Note that index records will have 10 bytes .. 5 bytes 
	// for the date and 5 bytes for the block number.)

	//create the flat file
	//create index vector and index file
    

	vector<Indexrec> indvec;

	ifstream myfile;
	vector<string> blocks;
    
    
    input_file += ".txt";

	myfile.open(input_file.c_str());

	string r1, r2, d1, d2, buffer;

    
    getline(myfile,r1);
    getline(myfile,r2);

	while(myfile.good()) {

        
		d1 = r1.substr(0,5);
		d2 = r2.substr(0,5);

		buffer = r1 + r2;

		blocks = block(buffer, getblocksize());

		int blockid = addblock(flatfile,blocks[0]);

		indvec.push_back(Indexrec(d1,blockid));
		indvec.push_back(Indexrec(d2,blockid));
        
        getline(myfile,r1);
        getline(myfile,r2);
        
	}
    
    // fix problem with last 2 records not loading
    
    d1 = r1.substr(0,5);
    d2 = r2.substr(0,5);
    
    buffer = r1 + r2;
    
    blocks = block(buffer, getblocksize());
    
    int blockid = addblock(flatfile,blocks[0]);
    
    indvec.push_back(Indexrec(d1,blockid));
    indvec.push_back(Indexrec(d2,blockid));

    
    
	//flat file is on sdisk and index record vector is created

	//to write index vector to the disk

	ostringstream ostream;

	ostream << indvec.size() << " ";

	for (int i = 0; i < indvec.size(); i++) 
        ostream << indvec[i].getkey() << " " << indvec[i].getblock() << " ";


	buffer = ostream.str();

	blocks = block(buffer,getblocksize());

	for (int i = 0; i < blocks.size(); i++) 
        int error = addblock(indexfile,blocks[i]);

}


int Table::Search(string value) {
	
	// This module accepts a key value, and searches the index file with a 
	// call to IndexSearch for the record where the date matches the specified 
	// value. IndexSearch returns the blocknumber of the block in the flat 
	// file where the target record is located. This block should then be 
	// read and the record displayed
    
    
    int block = IndexSearch(value);
    
    if (block == -1) {
        cout << "\nThe record could not be located\n";
        return -1;      // search bad  
    }
    
    string buffer;
    
    int error = getblock(flatfile,block,buffer);
   

    
    // determine break apart point based on number of *
    
    int split = 0;
    int count = 0;
    
    
    for (;count < 6; split++) {
        
        if (buffer[split] == '*')
            count++;
    }
    
  
    string temp = buffer.substr(0,value.length());
    
    if (temp == value) 
        temp = buffer.substr(0,split);
    else 
        temp = buffer.substr(split,buffer.length() - split);
    
    
    cout << "\nStart Date  : " << temp.substr(0,5);
    cout << "\nEnd Date    : " << temp.substr(6,5);
    cout << "\nType        : " << temp.substr(12,8);
    cout << "\nPlace       : " << temp.substr(21,15);
    cout << "\nReference   : " << temp.substr(37,7);
    cout << "\nDescription : " << temp.substr(45,temp.length() - 45 - 1) << endl;

    return 0; // search good
	
	
	
}

int Table::IndexSearch(string value) {
	
	// This module accepts a key value, and searches the index file indexfile 
	// for the record where the date matches the specified value. IndexSearch 
	// then returns the block number key of the index record where the match occurs.

	//search index file for the block with value

	//Let get index file

	string buffer;
	string buffer2;

	int block = getfirstblock(indexfile);

	while (block != 0) {
		int error = getblock(indexfile,block,buffer2);

        buffer += buffer2;

        block = nextblock(indexfile,block);

	}

	istringstream istream;

	istream.str(buffer);

	vector<Indexrec> irec;

	int size;
	string keyid;
	int blockid;

	istream >> size;

	for (int i = 0; i < size; i++) {

		istream >> keyid;
		istream >> blockid;

		if(keyid == value)
			return blockid;

	}
    
    return -1;
}