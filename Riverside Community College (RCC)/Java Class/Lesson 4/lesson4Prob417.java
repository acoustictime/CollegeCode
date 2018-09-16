/*
 * 4.17
	Drivers are concerned with the mileage their automobiles get. One driver has kept track of several 
	tankfuls of gasoline by recording the miles driven and gallons used for each tankful. Develop a 
	Java application that will input the miles driven and gallons used (both as integers) for each 
	tankful. The program should calculate and display the miles per gallon obtained for each tankful
	 and print the combined miles per gallon obtained for all tankfuls up to this point. All averaging
	  calculations should produce floating-point results. Use class Scanner and sentinel-controlled 
	  repetition to obtain the data from the user.
	  
	  James Small
	  Lesson 4
	  Problem 4.17

*/

import java.util.Scanner;

public class lesson4Prob417 
{
	
	public static void main(String args[])
	{	
		Scanner input = new Scanner(System.in); // Scanner object
		
		//Declare and initialize values	
		int distance = 0;
		int gallons = 0;
		int totalDistance = 0;
		int totalGallons = 0;
		int tanks = 0;
		double mpg = 0.0;	
			
		while (distance != -1) // Run loop until sentinel value is entered.
		{	
			//Input distance traveled
			
			System.out.println("\nPlease enter the distance you traveled on this tankful.  If done entering, please enter -1\n");
			
			distance = input.nextInt();
			
			if (distance != -1) // If value -1, skip till end to exit loop
			{
				totalDistance += distance; // increase total distance traveled
				
				// input gallons used
				System.out.println("\nPlease enter the amount of gallons used this tankful\n");
				gallons = input.nextInt();
				
				totalGallons += gallons; // Inrease total gallons used
				
				++tanks; // Increment tanks used
				
				mpg = (double) distance / gallons; // Determine mpg for current tankful
				
				System.out.printf("\nThe MPG's for tankful # %d is %.2f\n", tanks,mpg); // Display results of current tankful
			
				mpg = (double) totalDistance / totalGallons; // Determine combined mpgs
				
				System.out.printf("\nThe total combined MPG's is %.2f\n", mpg); // Display results for combined mpgs			
			}			
		}
		
		System.out.printf("\nNow that you've entered the final trip numbers for all %d trips\nThe total combined MPG's is %.2f\n", tanks,mpg); // Display final results before ending program	
	}
}
