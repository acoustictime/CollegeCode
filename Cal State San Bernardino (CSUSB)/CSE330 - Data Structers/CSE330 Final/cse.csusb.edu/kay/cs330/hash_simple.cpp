/**************************************************************
 * K Zemoudeh
 * 3/15/2011
 * hash.cpp
 *
 * This program illustrates how hash functions work.
 * It is intentionally kept simple to focus attention on the 
 * hash function.
 *
 * There are 101 buckets (a vector of 0 to 100 pointers) where
 * each pointer points to a linked list of Items. Each Item is
 * pair of value and pointer.
 * ************************************************************/

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

// linked list items
class Item {
public:
	Item(const string & v): value(v), next(0) { }
	string value;
	Item * next;
};

// a very simple hash function for 101 buckets
int hash_function(const string & s)
{
	// assuming s.size() >= 2
	return (s[0]+s[1])%101;
}

main()
{
	string name;
	int index;
	Item * p;

	// 101 buckets
	vector<Item *> bucket(101);

	// initialize all buckets
	for (index = 0; index < 101; index++)
		bucket[index] = 0;

	while (cin >> name) {
		p = new Item(name);
		index = hash_function(name);

		// push front
		if (bucket[index] != 0)
			p->next = bucket[index];
		bucket[index] = p;
	}

	// display only the buckets containing items
	for (index = 0; index < 101; index++)
		if (bucket[index] != 0) {
			cout << setw(3) << index << ": ";
			p = bucket[index];
			while (p != 0) {
				cout << p->value << " ";
				p = p->next;
			}
			cout << endl;
		}

	// free allocated memory
	Item * temp;
	for (index = 0; index < 101; index++) {
		p = bucket[index];
		while (p != 0) {
			temp = p;
			p = p->next;
			delete temp;
		}
	}
}
