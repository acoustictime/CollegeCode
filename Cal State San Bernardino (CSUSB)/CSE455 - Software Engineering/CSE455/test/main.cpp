#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
	string test;	
	cout << "enter file name: ";
	cin >> test;

	ifstream infile;
  
    infile.open(test.c_str());
  
  
    infile.close(); 

	if (infile)
		cout << "file exists";





return 1;
}
