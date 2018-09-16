/*
 7.10 Use a single-subscripted array to solve the following problem. A company 
 pays its salespeople on a commission basis. The salespeople receive $200 per 
 week plus 9% of their gross sales for that week. For example, a salesperson 
 who grosses $5000 in sales in a week receives $200 plus 9% of $5000 or a total 
 of $650. Write a program (using an array of counters) that determines how many 
 of the salespeople earned salaries in each of the following ranges (assume that 
 each salespersonÕs salary is truncated to an integer amount):

a.$200-$299 
b.$300-$399 
c.$400-$499 
d.$500-$599 
e.$600-$699 
f.$700-$799 
g.$800-$899 
h.$900-$999 
i.$1000 and over 

7.11 The bubble sort presented in Fig. 7.11 is inefficient for large arrays. Make 
the following simple modifications to improve the performance of the bubble sort. 

a. After the first pass, the largest number is guaranteed to be in the highest-numbered 
element of the array; after the second pass, the two highest numbers are "in place"; 
and so on. Instead of making nine comparisons on every pass, modify the bubble sort 
to make eight comparisons on the second pass, seven on the third pass and so on.  

b. The data in the array may already be in the proper order or near-proper order, so 
why make nine passes if fewer will suffice? Modify the sort to check at the end of 
each pass if any swaps have been made. If none has been made, the data must already 
be in the proper order, so the program should terminate. If swaps have been made, at 
least one more pass is needed. 

7.15 Write a program to simulate the rolling of two dice. The program should use 
Math.random to roll the first die and should use Math.random again to roll the second 
die. The sum of the two values should then be calculated. [Note: Since each die can 
show an integer value from 1 to 6, the sum of the values will vary from 2 to 12, with 
7 being the most frequent sum and 2 and 12 being the least frequent sums. Figure 7.17 
shows the 36 possible combinations of the two dice. Your program should roll the dice 
36,000 times. Use a single-subscripted array to tally the numbers of times each possible 
sum appears. Print the results in a tabular format. Also, determine if the totals are 
reasonable (i.e., there are six ways to roll a 7, so approximately one sixth of all the 
rolls should be 7).]
 
		James Small
		Lesson 10
		Homework
 
 */

import java.awt.Container;
import javax.swing.*;

public class Lesson10 extends JApplet
{
	private static final long serialVersionUID = 101010;

	public void init()
	{
		// Input system to determine which problem to run
		int inN;

		do{
			inN=getN();
			
			switch(inN)
			{
			case 1: problem1();break;
			case 2: problem2();break;
			case 3: problem3();break;
			default:
			}
		}while(inN != 0); 
	}

	public static int getN() // Used to actual enter which program to run.
	{
		int value = 0;
		String choice = "";

		do
		{
			choice = JOptionPane.showInputDialog( 
					"\nHomework Menu\n\n" +
					"Press 1 for Problem 1\n"+			
					"Press 2 for Problem 2\n"+
					"Press 3 for Problem 3\n"+
					"Press 0 To Quit\n");
		}while((Integer.parseInt(choice)) > 3 || (Integer.parseInt(choice)) < 0);

		value = Integer.parseInt(choice);

		return value;
	}

	public void problem1() // problem 1 method
	{
		int totals[] = new int[9]; // array for totals count
		
		String choice = "1"; // string choice
		
		while(Integer.parseInt(choice) != 0) // while choice isn't 0
		{	
			do
			{
				choice = JOptionPane.showInputDialog( 
					"\nEnter your choice\n\n" +
					"Press 1 to input employee gross sales\n"+			
					"Press 2 to display results\n"+
					"Press 0 To Quit\n");
			}while((Integer.parseInt(choice)) > 2 || (Integer.parseInt(choice)) < 0);
			
			if(Integer.parseInt(choice) == 1) // if choice is 1
			{
				do
				{
					choice = JOptionPane.showInputDialog( 
						"Enter the employee's gross sales");
				}while((Integer.parseInt(choice)) < 0);

				determine(200 + (int) (Integer.parseInt(choice) * .09),totals); // determine gross pay using determine method
			}
			else if(Integer.parseInt(choice) == 2) // if choice is 2
			{
				display(totals); // display totals using display method
			}	
		}
		
	} // end problem 1
	
