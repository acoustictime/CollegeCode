/* Extends Die.cpp, a class in Page 10 of Larman */
#include <cstdlib>
#include <ctime>
using namespace std;
#include "Die.cpp"

class Die2 : public Die
{ 
  public:
	virtual void roll()
	{	cerr << "Die2 rolled\n";
		faceValue = 1+(6.0*rand())/RAND_MAX;
	}
	Die2 () {roll(); };
};
