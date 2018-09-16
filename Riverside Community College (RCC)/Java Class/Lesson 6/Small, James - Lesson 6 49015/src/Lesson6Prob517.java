/*
  5.17	A mail-order house sells five products whose retail prices are as 
  follows: Product 1, $2.98; product 2, $4.50; product 3, $9.98; product 4, 
  $4.49 and product 5, $6.87. Write an application that reads a series of 
  pairs of numbers as follows:
 	a)	product number
 	b)	quantity sold
Your program should use a switch statement to determine the retail price 
for each product. It should calculate and display the total retail value 
of all products sold. Use a sentinel-controlled loop to determine when 
the program should stop looping and display the final results.

		James Small
		Lesson 6
		Problem 5.17
 */

import java.util.Scanner;

public class Lesson6Prob517
{
   public static void main( String args[] )
   {
     	Scanner input = new Scanner( System.in ); // Scanner Object
	
     	//Declare and initialize variables
     	int prod1Count = 0;
     	int prod2Count = 0;
     	int prod3Count = 0;
     	int prod4Count = 0;
     	int prod5Count = 0;
     	int item = 1;
     	int quantity;
	
     	// Loop and ask user for item # and quantity

     	while (item != 0) // While item # doesnt equal 0
     	{
     		System.out.println("Please enter item #  you would like to purchase: \n");
     		System.out.println("Item # 1 - Press 1");
     		System.out.println("Item # 2 - Press 2");
     		System.out.println("Item # 3 - Press 3");
     		System.out.println("Item # 4 - Press 4");
     		System.out.println("Item # 5 - Press 5");
     		System.out.println("Done Entering - Press 0\n");

     		item = input.nextInt();

     		while (item < 0 || item > 5) // Check if item # is within range
     		{
     			System.out.println("\nNumber entered was out of range, try again: \n");
				System.out.println("Please enter item #  you would like to purchase: \n");
				System.out.println("Item # 1 - Press 1");
				System.out.println("Item # 2 - Press 2");
				System.out.println("Item # 3 - Press 3");
				System.out.println("Item # 4 - Press 4");
				System.out.println("Item # 5 - Press 5");
				System.out.println("Done Entering - Press 0\n");

				item = input.nextInt();
     		}
		
     		if (item == 0) // If entered 0 to exit, break out of main while loop
     			continue;

     		System.out.printf("\nPlease enter quantity purchased for item # %d: \n",item); // Enter quantity

     		quantity = input.nextInt();

     		while (quantity <= 0) // Check for at least 1 quantity
     		{
     			System.out.println("\nYou need to buy at least one item!!!  Try Again: ");
     			quantity = input.nextInt();
     		}

     		switch(item) // Switch to increase count per product selected
     		{
     			case 1:
     				prod1Count += quantity;
     				break;
     			case 2:
     				prod2Count += quantity;
     				break;
     			case 3:
     				prod3Count += quantity;
     				break;
     			case 4:
     				prod4Count += quantity;
     				break;
     			case 5:
     				prod5Count += quantity;
     				break;
     			case 0:
     				break;
     		}
     	}

     	System.out.printf("\nThe results for the %d items you purchased are:\n",prod1Count + prod2Count + prod3Count + prod4Count + prod5Count); // Output menu begin
     	
     	System.out.println("\nItem #\tQuantity\tTotal Cost");
   		
     	for (int counter = 1;counter <= 5; counter++) // Loop through all 5 products and use switch below to output totals
     	{
     		switch(counter)
     		{
     			case 1:
     				System.out.printf("\n%d\t%d\t\t$%.2f",counter, prod1Count, (float) prod1Count * 2.98);
     				break;
     			case 2:
     				System.out.printf("\n%d\t%d\t\t$%.2f",counter, prod2Count, (float) prod2Count * 4.50);		
     				break;
     			case 3:
     				System.out.printf("\n%d\t%d\t\t$%.2f",counter, prod3Count, (float) prod3Count * 9.98);
     				break;
     			case 4:
     				System.out.printf("\n%d\t%d\t\t$%.2f",counter, prod4Count, (float) prod4Count * 4.49);		
     				break;
     			case 5:
     				System.out.printf("\n%d\t%d\t\t$%.2f",counter, prod5Count, (float) prod5Count * 6.87);
     				break;
     		}
     	} 
   	}
}