/* IDS to Objects
   Some samples of the kind of code you might
   write so that a Controler handles incoming system events
   (from the SSD) and converts them (with Finder and Worker) to objects.
*/
#include <iostream>
#include <string>
#include <map>
#include <cassert>
using namespace std;

class Finder
{
  private: string myid;
	static map<string,Finder*> helpers;
  public:
	Finder(string id){myid=id; helpers[id]=this;} 
	static Finder * find(string id){return helpers[id];}
	void event(string t){ cout << "Finder " << myid << " got event(" << t << ")\n";}
	string getId(){return myid;}
};
map<string,Finder*> Finder::helpers;

class Worker{
  public:
	void mumble(Finder * h, string d){cout << "Worker " << " got mumble( Finder " << h->getId()<<", "<<d << ")\n";}
};

class Controler
{
  private: Finder * object;
  private: Worker * worker;
  public:
	Controler(){object=NULL; worker = new Worker();}
	void input1(string id){object=Finder::find(id);}
	void input2(string t){object->event(t);}
	void simpleInput(string id, string data){worker->mumble(Finder::find(id), data);}
};


/** Unit test */
int main()
{
	Controler c;
	Finder x("id");
	c.input1("id");
	c.input2("foo");

	c.simpleInput("id", "bar");

	return 0;
}
