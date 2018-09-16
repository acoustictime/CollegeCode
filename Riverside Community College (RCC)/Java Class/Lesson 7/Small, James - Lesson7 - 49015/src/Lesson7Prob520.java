/*
 5.20	Calculate the value of p from the infinite series
    
Print a table that shows the value of p approximated by 
computing one term of this series, by two terms, by three 
terms, and so on. How many terms of this series do you 
have to use before you first get 3.14? 3.141? 3.1415? 3.14159?

		James Small
		Lesson 7
		Problem 5.20

 */

import java.text.DecimalFormat;

import javax.swing.*;
import java.lang.Math; // Used for Absolute value
 
public class Lesson7Prob520  //********************************************Program takes about 1 minute to run to get all results, at least on my computer***************************
{
	public static void main( String args[] )
	{
		JTextArea outputArea = new JTextArea( 50, 30 );
		JScrollPane scroller = new JScrollPane( outputArea );
		String output = "";
		DecimalFormat precisionTwo = new DecimalFormat( "0.000000" ); // Set Precision

		//Declare and initialize variables
		double top = 4.0;
		int start = 4;
		int control = 3;
		int neg = 0;
		double value = 4.0;
		double temp;
		int twoDecimals = 0;
		int threeDecimals = 0;
		int fourDecimals = 0;
		int fiveDecimals = 0;
	
		// Header on output screen
		output += "Please scroll down for full results\n\n";
		output += "Terms\tValue\n\n";
		output += "1\t" + precisionTwo.format(start) + "\n";
		
		for(int counter = 2;counter < 300000;counter += 2) // Main loop, controls how many iterations to run.  300,000 is an arbitrary number high enough to get results, but won't allow an infinite loop
		{
			temp = 0; // Reset temp varibale every time through

				if(neg == 0) // Used to switch between the - and + portions of the equation
				{				
					temp = (top / (float) control); // Calculate new value to subtract from value.  Set as temp	
					value -= temp; // Subtract newley calculated temp variable to main value.
					neg = 1; // Used so next time through loop, you will add instead of subtract
				}
				else // used if need to add
				{
					temp = (top / (float) control ); // Calculate new value to subtract from value.  Set as temp	
					value = value + temp; // add newley calculated temp variable to main value.
					neg = 0; // Used so next time through loop, you will subtract instead of subtract			
				}
	
			output += "\n" + ((counter / 2) + 1) + "\t" + precisionTwo.format(value) + "\n"; // Out put current iteration
			
			if (Math.abs(value - 3.14) < 0.001 && twoDecimals == 0) // Check if current value is within precision set for 3.14
			{
				twoDecimals = ((counter / 2) + 1); // save current variable # for reporting
			}
			
			if (Math.abs(value - 3.141) < 0.0001 && threeDecimals == 0) // Check if current value is within precision set for 3.141
			{
				threeDecimals = ((counter / 2) + 1);	// save current variable # for reporting
			}
			
			if (Math.abs(value - 3.1415) < 0.00001 && fourDecimals == 0) // Check if current value is within precision set for 3.1415
			{
				fourDecimals = ((counter / 2) + 1);// save current variable # for reporting
			}
			
			if (Math.abs(value - 3.14159) < 0.00001) // Check if current value is within precision set for 3.14159
			{
				fiveDecimals = ((counter / 2) + 1);		// save current variable # for reporting
				break;
			}
		
			control += 2;		// Increase control variable by two which controls the denominator of equation above.
		}
		
		//Output results
		
		output += "\n\nIt took " + twoDecimals + " iterations to get 3.14\n";
		output += "\n\nIt took " + threeDecimals + " iterations to get 3.141\n";	
		output += "\n\nIt took " + fourDecimals + " iterations to get 3.1415\n";	
		output += "\n\nIt took " + fiveDecimals + " iterations to get 3.14159\n";	

		outputArea.setText( output );
		JOptionPane.showMessageDialog( null, scroller,
				"The Results of Pi", JOptionPane.INFORMATION_MESSAGE );
		System.exit( 0 );
	}
}