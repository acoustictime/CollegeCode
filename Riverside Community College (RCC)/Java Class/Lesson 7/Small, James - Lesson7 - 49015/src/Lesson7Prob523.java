/*
 5.23	(De Morgan’s Laws) In this chapter, we have discussed the logical operators 
 &&, &, ||, |, ^ and !. De Morgan’s Laws can sometimes make it more convenient for 
 us to express a logical expression. These laws state that the expression 
 !(condition1 && condition2) is logically equivalent to the expression 
 (!condition1 || !condition2). Also, the expression !(condition1 || condition2) is 
 logically equivalent to the expression (!condition1 && !condition2). Use De Morgan’s 
 Laws to write equivalent expressions for each of the following, then write an 
 application to show that both the original expression and the new expression in each
  case produce the same value:
  
 	a)	!( x < 5 ) && !( y >= 7 )
 	b)	!( a == b ) || !( g != 5 )
 	c)	!( ( x <= 8 ) && ( y > 4 ) )
 	d)	!( ( i > 4 ) || ( j <= 6 ) )
 */

public class Lesson7Prob523 
{
	public static void main(String args[])
	{
		//Declare and initialize test variables for testing purposes
		int x = 1;
		int y = 1;
		int a = 1;
		int b = 1;
		int g = 1;
		int i = 1;
		int j = 1;
		
		System.out.println("A: !( x < 5 ) && !( y >= 7 ) is equivalent to !(x < 5 || y > 7)\n"); // Output for part a
		System.out.println("Are they equivalent, survey says....\n");
		
		if ((!( x < 5 ) && !( y >= 7 )) == !(x < 5 || y > 7)) // Confirm they are equal
		{
			System.out.print("Yes\n\n"); // Outputs yes if they are equal
		}
		else
		{
			System.out.print("No\n\n"); // Outputs no if they are not equal
		}
		
		System.out.println("B: !( a == b ) || !( g != 5 ) is equivalent to !(a == b && g != 5)\n");
		System.out.println("Are they equivalent, survey says....\n");
		
		if ((!( a == b ) || !( g != 5 )) == !(a == b && g != 5)) // Confirm they are equal
		{
			System.out.print("Yes\n\n"); // Outputs yes if they are equal
		}
		else
		{
			System.out.print("No\n\n"); // Outputs no if they are not equal
		}
		
		System.out.println("C: !(( x <= 8 ) && ( y > 4 )) is equivalent to !(x <= 8) || !(y > 4)\n");
		System.out.println("Are they equivalent, survey says....\n");
		
		if (!(( x <= 8 ) && ( y > 4 )) == (!(x <= 8) || !(y > 4))) // Confirm they are equal
		{
			System.out.print("Yes\n\n"); // Outputs yes if they are equal
		}
		else
		{
			System.out.print("No\n\n"); // Outputs no if they are not equal
		}
		
		System.out.println("D: !(( i > 4 ) || ( j <= 6 )) is equivalent to !(i > 4) && !(j <= 6)\n");
		System.out.println("Are they equivalent, survey says....\n");
		
		if (!(( i > 4 ) || ( j <= 6 )) == (!(i > 4) && !(j <= 6))) // Confirm they are equal
		{
			System.out.print("Yes\n\n"); // Outputs yes if they are equal
		}
		else
		{
			System.out.print("No\n\n"); // Outputs no if they are not equal
		}
		
	}

}
