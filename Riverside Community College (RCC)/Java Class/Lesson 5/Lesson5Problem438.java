/*
4.38
	The factorial of a nonnegative integer n is written as n! (pronounced “n factorial”) and is defined as follows:
 
 	 n! = n · (n − 1) · (n − 2) · … · 1 (for values of n greater than or equal to 1)
and

 	 n! = 1 (for n = 0)
For example, 5! = 5 · 4 · 3 · 2 · 1, which is 120.

 	a)	Write an application that reads a nonnegative integer and computes and prints its factorial.
 	b)	Write an application that estimates the value of the mathematical constant e by using the formula


 	c)	Write an application that computes the value of ex by using the formula

		James Small
		Lesson 5
		Problem 4.38

 */

import java.util.Scanner;

public class Lesson5Problem438 {
	
	public static void main(String args[])
	{
		Scanner input = new Scanner(System.in); // Scanner input object
		
		//Part A
		
		// Declare Variables
		int factoral = 0;
		int computed = 0;
		int counter = 0;
		
		System.out.println("Please enter a non negative number: \n"); // Input number
		factoral = input.nextInt();
		
		while (factoral <= 0) // Check if positive
		{
			System.out.println("\nYou enterd a negative number, try again: ");
			factoral = input.nextInt();
		}
	
		computed = factoral;
		factoral -= 1;
	
		while (counter < factoral) // Loop through values until down to 1
		{
			computed *= factoral;
			factoral -= 1;
		}
	
		System.out.printf("\nThe factoral value is %d\n\n",computed); // Display computed
		
		// Part B & C
		
		double acc=1.0E-17;  //accuracy desired
        
        for(double x=1;x<=3;x++) //Try x=1,2,3...10
        {
            double ex=1,i = 1; //declare outside inner for-loop so we can use them in the printout
         
            double fac = 1;
            	
            	while(i<=100 && fac>=acc)
            	{
            		fac*=x/i;
            		ex+=fac;
            		i++;
            	}
            
        	System.out.println("Value of x = "+x+" The value of e^x = "+ex);
        }
		
		
	}
}