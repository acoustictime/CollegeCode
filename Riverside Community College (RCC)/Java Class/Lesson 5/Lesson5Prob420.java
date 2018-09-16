/*
 * 4.20
	Develop a Java application that will determine the gross pay for each of three employees. 
	The company pays straight time for the first 40 hours worked by each employee and time 
	and a half for all hours worked in excess of 40 hours. You are given a list of the 
	employees of the company, the number of hours each employee worked last week and the 
	hourly rate of each employee. Your program should input this information for each 
	employee and should determine and display the employee’s gross pay. Use class Scanner
	to input the data.
	
		James Small
		Lesson 5
		Problem 4.20
	
*/

import java.util.Scanner; // Scanner input

public class Lesson5Prob420
{	
	public static void main(String args[])
	{
		Scanner input = new Scanner(System.in); // Declare and initialize scanner object
		
		// Declare and initialize variables.
		double hours = 0.0;
		double rate = 0.0;
		double pay = 0.0;
		String name;
		int counter = 0;
		
		while (counter < 3) // While counter is less than 3
		{
			
			System.out.printf("\nEnter employee number %d's name: \n",counter + 1); // Input name
			name = input.nextLine();
			
			System.out.printf("\nEnter employee number %d's hours worked: \n", counter + 1); // Input hours worked
			hours = input.nextDouble();		
			
			System.out.printf("\nEnter employee number %d's hourly rate: \n", counter + 1); // Input Hourly Rate
			rate = input.nextDouble();
			
			if (hours > 40.00) // If hours worked are greater than 40
			{
				pay = rate * 40.00 + (hours - 40.00) * rate * 1.5; // Calculate pay	with overtime
			}
			else
			{
				pay = rate * hours; // calculate regular time	
			}
			
			System.out.printf("\nThe total paycheck for %s is %.2f\n",name,pay); // Display total amount of paycheck.
			
			name = input.nextLine(); //When the loop came back around, the nextLine input was off.  This catches it back up.
			
			++counter; // Increase counter by 1	
		}
	}
}
