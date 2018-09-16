/* Program: fall.cpp */

#include "ccc_win.h"

int ccc_win_main()
{
  cwin.coord(0,1000,1000,0);
  
  Point ballCenter(500,975);
  Circle ball(ballCenter,25);
  double downVelocity = 0;
  double ballYValue = 975;
  int timeSeconds = 0;
  int parachuteRelease = 5;
  bool parachuteOpen = false;

  ballCenter = ball.get_center();
  ballYValue = ballCenter.get_y();

  parachuteRelease = cwin.get_int("Enter seconds before chute opens\n");

  cwin << Line(Point(0,5),Point(1000,10));
  cwin << ball;

  while(ballYValue > 30 )
  {

    if(timeSeconds <  parachuteRelease)
    {  
      if(downVelocity < 174-32)
      {
        downVelocity += 32;
      }
      else
      {
        downVelocity = 174;
      }
    }
    else
    {
      parachuteOpen = true;
      
      if(downVelocity > 17)
      {
        downVelocity -= 100;
      }
      else
      {
        downVelocity = 17;
      }    
    }
 
    ball.move(0,-downVelocity);
       
    ballCenter = ball.get_center();
    ballYValue = ballCenter.get_y();
   
    if(ballYValue < 30)
    { 
      ball.move(0,30);
      cwin << ball;
    }
    else
    {
      cwin << ball;
    }

    timeSeconds++;
  }
 
  Message m1(Point (10,200), "You hit the ground");

  cwin << m1;

  if(parachuteOpen)
  {
    Message m2(Point (10,175), "And the parachute opened!!!");
    cwin << m2;
  }
  else
  {
    Message m2(Point (10,175), "Parachute failed, that sucks!!");
    cwin << m2;
  }

  return 0;
}
