/*
 * 5.14	Modify the compound-interest application of Fig 5.6 to repeat 
 * its steps for interest rates of 5, 6, 7, 8, 9 and 10%. Use a for 
 * loop to vary the interest rate.
 * 		
 * 				James Small
 * 				Lesson 6
 * 				Problem 5.14
 */

import java.text.DecimalFormat;
import javax.swing.*;

public class Lesson6Prob514 
{
	public static void main( String args[] )
	{
		double amount, principal = 1000.0, rateMax = .10; // Declare and Initialize Variables
 
		DecimalFormat precisionTwo = new DecimalFormat( "0.00" ); // Set precision level of values
		JTextArea outputTextArea = new JTextArea( 11, 100 ); // Output area, extended horizontally to fit output.

		outputTextArea.append( "Year"); // Display year text
		
		for (double rate = .05;rate <= rateMax; rate += .01) // Loop through and setup titles of columns using rates.
		{
			outputTextArea.append( "\t Rate " + precisionTwo.format (rate * 100)+ "%\t" );
		}
			
		for ( int year = 0; year <= 10; year++ ) // Loop for each of the 10 years we are calculating
		{
			outputTextArea.append( "\n" + year); // Display year number on left hand column
			
			for (double rate = .05;rate <= rateMax; rate += .01) // Loop to actually calculate rate for current year and specific interest rate.
			{
				amount = principal * Math.pow( 1.0 + rate, year ); // Calculate amount
				outputTextArea.append("\t$" + precisionTwo.format( amount ) + "\t" ); // Output amount tabbing to the right per interest rate on the for loop above.
			}
		}
			
		JOptionPane.showMessageDialog(null, outputTextArea, "Compound Interest For Ten Years, Interest Rate 5% to 10%",JOptionPane.INFORMATION_MESSAGE ); // Title of text area
 
		System.exit( 0 ); // terminate the application
	}
}