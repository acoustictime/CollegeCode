/*
 6.8
 A parking garage charges a $2.00 minimum fee to park for 
 up to three hours. The garage charges an additional 
 $0.50 per hour for each hour or part thereof in excess of
 three hours. The maximum charge for any given 24-hour 
 period is $10.00. Assume that no car parks for longer than 
 24 hours at a time. Write an application that calculates 
 and displays the parking charges for each customer who 
 parked in the garage yesterday. You should enter the hours 
 parked for each customer. The program should display the 
 charge for the current customer and should calculate and 
 display the running total of yesterday’s receipts. The 
 program should use the method calculateCharges to determine 
 the charge for each customer.

  James Small
  Lesson 8
  Problem 6.8
 */

import java.util.Scanner;

public class Lesson8Prob68 
{
	public static void main(String args[])
	{
		Scanner input = new Scanner(System.in);
  
		//Declare and initialize Variables
		int hours = 0;
		double totalCharges = 0;
  
		do // Main do while loop.  Will run until 0 entered for hours.
		{
			System.out.println("\nEnter the amount of hours parked,\nIf done entering, type 0 for the hours: \n"); // Ask user for hours
			hours = input.nextInt();
  
			while (hours < 0) // While hours entered is negative, ask again.
			{
				System.out.println("The amount of hours can't be negative\n" +
						"This isn't back to the future now is it.\nEnter the amount " +
				"of hours parked\nIf done entering, type 0 for the hours: \n");
				hours = input.nextInt();
			}
   
			if (hours == 0) // if hours is 0, skip to next iteration of main do while loop
				continue;
  
  
			System.out.printf("\nCharges for %d hours = %.2f",hours,calculateCharges(hours)); // Print current charges
 
			totalCharges += calculateCharges(hours); // add to total charges for the day
  
			System.out.printf("\nTotal Charges For Yesterday = %.2f\n",totalCharges); // print current total yesterday's charges
   
		}while(hours != 0); // end while loop, checking for hours entered = 0;
 
		System.out.printf("\nFinal Total Charges For Yesterday = %.2f\n",totalCharges); // print final total for yesterday
 
	} 
  
	static double calculateCharges(int hours) // calculate charges method
 	{
		//Declare and initialize variables
		double charges = 0;
   
		if (hours <= 3)  // if hours less than or equal to 3
			charges = 2.00;
		else // if hours more than three
			charges = 2.00 + (float)(hours - 3) * .5;
   
		if (charges > 10.00) // if charges was higher then 10, then set charges to maximum allowed of 10
			charges = 10.00;

		return charges; // return current charges for hours entered
 	}
}