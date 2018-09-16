/**************************************************************
 * K Zemoudeh
 * 3/22/2011
 * hash1.cpp
 *
 * This program illustrates hash class.
 *
 * There are 101 buckets (a vector of 0 to 100 list<Item<T>>).
 * Each Item is a pair of key and value.
 * ************************************************************/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <vector>
#include <list>

using namespace std;

template <class T> class Hash_table; //forward decl

template <class T>
class Item {
private:
	Item(const string & k, const T & v): key(k), value(v) {}
	string key;
	T value;
friend class Hash_table<T>;
};

template < class T>
class Hash_table {
public:
	Hash_table(int n): size(n), bucket(vector<list<Item<T> > >(n)) {}
	bool lookup(const string & k, T & v);
	void insert(const string & k, const T & v); 
	void print();
private:
	vector<list<Item<T> > > bucket;
	int size;
	int hash_function(const string & s) { return (s[0]+s[1])%size; }
};

template < class T>
void Hash_table<T>::print()
{
	for (int i = 0 ; i < size; i++)
		if (!bucket[i].empty()) {
			cout << i << ": ";
			typename list<Item<T> >::iterator j;
			for (j = bucket[i].begin(); j != bucket[i].end(); j++)
				cout << "(" << j->key << "," << j->value << ") ";
			cout << endl;
		}
}

// returns status: true means found it, false otherwise
template < class T>
bool Hash_table<T>::lookup(const string & k, T & v)
{
	int index = hash_function(k);
	typename list<Item<T> >::iterator i;
	for (i = bucket[index].begin(); i != bucket[index].end(); i++)
		if (i -> key == k) {
			v = i -> value;
			return true;
		}
	return false;
}

template < class T>
void Hash_table<T>::insert(const string & k, const T & v)
{
	int index = hash_function(k);
	bucket[index].push_front(Item<T>(k, v));
}

main()
{
	string name;
	int age;
	ifstream in("hash.in");

	if (!in.is_open()) {
		cout << "couldn't open 'hash.in' for input.\n";
		exit(1);
	}

	// 101 buckets of list<(string, int)>
	Hash_table<int> h(101);

	while (in >> name >> age)
		h.insert(name, age);
	in.close();

	h.print();

	cout << "lookup what? ";
	while (cin >> name) {
		if (h.lookup(name, age))
			cout << "found: " << name << "," << age << endl;
		else cout << name << " doesn't exist\n";
		cout << "lookup what? ";
	}
}
