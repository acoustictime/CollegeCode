// File: rocket.cpp
// By: 
// Project: lab3

#include "ccc_win.h"

using namespace std;

// a simple rocket is represented by a Point which is the lower left
// corner of the rocket when displayed pointing up; The attributes
// also include a direction (string) having values "up", "down", "letf"
// and "right".

class Rocket
{
public:
  
  Rocket();  // Default constructor

  Rocket(Point loc);       // constructor where rocket always points up
  
  void display();  // accessor function, displays rocket

  void move(int dx, int dy);  // mutator function, moves rocket

  void direction(string newdirection);  // mutator function, changes direction

private:

  Point llc; // lower left corner, location of rocket when pointing up

  string direction2; // this can be up, down, right or left

  void displayup(); // function used by display to draw the rocket pointing up

  void displaydown(); // function used by display to draw the rocket pointing down

  void displayright(); // function used by display to draw the rocket pointing right

  void displayleft(); // function used by display to draw the rocket pointing left 


};

// default; the number is 0 and the location is at (0,0);

Rocket::Rocket()
{
  llc = Point(0,0);
  direction2="up";
}

// constructor of Rocket object with number num at Point loc;

Rocket::Rocket(Point loc)
{
  llc = loc;
  direction2 = "up";
}

// accessor function: displays a rocket with lower left corner at 
// llc; the function determines the direction and calls the appropriate
// private display function.

void Rocket::display()
{
 
//calls one of the private functions depending on direction

  if (direction2 == "up")
  {
    displayup();
  }

  if (direction2 == "down")
  {
    displaydown();
  }

  if (direction2 == "left")
  {
    displayleft();
  }

  if (direction2 == "right")
  {
    displayright();
  }


}

void Rocket::direction(string newdirection)
{
  direction2 = newdirection;
}

void Rocket::move(int dx, int dy)
{
  llc.move(dx,dy);
}

void Rocket::displayup()
{
  Point a1 = llc;
  Point a2((llc.get_x() + 10),(llc.get_y()));
  Point a3((llc.get_x() + 10),(llc.get_y()+ 30));
  Point a4((llc.get_x()),(llc.get_y()+ 30));
  Point a5((llc.get_x() + 5),(llc.get_y()+ 40));
  cwin << Line(a1,a2);
  cwin << Line(a2,a3);
  cwin << Line(a1,a4);
  cwin << Line(a3,a4);
  cwin << Line(a3,a5);
  cwin << Line(a4,a5);
}

void Rocket::displayleft()
{
  Point a1 = llc;
  Point a2((llc.get_x()),(llc.get_y() + 10));
  Point a3((llc.get_x() - 30),(llc.get_y() + 10));
  Point a4((llc.get_x() - 30),(llc.get_y()));
  Point a5((llc.get_x() - 40),(llc.get_y()+ 5));
  cwin << Line(a1,a2);
  cwin << Line(a2,a3);
  cwin << Line(a1,a4);
  cwin << Line(a3,a4);
  cwin << Line(a4,a5);
  cwin << Line(a3,a5);
}

void Rocket::displayright()
{
  Point a1 = llc;
  Point a2((llc.get_x()),(llc.get_y()- 10));
  Point a3((llc.get_x() + 30),(llc.get_y() - 10));
  Point a4((llc.get_x() + 30),(llc.get_y()));
  Point a5((llc.get_x() + 40),(llc.get_y()- 5));
  cwin << Line(a1,a2);
  cwin << Line(a2,a3);
  cwin << Line(a1,a4);
  cwin << Line(a3,a4);
  cwin << Line(a3,a5);
  cwin << Line(a4,a5);
  
}

void Rocket::displaydown()
{
  Point a1 = llc;
  Point a2((llc.get_x() - 10),(llc.get_y()));
  Point a3((llc.get_x()- 10),(llc.get_y() + 30));
  Point a4((llc.get_x()),(llc.get_y()+ 30));
  Point a5((llc.get_x() - 5),(llc.get_y()- 10));
  cwin << Line(a1,a2);
  cwin << Line(a2,a3);
  cwin << Line(a1,a4);
  cwin << Line(a3,a4);
  cwin << Line(a2,a5);
  cwin << Line(a1,a5);
}

// main() function; 
// 

int ccc_win_main()
{
   cwin.coord(0,1000,1000,0);
   Rocket usa1(Point(250,10));
   Rocket usa2(Point(750,10));
   usa1.display();
   usa2.display();

  for (int i = 0; i <= 3000; i += 100)
    {
      if (i < 550) 
      { 
        usa1.direction("up");
        usa2.direction("up");
        usa1.move(0,50);
        usa2.move(0,50);
      }

      if (i>=500 && i < 1000)
      { 
        usa1.direction("left");
        usa2.direction("left");
        usa1.move(-50,0);
        usa2.move(-50,0);
      }

      if (i>=1000 && i < 1500)
      { 
        usa1.direction("up");
        usa2.direction("up");
        usa1.move(0,50);
        usa2.move(0,50);
      }

      if (i>=1500 && i < 2200)
      { 
        usa1.direction("right");
        usa2.direction("right");
        usa1.move(50,0);
        usa2.move(50,0);
      }

      if (i>2200)
      { 
        usa1.direction("down");
        usa2.direction("down");
        usa1.move(0,-50);
        usa2.move(0,-50);
      }
  
      

      usa1.display();
      usa2.display();
 
    }
      
  return 1;
}
