#ifndef _Table_h
#define _Table_h

#include "Filesys.h"
#include "Indexrec.h"

#include <string>

using namespace std;

class Table : public Filesys{
public: 
	Table(string filename, string flatfile, string indexfile);
	int Build_Table(string input_file);
	int Search(string value);

private:
	string flatfile;
	string indexfile;
      string indexfile2;
      int root;
      int max;
	int IndexSearch(string value);
	int index_search(int node, string key);
	void build_root(Indexrec r1, Indexrec r2);
	void buildnewroot(Indexrec r);
	Indexrec insertextnode(int node, Indexrec r);
	Indexrec insertintnode(int node, Indexrec r);
	Indexrec addindexrecordb(int node, Indexrec r);
	void addindexrecordb(Indexrec r);    
};

#endif
