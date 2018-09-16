// How to code a class that implements the GoF Singleton Pattern
// (1) a class that never has more than one instance
// (2) a class that gives access to the instance

// in this case the instance is a counter.  

#ifndef SINGLETONCPP
#define SINGLETONCPP
#include <cstdlib>

class Singleton 
{
    private: static Singleton * instance;

    private: Singleton() { reset(); } // hidden constructor stops others creating instances
		~Singleton(){} //similarly stop others from deleting the Singleton
   public:
      static Singleton * getInstance() // you want it? get it here
      {
	if(instance==NULL) instance = new Singleton();
        return instance;
      }

  private: int counter;
  public: void reset(){ counter=0; }
  public: void count(){ counter++;}
  public: int value(){ return counter;}
	
};

Singleton * Singleton::instance = NULL;

#endif
