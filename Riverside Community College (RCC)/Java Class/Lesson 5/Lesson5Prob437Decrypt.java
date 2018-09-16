/*
 4.37
	A company wants to transmit data over the telephone, but is concerned that 
	its phones may be tapped. It has asked you to write a program that will 
	encrypt the data so that it may be transmitted more securely. All the data 
	is transmitted as four-digit integers. Your application should read a 
	four-digit integer entered by the user and encrypt it as follows: Replace 
	each digit with the result of adding 7 to the digit and getting the 
	remainder after dividing the new value by 10. Then swap the first digit 
	with the third, and swap the second digit with the fourth. Then print the 
 integer. Write a separate application that inputs an encrypted four-digit 
 integer and decrypts it to form the original number.
 
 		James Small
 		Lesson 5
 		Problem 4.37 Decrypt

*/

import java.util.Scanner;

public class Lesson5Prob437Decrypt
{
	public static void main(String args[])
	{
		Scanner input = new Scanner(System.in); // Declared and initialized scanner object
		
		//Declare values
		int original;
		int num1;
		int num2;
		int num3;
		int num4;
		int temp = 0;
		double temp2 = 0.0;
		
		System.out.println("Enter a four digit number to decrypt: \n"); // Enter the four digit number
		original = input.nextInt();
		
		while (original > 9999 || original < 1000) // Check if a four digit number was entered, if not, enter a new number
		{
			System.out.println("\nThe number you entered isn't a four digit number, try again!!:\n");
			original = input.nextInt();
		}
		
		num1 = original / 1000; // Divide original number by 10,00 to get the value of the first digit
		temp = num1 * 1000; // Temp variable to store num1 * 10,00
		
		num2 = (original - temp) / 100; // subtract temp number above from original number and then divide by 100 to get second digit
		temp = temp + num2 * 100; // add temp number from above to num2 * 100
		
		num3 = (original - temp) / 10; // subtract temp number above from original number and then divide by 10 to get second digit
		temp = temp + num3 * 10; //add temp number from above to num3 * 10
		
		num4 = (original - temp) / 1; // subtract temp number above from original number and then divide by 1 to get second digit
		
		/* Decryption code Replace 
		each digit with the result of adding 7 to the digit and getting the 
		remainder after dividing the new value by 10. Then swap the first digit 
		with the third, and swap the second digit with the fourth. */
		
		// Swamp numbers 1 & 3
		temp = num1;
		num1 = num3;
		num3 = temp;
		
		// Swap numbers 2 & 4
		temp = num2;
		num2 = num4;
		num4 = temp;
		
		// Reverse what we did during encryption
		
		num1 = (num1 + 3) % 10;
		num2 = (num2 + 3) % 10;
		num3 = (num3 + 3) % 10;
		num4 = (num4 + 3) % 10;
		
		System.out.printf("\nThe encrypted number is \n\n%d%d%d%d\n",num1,num2,num3,num4);	//Display decrypted number
	}
}