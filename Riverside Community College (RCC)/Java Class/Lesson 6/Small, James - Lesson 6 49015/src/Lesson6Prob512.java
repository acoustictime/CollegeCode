/*
5.12	Write an application that calculates the product of the odd integers from 1 to 15.

	James Small
	Lesson 6
	Problem 5.12
*/

public class Lesson6Prob512
{
   public static void main( String args[] )
   {
	   int product = 1; // Define and initialize product

	   for (int counter = 1; counter <= 15;counter += 2) // Loop through all odd numbers through 15 and multiply by product variable.
	   {
		   product *= counter;
	   }
	
	   System.out.printf("The sum of the odd digits between 1 and 15 is %d", product); // Display results
   	} 
}
