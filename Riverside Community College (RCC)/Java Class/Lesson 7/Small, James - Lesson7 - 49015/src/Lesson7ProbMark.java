
/*
 5.Mark Write an application that prints a table of the binary, 
 octal, and hexadecimal equivalents of the decimal numbers in 
 the range 1 through 256. If you are not familiar with these 
 number systems, read Appendix E, first. 
 
 			James Small
 			Lesson 7
 			Problem Mark
 */
import javax.swing.JOptionPane;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;

public class Lesson7ProbMark 
{
	public static void main(String args[])
	{
		JTextArea outputArea = new JTextArea( 50, 35 );
		JScrollPane scroller = new JScrollPane( outputArea );
		String output = "";
		
		//Declare and initialize variables.  
		int current;
		String temp = "";
		String actual = "";
		boolean done = false; // Used to determine if current value is calculated fully
		
		output += ("Dec\tOct\tHex\tBin\n\n"); // Output header
		
		for(int i = 1;i <= 256; i++) // main loop to control all decimals
		{
			output += (i + "\t"); // Output current decimal value.
			
			current = i; // Set to current decmial every loop
			
			while (!done) // Loop to calculate Octal values.  Values are calculted backwards, so I have to reverse them as I go.
			{
				if (current / 8 == 0) // Used to exit while loop if full value has been calculated.
					done = true;	
			
				temp = actual; // Set current value as a temp
				actual = Integer.toString(current % 8); // Calculate new integer and store as current value.
				current /= 8;		// Calculate new current value.
				actual = actual.concat(temp);		//Concatinate current value with new value at the end.
			} // end oct loop
			
			output += (actual + "\t"); // Output result
			
			// Reset variables for hex loop
			done = false;
			actual = "";
			temp = "";	
			current = i;
			
			while (!done) // Loop to calculate Hexidecimal values.  Values are calculted backwards, so I have to reverse them as I go.
			{
				int j = 0; // Used for swith below
				
				if (current / 16 == 0) // Used to exit while loop if full value has been calculated.
					done = true;	
			
				temp = actual; // Set current value as a temp
				j = current % 16; // Calculate new integer and store as current value for switch below
				
				if (j > 9) // If value 10 and above, determine letter value
				{	
					switch (j) // Letter value switch
					{
						case 10:
							actual = "A";
							break;
						case 11:
							actual = "B";
							break;	
						case 12:
							actual = "C";
							break;
						case 13:
							actual = "D";
							break;
						case 14:
							actual = "E";
							break;	
						case 15:
							actual = "F";
							break;
					}
				}
				else
				{
						actual = Integer.toString(j); // Calculate new integer and store as current value.
				}
			
				current /= 16;		 // Calculate new current value.
				actual = actual.concat(temp);	//Concatinate current value with new value at the end.	
			} // End hex loop
			
			output += (actual + "\t"); // Output result
			
			// Reset variables for bin loop
			done = false;
			actual = "";
			temp = "";
			current = i;
			
			while (!done) // Loop to calculate binary values.  Values are calculted backwards, so I have to reverse them as I go.
			{
				if (current / 2 == 0) // Used to exit while loop if full value has been calculated.
					done = true;	
			
				temp = actual; // Set current value as a temp
				actual = Integer.toString(current % 2);
				current /= 2;		 // Calculate new current value.
				actual = actual.concat(temp);		//Concatinate current value with new value at the end.
			} // end bin loop
			
			output += (actual + "\n"); // Output result
			
			// Reset variables for oct loop above
			done = false;
			actual = "";
			temp = "";				
		}
		
		outputArea.setText( output );
		JOptionPane.showMessageDialog( null, scroller,
				"Decimal, Octal, Hexidecimal, Binary Numbers Through 256", JOptionPane.INFORMATION_MESSAGE );
		System.exit( 0 );
	}
}
