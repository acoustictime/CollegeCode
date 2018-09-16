/*
8.5 Modify the Date class of Fig. 8.9 "from the book"  (6th edition due 8.8 and refer to Fig 8.7) 
to perform error checking on the initializer values for instance variables month, day and year. 
Also, provide a method nextDay to increment the day by one. The Date object should always remain 
in a consistent state. Write a driver program that tests the nextDay method in a loop that prints 
the date during each iteration of the loop to illustrate that the nextDay method works correctly. 
Be sure to test the following cases:

a. Incrementing into the next month. 
b. Incrementing into the next year. 

8.6 Combine the modified Time3 class of Exercise 8.4 and the modified Date class of Exercise 8.5 
into one class called DateAndTime. (6th edition due problem 8.13)  Modify the tick method to call 
the\ nextDay method if the time is incremented into the next day. Modify methods toString and 
toUniversalString() to output the date in addition to the time. Write a driver program to test the 
new class DateAndTime. Specifically test incrementing the time to the next day.

8.7 Modify the set methods in the program of Fig. 8.7 to return appropriate error values if an attempt
 is made to set one of the instance variables hour, minute or second of an object of class Time to an
  invalid value. (Same for 6th edition)  (Hint: Use boolean return types on each method.)

8.8 Create a class Rectangle. (6th edition, this is 8.4)  The class has attributes length and width, 
each of which defaults to 1. It has methods that calculate the perimeter and the area of the rectangle. 
It has set and get methods for both length and width. The set methods should verify that length and 
width are each floating-point numbers larger than 0.0 and less than 20.0.

8.9 Create a more sophisticated Rectangle class than the one you created in Exercise 8.8. (This problem 
is 8.14 in the sixth edition)   This class stores only the Cartesian coordinates of the four corners of 
the rectangle. The constructor calls a set method that accepts four sets of coordinates and verifies that 
each of these is in the first quadrant with no single x- or y-coordinate larger than 20.0. The set method 
also verifies that the supplied coordinates do, in fact, specify a rectangle. Provide methods to calculate 
the length, width, perimeter and area. The length is the larger of the two dimensions. Include a predicate 
method isSquare which determines if the rectangle is a square.
 */

import javax.swing.*;
 
public class Lesson11 extends JApplet{

	private static final long serialVersionUID = 101010;

	public void init()
	{	
		// Input system to determine which problem to run
		int inN;
		do{
	         inN=getN();
	         switch(inN)
	         {
	          case 1:    problem1();break;
	          case 2:    problem2();break;
	          case 3:    problem3();break;
	          case 4:    problem4();break;
	          case 5:    problem5();break;
	          default:
	         }
	       }while(inN != 0);	
	}
	
	public static int getN() // Used to actual enter which program to run.
	{
		int value = 0;
		String choice = "";
	
		do
		{
			choice = JOptionPane.showInputDialog( 
					"\nHomework Menu\n\n" +
					"Press 1 for Problem 8.5\n"+
					"Press 2 for Problem 8.6\n"+
					"Press 3 for Problem 8.7\n"+
					"Press 4 for Problem 8.8\n"+
					"Press 5 for Problem 8.9\n"+
					"Press 0 To Quit\n");
		}while((Integer.parseInt(choice)) > 5 || (Integer.parseInt(choice)) < 0);
			
		value = Integer.parseInt(choice);
		
		return value;
	}

	public void problem1() // problem 1 method
	{
		Date d = new Date(12,25,2010);
		
		for(int i = 1;i < 10;i++)
		{
			d.nextDay();
			System.out.print(d.toString());
		}	
	} // end problem 1
		
	public void problem2() // problem 2 method
	{
		DateTime dt = new DateTime(12,31,2000,23,59,50);
		
		for(int i = 1;i < 50;i++)
		{
			dt.nextSecond();
			System.out.print(dt.toString());
		}	
	} // end problem 2
		
	public void problem3() // problem 3
	{
		Time2 t = new Time2(111,122,2);
		String choice;
		
		System.out.printf("%s\n",t.toString());
		
		do
		{
			choice = JOptionPane.showInputDialog( 
					"Enter the current hour, 0 to 23.");
		}while(!(t.setHour(Integer.parseInt(choice))));
		
		
		
		do
		{
			choice = JOptionPane.showInputDialog( 
					"Enter the current minute, 0 to 59.");
		}while(!(t.setMinute(Integer.parseInt(choice))));
		
		do
		{
			choice = JOptionPane.showInputDialog( 
					"Enter the current second, 0 to 59.");
		}while(!(t.setSecond(Integer.parseInt(choice))));
			
		System.out.printf("%s\n",t.toString());
		
	} // end problem 3

	public void problem4() // problem 4
	{
		Rectangle r = new Rectangle(110,100);	
		for(int i = 1;i <= 20;i++)
		{
			System.out.printf("Sides = %.2f & %.2f\tPerimeter = %.2f\tArea = %.2f\n",r.getLength(),r.getWidth(),r.permieter(),r.area());
			r.setLength(r.getLength() + 1);
			r.setWidth(r.getWidth() + 1);
		}	
	} // end problem 4
	
	public void problem5() // problem 5
	{
		Rectangle2 r2 = new Rectangle2(2,4,2,2,5,4,4,2);
		System.out.printf("\nThe Length of r2 is %d",r2.getLength());
		System.out.printf("\nThe Width of r2 is %d",r2.getWidth());
		System.out.printf("\nThe Perimeter of r2 is %d",r2.getPerimeter());
		System.out.printf("\nThe Area of r2 is %d",r2.getArea());
		if(r2.isSquare())
			System.out.print("\nThe coordinates form a square.\n");
		else
			System.out.print("\nThe coordinates do not form a square.\n");
		
		Rectangle2 r3 = new Rectangle2(4,8,4,4,12,8,12,4);
		System.out.printf("\nThe Length of r3 is %d",r3.getLength());
		System.out.printf("\nThe Width of r3 is %d",r3.getWidth());
		System.out.printf("\nThe Perimeter of r3 is %d",r3.getPerimeter());
		System.out.printf("\nThe Area of r3 is %d",r3.getArea());
		if(r3.isSquare())
			System.out.print("\nThe coordinates form a square.");
		else
			System.out.print("\nThe coordinates do not form a square.");
		
		
		
		
	} // end problem 5

} // end Lesson9