// States without using the GoF STate Pattern -- using table driven code
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
	private: struct Transition{LampState next; char click; char onoff;};

	private: static Transition trans[4]; // table of next states

	public: Lamp(){ state=BothOff; }
	public: void pullChain() ;
};
Lamp::Transition Lamp::trans[]=
{      //next     click onoff    old state
	{LightOn, 'l',  '+'}, // BothOff
	{BothOn , 'h',  '+'}, // LightOn
	{HeatOn , 'l',  '-'}, // BothOn
	{BothOff, 'h',  '-'}  // HeatOn
};


void Lamp::pullChain() 
{ 
	
	if(Lamp::trans[state].click=='l')
		if(Lamp::trans[state].onoff=='+')
			light.on();
		else
			light.off();
	else// click=='h'
		if(Lamp::trans[state].onoff=='+')
			heat.on();
		else
			heat.off();
	state=Lamp::trans[state].next;


}

#endif
