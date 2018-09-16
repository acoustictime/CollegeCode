/*
 6.13
 For each of the following sets of integers, 
 write a single statement that will display 
 a number at random from the set:
 
a)  2, 4, 6, 8, 10.
b)  3, 5, 7, 9, 11.
c)  6, 10, 14, 18, 22.

  James Small
  Lesson 8
  Problem 6.13
 */

import java.util.Scanner;
import java.util.Random;

public class Lesson8Prob613 
{
	public static void main(String args[])
	{
		Scanner input = new Scanner(System.in); // Input object
  
		int choice; // choice variable
  
		System.out.print("Please enter which set of numbers you are looking for:\n\n" + // which group of numbers to check for
		"Press 1 for 2,4,6,8,10\nPress 2 for 3,5,7,9,11\nPress 3 for 6,10,14,18,22: ");
   
		choice = input.nextInt(); // choice input

		randomizer(choice); // use randomize method with input.
	}
 
	static void randomizer(int choice) // randomizer method
	{
		Random rand = new Random(); // new random object called rand
  
		if (choice == 1) // if choice entered is 1
		{
			System.out.printf("Your random number out of 2,4,6,8,10 is: %d\n",(rand.nextInt(5) + 1) * 2); 
		}
		if (choice == 2) // if choice entered is 2
		{
			System.out.printf("Your random number out of 3,5,7,9,11 is: %d\n",((rand.nextInt(5) + 1) * 2) + 1);
		}
		
		if (choice == 3) // if choice entered is 3
		{
			System.out.printf("Your random number out of 6,10,14,18,22 is: %d\n",(((rand.nextInt(5) + 1) * 2) + 1) * 2);
		}
	}
}