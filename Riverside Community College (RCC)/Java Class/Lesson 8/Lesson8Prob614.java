/*

6.14

Write a method integerPower( base, exponent ) that returns the value of

base exponent

For example, integerPower( 3, 4 ) calculates 34 (or 3 * 3 * 3 * 3). Assume
that exponent is a positive, nonzero integer and that base is an integer.
Method integerPower should use a for or while loop to control the calculation.
Do not use any math-library methods. Incorporate this method into an
application that reads integer values for base and exponent and performs the
calculation with the integerPower method.

		James Small
		Lesson 8
		Problem 6.14

*/

import java.util.Scanner;

public class Lesson8Prob614
{
	public static void main(String args[])
	{
		Scanner input = new Scanner(System.in); // Scanner object
		
		//Declare and intialize variables
		int base = 0;
		int exponent = 0;
		
		System.out.print("Enter the base value for the equation\nPlease select a value greater than 0: "); // Enter base value
		base = input.nextInt();
		
		while (base <= 0) // keep looping until base value is greater than 0
		{
			System.out.print("\nThe value you entered is not greater than 0\n");
			System.out.print("Enter the base value for the equation\nPlease select a value greater than 0: ");
			base = input.nextInt();
		}
		
		System.out.print("\nEnter the exponent value for the equation\nPlease select a value greater than 0: "); // Enter exponent value
		exponent = input.nextInt();
		
		while (exponent <= 0) // keep looping until exponent value is greater than 0
		{
			System.out.print("\nThe value you entered is not greater than 0\n");
			System.out.print("Enter the exponent value for the equation\nPlease select a value greater than 0: ");
			exponent = input.nextInt();
		}
		

		System.out.printf("\n%d to the %d power is %d",base, exponent,(integerPower(base,exponent))); // output result using integerPower method
	}

	public static int integerPower(int base, int exponent) // Method takes base and exponent as parameters
	{
		int solution = base; // Declare and initialize variable
		
		for(int i = 2;i <= exponent;i++) // while counter is less than or equal to exponent, loop
		{
			solution *= base; // multiply current solution value by base
		}

		return solution; // once looped through exponent value, return solution
	}
}