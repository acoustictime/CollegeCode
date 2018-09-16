

class Indexrec {
public:
	Indexrec(string key, int block) { this->key = key; this->block = block; }
	string getkey() { return key;}
	int getblock() { return block; }

private:
	string key;
	int block;
};