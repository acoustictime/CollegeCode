/*
  4.30
	(Palindromes) A palindrome is a sequence of characters that reads the same backward 
	as forward. For example, each of the following five-digit integers is a palindrome: 
	12321, 55555, 45554 and 11611. Write an application that reads in a five-digit 
	integer and determines whether it is a palindrome. If the number is not five digits 
	long, display an error message and allow the user to enter a new value.
	
		James Small
		Lesson 5
		Problem 4.30
 */

import java.util.Scanner; // Needed for input

public class Lesson5Prob430 
{
	public static void main(String args[])
	{
		Scanner input = new Scanner(System.in); // Declared and intialized scanner object
		
		//Declare values
		int original;
		int num1;
		int num2;
		int num3;
		int num4;
		int num5;
		int temp = 0;
		
		System.out.println("Enter a five digit number: \n"); // Enter the five digit number
		original = input.nextInt();
		
		while (original > 99999 || original < 10000) // Check if a five digit number was entered, if not, enter a new number
		{
			System.out.println("\nThe number you entered isn't a five digit number, try again!!:\n");
			original = input.nextInt();
		}
		
		num1 = original / 10000; // Divide original number by 10,000 to get the value of the first digit
		temp = num1 * 10000; // Temp variable to store num1 * 10,000
		
		num2 = (original - temp) / 1000; // subtract temp number above from original number and then divide by 1000 to get second digit
		temp = temp + num2 * 1000; // add temp number from above to num2 * 1000
		
		num3 = (original - temp) / 100; // subtract temp number above from original number and then divide by 100 to get second digit
		temp = temp + num3 * 100; //add temp number from above to num3 * 100
		
		num4 = (original - temp) / 10; // subtract temp number above from original number and then divide by 10 to get second digit
		temp = temp + num4 * 10; //add temp number from above to num4 * 10

		num5 = (original - temp) / 1; // subtract temp number above from original number and then divide by 1 to get second digit
		
		if (num1 == num5) // Check if number 1 = number 5.  If not, then not a palindrome.
		{
			if (num2 == num4) // Check if number 2 = number 4.  If not, then not a palindrome.
			{
				System.out.printf("\nThe number you entered, %d, is a palindrome!!\n",original); // Display is a palindrome message
			}
			else
			{
				System.out.printf("\nThe number you entered, %d, is not a palindrome, sorry.\n",original); // Dipslay not a palindrome message
			}
		}
		else
		{
			System.out.printf("\nThe number you entered, %d, is not a palindrome, sorry.\n",original); // Dipslay not a palindrome message
		}
		
	/*	 This code was used to confirm my algorithm to separate the numbers out worked correctly.
	 
		System.out.printf("\nNumber 1 = %d",num1);
		System.out.printf("\nNumber 2 = %d",num2);
		System.out.printf("\nNumber 3 = %d",num3);
		System.out.printf("\nNumber 4 = %d",num4);
		System.out.printf("\nNumber 5 = %d",num5);
		*/
	}
}
