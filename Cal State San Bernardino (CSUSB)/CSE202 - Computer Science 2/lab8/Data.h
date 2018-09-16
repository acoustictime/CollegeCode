#ifndef DATA_H
#define DATA_H

#include <vector>

using namespace std;

class Data
{
public:
  Data();
  void addData(int x); // adds x to the data vector
  bool operator == (Data other) const; //compares two Data objects for equality
  static void changebenchmark(int newbenchmark); // changes the static benchmark variable
  vector<int> getData() const; // returns the data vector;
  int getbenchmark() const; // returns the static benchmark;
  void deleteData(int x);
 
private:
  vector<int> data;
  static int benchmark;
};


#endif


