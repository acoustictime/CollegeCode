#ifndef _Indexrec_h
#define _Indexrec_h

class Indexrec {
public:
	Indexrec(string key, int block) { this->key = key; this->block = block; }
	string getkey() { return key;}
	int getblock() { return block; }

private:
	string key;
	int block;
};

#endif