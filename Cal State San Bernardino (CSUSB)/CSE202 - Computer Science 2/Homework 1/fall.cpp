#include "ccc_win.h"

const int BALL_RADIUS = 15;
const double HORIZONTAL_DECREASE_VELOCITY = 40;
const double TERMINAL_VELOCITY = 174;
const double INCREASE_VELOCITY = 32;
const double PARA_MAX_VELOCITY = 17;
const double DECREASE_VELOCITY = 100;
const double GROUND = 5;


int ccc_win_main()
{
  cwin.coord(0,1000,1000,0);
 
  double downVelocity = 0;
  double sideVelocity = 0;
  double ballYValue = 0;
  double ballXValue = -25; 
  int timeSeconds = 0;
  int parachuteRelease = 0;
  bool parachuteOpen = false;

  
  sideVelocity = cwin.get_int("Enter Speed of Plane: \n");
  ballYValue = cwin.get_int("Height of the plane: \n");
  parachuteRelease = cwin.get_int("Enter freefall time: \n");


  Point ballCenter(500,ballYValue);
  Circle ball(ballCenter,BALL_RADIUS);

  cwin << Line(Point(0,GROUND),Point(1000,GROUND));
  cwin << ball;

  while(ballYValue > GROUND + BALL_RADIUS )
  {

    if(timeSeconds <  parachuteRelease)
    {
      if(downVelocity < TERMINAL_VELOCITY - INCREASE_VELOCITY)
      {
        downVelocity += INCREASE_VELOCITY;
      }
      else
      {
        downVelocity = TERMINAL_VELOCITY;
      }
    }
    else
    {
      parachuteOpen = true;

      if(downVelocity > PARA_MAX_VELOCITY)
      {
        downVelocity -= DECREASE_VELOCITY;
        
      }
      else
      {
        downVelocity = PARA_MAX_VELOCITY;
      }

      if(sideVelocity > HORIZONTAL_DECREASE_VELOCITY)
      {
        sideVelocity -= HORIZONTAL_DECREASE_VELOCITY;
      }
      else
      {
        sideVelocity = 0;
      }
    }

    ball.move(sideVelocity,-downVelocity);

    ballCenter = ball.get_center();
    ballYValue = ballCenter.get_y();
    ballXValue = ballCenter.get_x();
  
 
    if(timeSeconds % 3 == 0)
    {
      cwin << ball;

      if(parachuteOpen)
      {
        cwin << Line(Point(ballXValue - BALL_RADIUS,ballYValue),Point(ballXValue + BALL_RADIUS,ballYValue));
      }
    }

    timeSeconds++;
  }

  return 0;
}
