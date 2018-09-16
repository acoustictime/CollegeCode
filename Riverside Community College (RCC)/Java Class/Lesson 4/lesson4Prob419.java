/*
 * 4.19
	A large company pays its salespeople on a commission basis. The salespeople receive $200 per week 
	plus 9% of their gross sales for that week. For example, a salesperson who sells $5,000 worth 
	of merchandise in a week receives $200 plus 9% of $5,000, or a total of $650. You have been 
	supplied with a list of the items sold by each salesperson. The values of these items are as follows:
	
Item		Value	
1		239.99
2		129.75
3		 99.95
4		350.89

Develop a Java application that inputs one salesperson’s items sold for last week and calculates 
and displays that salesperson's earnings. There is no limit to the number of items that can be 
sold by a salesperson.

			James Small
			Lesson 4
			Problem 4.19
 */

import java.util.Scanner; //Needed for input from the user

public class lesson4Prob419 {
	
	public static void main(String args[])
	{	
		Scanner input = new Scanner(System.in); // Declare and initialize scanner object
		
		//Declare and initialize variables with static default values
		double item1 = 239.99;
		double item2 = 129.75;
		double item3 = 99.95;
		double item4 = 350.89;
		double basePay = 200.00;
		double percentage = .09;
		
		//Declare and initialize change values;
		double sold = 0.0;
		double total = 0.0;
		int currentItem;
		String employeeName;
		
		System.out.println("Enter employee name: \n"); // Input employee name
		employeeName = input.nextLine();
		
		System.out.println("\nEnter Item # for item sold\n\nItem # 1 Press 1\nItem # 2 Press 2\nItem # 3 Press 3\nItem # 4 Press 4\nDone Entering Press 0\n"); // Input item # that was sold
		currentItem = input.nextInt();
		
		while (currentItem != 0) // While currentItem isn't the sentinel value, input more items and increment total accordingly.
		{
			if (currentItem == 1) // If item # 1 is picked
				sold += item1; 
			if (currentItem == 2) // If item # 2 is picked
				sold += item2;
			if (currentItem == 3) // If item # 3 is picked
				sold += item3;
			if (currentItem == 4) // If item # 4 is picked
				sold += item4;
			
			System.out.println("\nEnter Item # for item sold\n\nItem # 1 Press 1\nItem # 2 Press 2\nItem # 3 Press 3\nItem # 4 Press 4\nDone Entering Press 0\n"); //Input item # that was sold
			currentItem = input.nextInt();	
		}
		
		total = basePay + sold * percentage; // Calculate total pay with commission
		
		//Display results of base pay, commission, and total for employee entered.
		
		System.out.printf("\nThe total paycheck for %s is as follows:\n\nBase Pay = $%.2f\nCommision Pay = $%.2f\nTotal Paid = $%.2f\n", employeeName,basePay,sold * percentage, total);				
	}
}
