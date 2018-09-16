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
*/
#include <iostream>  //for debugging
#include <cstdlib>
using namespace std;

class OnOff{ //interface
  public: virtual void on()=0;
  public: virtual void off()=0;
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
	public: void setState(LampState* newState) { state=newState; }
};


class LampState
{
	protected: Light light;
	protected: Heat heat;

	public: virtual void pull( Lamp * context ) {}
			// an alternative is for the "pull" to return the next state

};

void Lamp::pullChain() {state -> pull(this); }

class BothOff : public LampState
{
	private: static BothOff* instance;
		BothOff(){}
		~BothOff(){}
	public: static BothOff * getInstance()
		{ 
			if(!instance) instance=new BothOff();
			return instance;
		}

		void pull(Lamp* context);
};
BothOff * BothOff::instance = NULL;
class LightOn : public LampState
{
	private: static LightOn* instance;
		LightOn(){}
		~LightOn(){}
	public: static LightOn * getInstance()
		{ 
			if(!instance) instance=new LightOn();
			return instance;
		}

		void pull(Lamp* context);


};
LightOn * LightOn::instance = NULL;
class BothOn : public LampState
{
	private: static BothOn* instance;
		BothOn(){}
		~BothOn(){}
	public: static BothOn * getInstance()
		{ 
			if(!instance) instance=new BothOn();
			return instance;
		}

		void pull(Lamp* context);


};
BothOn * BothOn::instance = NULL;
class HeatOn : public LampState
{
	private: static HeatOn* instance;
		HeatOn(){}
		~HeatOn(){}
	public: static HeatOn * getInstance()
		{ 
			if(!instance) instance=new HeatOn();
			return instance;
		}

		void pull(Lamp* context);


};
HeatOn * HeatOn::instance = NULL;

Lamp::Lamp() { state = BothOff::getInstance(); }

void BothOff::pull(Lamp* context)
{
	light.on();
	context->setState(LightOn::getInstance());
}
void LightOn::pull(Lamp* context)
{
	heat.on();
	context->setState(BothOn::getInstance());
}
void BothOn::pull(Lamp* context)
{
	light.off();
	context->setState(HeatOn::getInstance());
}
void HeatOn::pull(Lamp* context)
{
	heat.off();
	context->setState(BothOff::getInstance());
}
#endif
