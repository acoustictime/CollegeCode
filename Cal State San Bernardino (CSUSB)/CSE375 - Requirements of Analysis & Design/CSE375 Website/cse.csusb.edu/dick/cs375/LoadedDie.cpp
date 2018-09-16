/* Extends Die.cpp, a class in Page 10 of Larman */
#include <cstdlib>
#include <ctime>
using namespace std;
#include "Die.cpp"

class LoadedDie : public Die
{ 
  public:
	virtual void roll()
	{	cerr << "LoadedDie rolled\n";
		faceValue = 6;
	}
	LoadedDie () {roll(); };
};
