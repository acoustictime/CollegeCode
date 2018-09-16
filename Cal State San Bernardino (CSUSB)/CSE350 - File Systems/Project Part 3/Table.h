#include "Filesys.h"
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
	int IndexSearch(string value);
};