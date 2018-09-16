/*
 5.11 
 Write an application that finds the smallest of several integers. 
 Assume that the first value read specifies the number of values to input 
 from the user.
 	
 		James Small
 		Lesson 6
 		Problem 5.11
 
 */

import java.util.Scanner;

public class Lesson6Prob511
{
   public static void main( String args[] )
   {
     Scanner input = new Scanner( System.in ); // Scanner object

     //Declare and initialize variables
     int totalNumbers;
     int currentNumber;
     int smallestNumber;
     int counter  = 1;

     System.out.println("Please enter the amout of integers to input: \n"); // Ask for integers to enter

     totalNumbers = input.nextInt();

     while (totalNumbers < 1) // Check to make sure at least 1 is entered
     {
    	 System.out.println("\nYou have to enter at least 1, try again: ");
    	 totalNumbers = input.nextInt();
     }

 	System.out.printf("\nPlease enter integer # %d: \n",counter); // Enter first integer
 	smallestNumber = input.nextInt(); // assume first number entered is the smallest

 	while (counter < totalNumbers) // Loop while total numbers is less than number entered in the beginning
 	{
 		System.out.printf("\nPlease enter integer # %d: \n",++counter); // Ask for second integer and so on in a loop
 		currentNumber = input.nextInt();

 		if (currentNumber < smallestNumber) // determine smallest number
 			smallestNumber = currentNumber;	
 	}

 	System.out.printf("\nThe smallest integer entered was %d: \n",smallestNumber);	//Output result
   } 
}




