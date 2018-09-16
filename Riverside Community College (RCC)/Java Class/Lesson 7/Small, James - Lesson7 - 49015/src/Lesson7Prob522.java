/*
 5.22  	Modify Exercise 5.15 to combine your code from 
 the four separate triangles of asterisks such that all 
 four patterns print side by side. Make clever use of 
 nested for loops. 
 
 		James Small
 		Lesson 7
 		Problem 5.22
 */
import javax.swing.*;

public class Lesson7Prob522 
{
	public static void main(String args[])
	{
		
		JTextArea outputArea = new JTextArea( 15, 20 );
		JScrollPane scroller = new JScrollPane( outputArea );
		String output = "";
		
		//Declard and initialize variables
		int starStart = 0;
		int starEnd = 0;
		int starInc = 0;
		int spaceStart = 0;
		int spaceEnd = 0;
		int spaceInc = 0;
		int rowWidth = 10;
		
		for (int row = 1; row <= rowWidth; row++) // main for loop that controls moving from row to row.
		{
			for (int loop = 1; loop <= 4;loop++) // Loop within each row.  Loops 4 times for all 4 groups I broke out.  Each group has different properties.
			{	
				switch (loop) // Switch to determine which of the four loops you're in.  Each of the loops controls one set of *, and one set of spaces.
				{
				case 1: // Sets start, end, & increment varibales for both the * and the spaces, specific to the first * and the first spaces.
					starStart = 1;
					starEnd = row;
					starInc = 1;
					spaceStart = 1;
					spaceEnd = rowWidth - row + 1;
					spaceInc = 1;		
					break;
				case 2: // Sets start, end, & increment varibales for both the * and the spaces, specific to the second * and the second spaces.
					starStart = 1;
					starEnd = rowWidth - row + 1;
					starInc = 1;
					spaceStart = 2;
					spaceEnd = 4 * row;
					spaceInc = 2;	
					break;
				case 3: // Sets start, end, & increment varibales for both the * and the spaces, specific to the third * and the third spaces.
					starStart = 1;
					starEnd = rowWidth - row + 1;
					starInc = 1;
					spaceStart = 1;
					spaceEnd = rowWidth - row + 1;
					spaceInc = 1;	
					break;
				case 4: // Sets start, end, & increment varibales for the last *.  No spaces this round.
					starStart = 1;
					starEnd = row;
					starInc = 1;
					break;

				} // Variable Reset for each loop

				for(int i = starStart;i <= starEnd;) // Loop that creates the *.  
				{
					output += ("*");
				
					i += starInc;
				
				} // End star loop
			
				if(loop != 4) // If not the 4th loop
				{
					for(int j = spaceStart;j <= spaceEnd;) // Loop that creates the spaces.
					{
						output += (" ");
				
						j += spaceInc;
				
					} // End space loop
				}
			} // Creation Loop
			
			output += ("\n");	// Switch to next row once current row is complete.
			
		} // Row Loop
		
		outputArea.setText( output );
		JOptionPane.showMessageDialog( null, scroller,
		"The Star Probelm.....", JOptionPane.INFORMATION_MESSAGE );
		System.exit( 0 );
		
	} // Main Loop
}
