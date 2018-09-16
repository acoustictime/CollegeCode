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

class LampState;

class Lamp
{
	public: Lamp();
	private: LampState * state;
	public: void pullChain() ;
};


class LampState
{
	protected: Light light;
	protected: Heat heat;

	public: virtual LampState * pull( ) =0;
			// "pull" returns the next state
	public: static LampState * getInitialState() ;

};

void Lamp::pullChain() { state = (state -> pull()); }

class BothOff : public LampState
{
	private: static BothOff* instance;
		BothOff(){}
		~BothOff(){}
	public: static BothOff * getInstance() { return instance; }

		LampState * pull();
};

BothOff * BothOff::instance = new BothOff();
LampState * LampState::getInitialState() { return (LampState*)BothOff::getInstance(); }

class LightOn : public LampState
{
	private: static LightOn* instance;
		LightOn(){}
		~LightOn(){}
	public: static LightOn * getInstance() { return instance; }

		LampState * pull();


};
LightOn * LightOn::instance = new LightOn();
class BothOn : public LampState
{
	private: static BothOn* instance;
		BothOn(){}
		~BothOn(){}
	public: static BothOn * getInstance() { return instance; }

		LampState * pull();


};
BothOn * BothOn::instance = new BothOn();
class HeatOn : public LampState
{
	private: static HeatOn* instance;
		HeatOn(){}
		~HeatOn(){}
	public: static HeatOn * getInstance() { return instance; }

		LampState * pull();


};
HeatOn * HeatOn::instance = new HeatOn();

Lamp::Lamp() { state = LampState::getInitialState(); }

LampState * BothOff::pull()
{
	light.on();
	return (LampState*)(LightOn::getInstance());
}
LampState * LightOn::pull()
{
	heat.on();
	return (LampState*)(BothOn::getInstance());
}
LampState * BothOn::pull()
{
	light.off();
	return (LampState*)(HeatOn::getInstance());
}
LampState * HeatOn::pull()
{
	heat.off();
	return (LampState*)(BothOff::getInstance());
}
#endif
