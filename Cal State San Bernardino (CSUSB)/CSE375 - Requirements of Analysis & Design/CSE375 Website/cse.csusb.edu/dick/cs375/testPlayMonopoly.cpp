/* Test Driven Development of a MonopolyGame class
*/
#include <iostream>
#include <string>
#include <cassert>
using namespace std;

#include "Die.cpp"


class Square // Figs 17.5
{
private : string name;
public: 
   virtual string getName() {return name;}
   virtual void setName(string value) {name=value;}

public:
	Square(){}//default
	Square(int i){
	   switch(i)
	   { case 0: name ="GO"; break;
	     default: name= "TBD"; break;
	   }//TBD
	}

}; // end class Square

class Board //figure 17.4 and 17.5
{
public: static const int NSQUARES = 40;
public: exception NoSuchSquare;
private : Square square[NSQUARES];
public: 
   virtual Square getSquare(int i) {assert(0<=i and i<NSQUARES); return square[i];}
   virtual void setSquare(int i, Square value) {assert(0<=i and i<NSQUARES); square[i]=value;}
   virtual Square getSquare(string name) 
	{
	   int i;
	   for( i=0; i<NSQUARES; i++)
	     if(square[i].getName()==name)
		return square[i];
	     if( i>=40 )
		throw NoSuchSquare;
	}

public:
	Board(){
	for(int i=0; i<40; i++)
		square[i]=Square(i);
	}//default

}; // end class Board


class MonopolyGame
{
private : int nPlayers;
public: 
   virtual int getnPlayers() {return nPlayers;}
   virtual void setnPlayers(int value) {nPlayers=value;}

public:
	MonopolyGame(){nPlayers=0;}//default
	MonopolyGame(int n){nPlayers=n;}//default

	virtual void playGame()
	{
	   return ;
	}//playGame

};
int main(int argc, char* argv[])
{

	MonopolyGame * tester = new MonopolyGame ();
	assert(tester->getnPlayers() == 0);

	tester->setnPlayers(3);
	assert(tester->getnPlayers() == 3);
	tester->playGame();

	cout << "Success!\n";
}//end main
