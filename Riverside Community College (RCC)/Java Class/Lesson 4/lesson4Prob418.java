/*
 * 4.18
	Develop a Java application that will determine whether any of several department-store customers 
	has exceeded the credit limit on a charge account. For each customer, the following facts are available:
 	a)	account number
 	b)	balance at the beginning of the month
 	c)	total of all items charged by the customer this month
 	d)	total of all credits applied to the customer’s account this month
 	e)	allowed credit limit.
The program should input all these facts as integers, calculate the new balance (= beginning balance + charges − credits), 
display the new balance and determine whether the new balance exceeds the customer’s credit limit. For those customers 
whose credit limit is exceeded, the program should display the message "Credit limit exceeded".

			James Small
			Lesson 4
			Problem 4.18
 */

import java.util.Scanner; //Import Scanner Class

public class lesson4Prob418 {
	
	public static void main(String args[])
	{
		Scanner input = new Scanner(System.in); // Create and Initialize scanner object.
		
		//Declare Variables
		int account;
		int begBalance;
		int charged;
		int credits;
		int endBalance;
		int creditLimit;
		
		//Input account number
		System.out.println("Please enter your account number.\n(Enter -1 if you are done)\n");
		account = input.nextInt();
		
		while (account != -1) // Determine if account number is the sentinel value.
		{
			
			System.out.println("\nPlease enter your beginning balance.\n"); // Input beginning balance
			begBalance = input.nextInt();
			
			System.out.println("\nPlease enter total charges this month.\n"); // Input charges for the month
			charged = input.nextInt();
			
			System.out.println("\nPlease enter total credits this month.\n"); // Input credits for the month
			credits = input.nextInt();
			
			System.out.println("\nPlease enter your account credit limit.\n"); // Input account credit limit
			creditLimit = input.nextInt();
			
			endBalance = begBalance + charged - credits; // Calculate ending balance
			
			if (endBalance > creditLimit) // Check if credit limit was exceeded.
			{
				System.out.printf("\nYou exceeded your credit limit of $%d by $%d\nCredit Limit Exceeded for Account # %d!!!!!\n", creditLimit,endBalance - creditLimit,account); // Display credit limit exceeded message.
			}
			else // If balance wasn't exceeded.
			{
				System.out.printf("\nYour current balance for account # %d is $%d\n", account,endBalance); // Display current balance.
			}
			
			System.out.println("\nPlease enter your account number.\n(Enter -1 if you are done)\n"); // Input new account number for starting loop over again.
			account = input.nextInt();			
		}	
	}
}
