#include <iostream>
#include <vector>

using namespace std;

int main()
{
  vector<char> vectorObject(4); // initilizes all to null char, this also implies size=capacity

  cout << "initial size: " << vectorObject.size() << endl;
  cout << "initial capacity: " << vectorObject.capacity();
  cout << endl;

  vectorObject.push_back(123);

  cout << "size after push_back(): " << vectorObject.size() << endl;
  cout << "capacity after push_back(): " << vectorObject.capacity();
  cout << endl;

  //for (vector<char>::iterator i = vectorObject.begin(); i != vectorObject.end(); i++)
	//cout << "'" << *i << "'" << endl;
  for (int i = 0; i < vectorObject.size(); i++) // this for-loop is exactly the same as the previous one
	cout << "'" << vectorObject[i] << "'" << endl;

  vectorObject.reserve(20); // reserve more space
  
  cout << "size after reserve: " << vectorObject.size() << endl;
  cout << "capacity after reserve: " << vectorObject.capacity();
  cout << endl;

  return 0;
}

