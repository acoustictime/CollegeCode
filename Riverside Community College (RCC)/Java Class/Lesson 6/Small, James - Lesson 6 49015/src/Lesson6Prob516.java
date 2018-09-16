/*
 5.16	One interesting application of computers is to display graphs and 
 bar charts. Write an application that reads five numbers between 1 and 
 30. For each number that is read, your program should display the same 
 number of adjacent asterisks. For example, if your program reads the 
 number 7, it should display *******.
 
 		James Small
 		Lesson 6
 		Problem 5.16
 */

import java.util.Scanner;

public class Lesson6Prob516 
{
	public static void main(String args[])
	{
		Scanner input = new Scanner(System.in);
		
		int temp; // Declare variable

		for(int counter = 1;counter <= 5; ++counter) // Loop through 5 integers
		{
			System.out.println("Enter your first integer between 1 & 30: \n"); // Enter first integer
			temp = input.nextInt();
			
			while (temp < 1 || temp > 30) // Check if within constraints
			{
				System.out.printf("The number you entered, %d, is out of range, try again: \n",temp); // Try again.
				temp = input.nextInt();
			}
			
			for(int num = 1;num <= temp;++num) // Loop to output stars based on number entered
			{
				System.out.print("*");
			}
			
			System.out.println("\n"); // Used to add blank line after all stars entered.
		}	
	}
}
