/* Declares a class in Page 10 of Larman */
#ifndef DIECPP
#define DIECPP
#include <cstdlib>
#include <ctime>
using namespace std;

class Die
{ protected:  //future proofing to demo polymorphism
	int faceValue;
  public:
	virtual void roll()
	{
		faceValue = 1+(6.0*rand())/RAND_MAX;
	}
	virtual int getFaceValue()
	{
		return faceValue;
	}
	Die () { roll(); };
private:
	static const int seeded;
	static int seed(){ srand(time(NULL)); return 0; }
};
const int Die::seeded=seed();
#endif
