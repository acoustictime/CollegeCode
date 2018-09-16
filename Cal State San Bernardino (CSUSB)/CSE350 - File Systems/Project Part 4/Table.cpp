#include "Table.h"
#include "Indexrec.h"
#include "Filesys.h"
#include "Btnode.h"
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstdlib>

using namespace std;

Table::Table(string filename, string flatfile, string indexfile) : Filesys(filename) {
    // This constructor creates the table object. It creates the new (empty) 
    // files flatfile and indexfile in the file system filesystem.
    
    this->flatfile = flatfile;
    this->indexfile = indexfile;
    this->indexfile2 = "inde2";
    
    // create flatfile on filesys
    
    int error = newfile(flatfile);
    
    // create indexfile on filesys
    
    error = newfile(indexfile);
    
    max = 4;
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
 
    // Project Part 4 Additions
    
    build_root(indvec[1],indvec[0]);
    
    for (int i = 2; i < indvec.size(); i++) {
        addindexrecordb(indvec[i]);
    }


}

int Table::Search(string value) {
    // This module accepts a key value, and searches the index file with a 
    // call to IndexSearch for the record where the date matches the specified 
    // value. IndexSearch returns the blocknumber of the block in the flat 
    // file where the target record is located. This block should then be 
    // read and the record displayed
    
    int block = index_search(root,value);
    
    if (block == -1) {
        cout << "\nThe record could not be located\n";
        return -1;      // search bad  
    }
    
    string buffer;
    
    int error = getblock(flatfile,block,buffer);
   
    // cout << endl << buffer << endl;
    
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

void Table::build_root(Indexrec r1, Indexrec r2) {
    // note:  r1.getkey()  < r2.getkey()

    int temp = newfile(indexfile2);

    vector<string> leftk;
    vector<int> leftl;

    leftk.push_back("notused");
    leftl.push_back(0);
    leftk.push_back(r1.getkey());
    leftl.push_back(r1.getblock());

    vector<string> rightk;
    vector<int> rightl;

    rightk.push_back("notused");
    rightl.push_back(0);
    rightk.push_back(r2.getkey());
    rightl.push_back(r2.getblock());
    
    Btnode left(leftk,leftl);        // create nodes for left and right sides
    Btnode right(rightk,rightl);
    
    // put on disk

    int leftblock = addblock(indexfile2, left.getnbuffer());
    int rightblock = addblock(indexfile2, right.getnbuffer());

    vector<string> rootk;  //keys
    vector<int> rootb;  //blocks

    rootk.push_back("notused");
    rootk.push_back(r1.getkey());
    rootb.push_back(leftblock);
    rootb.push_back(rightblock);

    Btnode rootnode(rootk,rootb);

    root = addblock(indexfile2,rootnode.getnbuffer()); // add int root to table class
}

int Table::index_search(int node, string key) {  // node = block number that contains root

    string buffer;
    int error = getblock(indexfile2,node,buffer);
    
    Btnode node2(buffer);
    vector<string> keys = node2.getkeys();
    vector<int> links = node2.getlinks();

    if (links[0] == 0) {          //exit condition
        //external node case
    
	  for (int i = 1; i < keys.size(); i++) {
	      if (keys[i] == key)
		    return links[i];
	  }
		return -1;
    }
    else {   
        // internal node case
        
	  int i = 1;

	  while (i < keys.size() && atoi(key.c_str()) > atoi(keys[i].c_str()))
	      i++;
                
	  return index_search(links[i - 1], key);
    }    
}

void Table::addindexrecordb(Indexrec r) {  
    Indexrec s = addindexrecordb(root,r);
    
    if (s.getblock() != 0) 
        buildnewroot(s);
}

Indexrec Table::addindexrecordb(int node, Indexrec r) {
    // adding Indexrec r to b+tree

    string buffer;
    int error = getblock(indexfile2,node,buffer);
    
    Btnode b(buffer);

    vector<string> keys = b.getkeys();
    vector<int> links = b.getlinks();
    
    if (links[0] == 0) {
        //external node
	  return insertextnode(node,r);
    }
    else {
        // internal node

        string key = r.getkey();
                
	  int i = 1;

	  while (i < keys.size() && atoi(key.c_str()) > atoi(keys[i].c_str())) {

            i++;  
        }

	  // visit links[i - 1];

	  int child = links[i - 1];
        
        Indexrec r2 = addindexrecordb(child, r);
        
        if (r2.getblock() == 0) {
            return r2;
        }
        else {
            return insertintnode(node, r2);     
        }
    }        
}

void Table::buildnewroot(Indexrec r) {
    
    vector<string> keys;
    vector<int> links;

    links.push_back(root);
    links.push_back(r.getblock()); //accessor to get block

    keys.push_back("notused"); // no spaces in "notused"
    keys.push_back(r.getkey());

    Btnode b(keys,links);

    string buffer = b.getnbuffer();

    root = addblock(indexfile2,buffer);
}

Indexrec Table::insertextnode(int node, Indexrec r) {       
    //inserts r into external node

    string buffer;
    
    int error = getblock(indexfile2,node,buffer);
    
    Btnode b(buffer);

    vector<string> keys = b.getkeys();
    vector<int> links = b.getlinks();

    keys.push_back(r.getkey());
    links.push_back(r.getblock());

    int i = keys.size() - 1;

    while (i > 1 && atoi(keys[i].c_str()) < atoi(keys[i - 1].c_str())) {

        string stemp = keys[i];
        keys[i] = keys[i - 1];
        keys[i - 1] = stemp;
        
        int itemp = links[i];
        links[i] = links[i - 1];
        links[i - 1] = itemp;
        
        i--;
    }
    
    if (keys.size() <= max) {  // max is 4 with global variable
        
        Btnode newnode(keys,links);
        
	  buffer = newnode.getnbuffer();
        
	  error = putblock(indexfile2,node,buffer);

	  // no split
	  return Indexrec("",0);
    }
    else {
        //record has split

	  vector<string> lkeys;
	  vector<int> llinks;

	  vector<string> rkeys;
	  vector<int> rlinks;

	  llinks.push_back(0);
	  rlinks.push_back(0);
                
	  rkeys.push_back("notused");
	  lkeys.push_back("notused");
                
	  for (int i = 1; i < keys.size() / 2; i++) {
	      lkeys.push_back(keys[i]);
		llinks.push_back(links[i]);
	  }

	  for (int i = keys.size() / 2; i < keys.size(); i++) {
		rkeys.push_back(keys[i]);
		rlinks.push_back(links[i]);
	  }        
                
	  Btnode left(lkeys,llinks);
	  Btnode right(rkeys,rlinks);

	  string leftbuffer = left.getnbuffer();
	  string rightbuffer = right.getnbuffer();

	  error = putblock(indexfile2,node,leftbuffer);
      
	  error = addblock(indexfile2,rightbuffer);
      
	  return Indexrec(lkeys[lkeys.size() - 1], error);
    }
}

Indexrec Table::insertintnode(int node, Indexrec r) {

    //inserts r into internal node
    
    string buffer;

    int error = getblock(indexfile2,node,buffer);

    Btnode b(buffer);

    vector<string> keys = b.getkeys();
    vector<int> links = b.getlinks();

    keys.push_back(r.getkey());
    links.push_back(r.getblock());
    
    int i = keys.size() - 1;

    while (i > 1 && atoi(keys[i].c_str()) < atoi(keys[i - 1].c_str())) {
        string stemp = keys[i];
        keys[i] = keys[i - 1];
        keys[i - 1] = stemp;
        
        int itemp = links[i];
        links[i] = links[i - 1];
        links[i - 1] = itemp;
        
	  i--;
    }
    
    if (keys.size() <= max) {  // max is 4 with global variable
        // no split
        
	  Btnode newnode(keys,links);
        
        buffer = newnode.getnbuffer();
        
        error = putblock(indexfile2,node,buffer);
        
	  return Indexrec("",0);
    }
    else {
        //record has split

	  vector<string> lkeys;
	  vector<int> llinks;

	  vector<string> rkeys;
	  vector<int> rlinks;

	  llinks.push_back(links[0]);
	  rlinks.push_back(links[keys.size() / 2 + 1]);
        
	  rkeys.push_back("notused");
	  lkeys.push_back("notused");
                
	  for (int i = 1; i <= keys.size() / 2; i++) {
	      lkeys.push_back(keys[i]);
		llinks.push_back(links[i]);
	  }

	  for (int i = keys.size() / 2 + 2; i < keys.size(); i++) {
		rkeys.push_back(keys[i]);
		rlinks.push_back(links[i]);
	  }        
                
	  Btnode left(lkeys,llinks);
	  Btnode right(rkeys,rlinks);

	  string leftbuffer = left.getnbuffer();
	  string rightbuffer = right.getnbuffer();

	  error = putblock(indexfile2,node,leftbuffer);

	  error = addblock(indexfile2,rightbuffer);

	  return Indexrec(keys[keys.size() / 2 + 1], error);
    }
}