	public void determine(int value, int array[]) // determine gross pay method
	{
		if(value > 199 && value <= 299) // increase counter depending on gross pay
			array[0] += 1;
		else if(value > 299 && value <= 399)
			array[1] += 1;
		else if(value > 399 && value <= 499)
			array[2] += 1;
		else if(value > 499 && value <= 599)
			array[3] += 1;
		else if(value > 599 && value <= 699)
			array[4] += 1;
		else if(value > 699 && value <= 799)
			array[5] += 1;
		else if(value > 799 && value <= 899)
			array[6] += 1;
		else if(value > 899 && value <= 999)
			array[7] += 1;
		else if(value > 999)
			array[8] += 1;	
	}

	public void display(int array[]) // display array
	{
		//display variables
		JTextArea outputArea = new JTextArea();
		Container c = getContentPane();
		c.add( outputArea );

		String output = "Salary Ranges\n";
		
		//output results
		output += "$200-$299\t" + array[0];
		output += "\n$300-$399\t" + array[1];
		output += "\n$400-$499\t" + array[2];
		output += "\n$500-$599\t" + array[3];
		output += "\n$600-$699\t" + array[4];
		output += "\n$700-$799\t" + array[5];
		output += "\n$800-$899\t" + array[6];
		output += "\n$900-$999\t" + array[7];
		output += "\nOver $1000\t" + array[8];
		
		outputArea.setText( output );
		JOptionPane.showMessageDialog(null, outputArea, "Salarly Ranges",JOptionPane.INFORMATION_MESSAGE);
	}
	
	public void problem2() // problem 2 method
	{
		//display variables
		JTextArea outputArea = new JTextArea();
		Container c = getContentPane();
		c.add( outputArea );

		int a[] = {2, 6, 13, 8, 10, 12, 89, 68, 45, 37}; // int array with default values
		int passes = 0; // counter for passes

		String output = "Data items in original order\n";

		// display values in array as original
		for ( int i = 0; i < a.length; i++ ) 
			output += " " + a[ i ];
 
		passes = bubbleSort( a ); // run bubble sort method
 
		output += "\n\nData items in ascending order\n";

		//display values in ascending order
		for ( int i = 0; i < a.length; i++ ) 
			output += " " + a[ i ];
		
		output += "\n\nIt only took " + passes + " passes"; // display total amount of passes

		outputArea.setText( output );
		JOptionPane.showMessageDialog(null, outputArea, "The Results",JOptionPane.INFORMATION_MESSAGE);
	}
 
 // sort the elements of an array with bubble sort
	public int bubbleSort( int b[])
	{ 
		//variables
		int control = 0;
		boolean noSwap = true;
		
		for ( int pass = 1; pass < b.length - control;control++ ) // passes
		{	
			noSwap = true;
			
			for ( int i = 0; i < b.length - 1; i++ ) // one pass 
			{	
				if ( b[ i ] > b[ i + 1 ] ) // one comparison
				{
					swap( b, i, i + 1 ); // one swap
					noSwap = false;		
				}
			}

			if(noSwap)
				break;
		}
		return control + 1;
	}
 
	// swap two elements of an array
	public void swap( int c[], int first, int second )
	{
		int hold; // temporary holding area for swap

		hold = c[ first ]; 
		c[ first ] = c[ second ]; 
		c[ second ] = hold;
	}


	public void problem3() // problem 3
	{
		//variables
		int array[] = new int[13];
		String output = "";

		for (int i = 1;i <= 36000;i++) // loop through 36000 times, getting the sum of two random numbers
		{ 
			array[(1 + (int)(Math.random() * 6)) + (1 + (int)(Math.random() * 6))] += 1;
		}

		output += "Face\tCount\n";

		//output results
		for (int j = 2; j < array.length; j++ )
			output += j + "\t" + array[j] + "\n";

		JTextArea outputArea = new JTextArea( 3, 3 );
		outputArea.setText( output );
		JOptionPane.showMessageDialog(null, outputArea, "The Results",JOptionPane.INFORMATION_MESSAGE);
	} // end problem 3
} // end Lesson10

 

