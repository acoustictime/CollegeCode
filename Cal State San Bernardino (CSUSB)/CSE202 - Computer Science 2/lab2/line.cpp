/* Program: line.cpp */

#include "ccc_win.h"

int ccc_win_main()
{
  cwin.coord(0,15,15,0);
  Point p(1, 3);
  Point q(4, 7);
  Line s(p,q);
  cwin << s ;
  s.move(2,5);
  cwin << s ;
  return 0;
}
