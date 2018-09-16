// States without using the GoF STate Pattern
#ifndef STATECPP
#define STATECPP
/* A simple example of the State Pattern implemented in C++
   We have a lamp with a single pull chain that controls a
   heater and a light.  One pull turns on the light, the pull
   turns on the heat, then the light is turned of, and then
   the light turns off, and so on.

   There are four states:  BothOff, LightOn, BothOn, HeatOn.

   We code a Lamp class that has a LampState...  And each LampState has its
   own behavior.

   Here I show a couple of variations:
	The event returns the new state to the object that has the state.
		This breaks the Command-Query Separation principle.
	I use eager creation of states because we know we will need all four of them.
*/
#include <iostream>  //for debugging
#include <cstdlib>
using namespace std;

class OnOff{
  public: void on();
  public: void off();
};
class Light:public OnOff
{
  public: void on() {cerr << "light on\n";}
  public: void off(){cerr << "light off\n";}
};
class Heat:public OnOff
{
  public: void on() {cerr << "             heat on\n";}
  public: void off(){cerr << "             heat off\n";}
};


class Lamp
{
	Light light;
	Heat  heat;

	private: enum LampState{BothOff, LightOn, BothOn, HeatOn}state;
	public: Lamp(){state=BothOff;}
	public: void pullChain() ;
};


void Lamp::pullChain() 
{ 
	switch(state)
	{
	  case BothOff: light.on(); state=LightOn; 
	  break;
	  case LightOn: heat.on(); state=BothOn; 
	  break;
	  case BothOn: light.off(); state=HeatOn; 
	  break;
	  case HeatOn: heat.off(); state=BothOff; 
	  break;
	}
}

#endif
