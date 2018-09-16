/*
 5.21  	(Pythagorean Triples) A right triangle can have sides 
 whose lengths are all integers. The set of three integer 
 values for the lengths of the sides of a right triangle is 
 called a Pythagorean triple. The lengths of the three sides 
 must satisfy the relationship that the sum of the squares of 
 two of the sides is equal to the square of the hypotenuse. 
 Write an application to find all Pythagorean triples for 
 side1,  side2 and the hypotenuse, all no larger than 500. 
 Use a triple-nested for loop that tries all possibilities. 
 This method is an example of “brute-force” computing. You 
 will learn in more advanced computer science courses that 
 there are large numbers of interesting problems for which 
 there is no known algorithmic approach other than using 
 sheer brute force. 
 
 		James Small
 		Lesson 7
 		Problem 5.21
 */

import java.lang.Math;

import javax.swing.JOptionPane;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;

public class Lesson7Prob521
{
	public static void main( String args[] )
	{	
		JTextArea outputArea = new JTextArea( 50, 30 );
		JScrollPane scroller = new JScrollPane( outputArea );
		String output = "";
		
		//Declare and initialize variables
		int length = 500;
		int counter = 0;
		
		output += ("Hyp\tSide1\tSide2\n"); // Top Headers
		
		for (int hyp = 1; hyp <= length; hyp++) // Loop for Hypotonuse 
		{
			for (int leg1 = 1; leg1 <= length; leg1++) // Loop for Side 1
			{
				for (int leg2 = 1; leg2 <= length; leg2++) // Loop for Side 2
				{
					if(Math.pow(leg2,2) + Math.pow(leg1,2) == Math.pow(hyp,2)) // Determine if triplet or not
					{
						
						output += "\n" + hyp + "\t" + leg1 + "\t" + leg2; // Output triplet
						counter++; // Increase counter for total triplets found
					}	
				}		
			}		
		}
		
		//Out put results for total triplets found
		output += ("\n\nThere were a total of " + counter + " Pythagorean Triplets\n\nwhose sides are less than " + length + " each\n\n");
		
		outputArea.setText( output );
		JOptionPane.showMessageDialog( null, scroller,
				"The Results of the Pythagorean Triplets", JOptionPane.INFORMATION_MESSAGE );
		System.exit( 0 );
	}
}
