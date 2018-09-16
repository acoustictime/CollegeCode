/*
 8.15 Create a Date class with the following capabilities:

a. Output the date in multiple formats such as 

MM/DD/YYYY
June 14, 1992
DDD YYYY

b. Use overloaded constructors to create Date objects initialized 
with dates of the formats in part a). 

8.16 Create class SavingsAccount. Use a static class variable to 
store the annualInterestRate for all of the savers. Each object of 
the class contains a private instance variable savingsBalance 
indicating the amount the saver currently has on deposit. Provide 
method calculateMonthlyInterest to calculate the monthly interest by 
multiplying the savingsBalance by annualInterestRate divided by 12; 
this interest should be added to savingsBalance. Provide a static 
method modifyInterestRate that sets the annualInterestRate to a new 
value. Write a driver program to test class SavingsAccount. Instantiate
two different savingsAccount objects, saver1 and saver2, with balances
of $2000.00 and $3000.00, respectively. Set annualInterestRate to 4%, 
then calculate the monthly  interest and print the new balances for each 
of the savers. Then set the annualInterestRate to 5% and calculate the 
next month’s interest and print the new balances for each of the savers.

8.17 It would be perfectly reasonable for the Time3 class of Fig. 8.7 to 
represent the time internally as the number of seconds since midnight rather 
than the three integer values hour, minute and second. Clients could use the 
same public methods and get the same results. Modify the Time3 class of Fig. 
8.7 to implement the Time3 as the number of seconds since midnight and show 
that there is no visible change to the clients of the class.

 */

import javax.swing.JApplet;
import javax.swing.JOptionPane;
 
public class Lesson12 extends JApplet{

	private static final long serialVersionUID = 101010;

	public void init()
	{	
		// Input system to determine which problem to run
		int inN;
		do{
	         inN=getN();
	         switch(inN)
	         {
	          case 1:    problem1();break;
	          case 2:    problem2();break;
	          case 3:    problem3();break;
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
					"Press 1 for Problem 8.15\n"+
					"Press 2 for Problem 8.16\n"+
					"Press 3 for Problem 8.17\n"+
					"Press 0 To Quit\n");
		}while((Integer.parseInt(choice)) > 3 || (Integer.parseInt(choice)) < 0);
			
		value = Integer.parseInt(choice);
		
		return value;
	}

	public void problem1() // problem 1 method
	{
		//Testing all three constructors using three different DateNew objects
		DateNew d1 = new DateNew(10,12,2002);
		DateNew d2 = new DateNew("March",23,2010);
		DateNew d3 = new DateNew(12,2009);
		
		System.out.printf("Date object d1's output is %s",d1.toString());
		System.out.printf("Date object d2's output is %s\n",d2.toString2());
		System.out.printf("Date object d3's output is %s\n",d3.toString3());	
	} // end problem 1
	
	public void problem2() // problem 2 method
	{
		SavingsAccount saver1 = new SavingsAccount(2000.00);
		SavingsAccount saver2 = new SavingsAccount(3000.00);
		
		SavingsAccount.modifyInterestRate(4.0);
		
		System.out.printf("Saver 1 Beginning Balance = %.2f\n",saver1.getBalance());
		System.out.printf("Saver 2 Beginning Balance = %.2f\n",saver2.getBalance());
		
		System.out.printf("Current Interest Rate is set to %.2f\n",saver1.getInterestRate());
		
		saver1.calculateMonthlyInterest();
		saver2.calculateMonthlyInterest();
		
		System.out.printf("Saver 1 Balance now = %.2f\n",saver1.getBalance());
		System.out.printf("Saver 2 Balance now = %.2f\n",saver2.getBalance());
		
		SavingsAccount.modifyInterestRate(5.0);

		System.out.printf("Current Interest Rate is set to %.2f\n",saver1.getInterestRate());
		
		saver1.calculateMonthlyInterest();
		saver2.calculateMonthlyInterest();
		
		System.out.printf("Saver 1 Balance now = %.2f\n",saver1.getBalance());
		System.out.printf("Saver 2 Balance now = %.2f\n",saver2.getBalance());
	
	} // end problem 2
	
	public void problem3() // problem 3 method
	{
		Time3 t = new Time3(20,5,59);
		
		System.out.printf("Total Seconds = %s\n",t.seconds());
		System.out.printf("Hour = %s\n",t.getHour());
		System.out.printf("Minute = %s\n", t.getMinute());
		System.out.printf("Seconds = %s\n",t.getSecond());
		System.out.printf("Universal = %s",t.toUniversalString());
		System.out.printf("Regular = %s\n",t.toString());
		
		for(int i = 0; i < 7456;i++)
			t.nextSecond();
		
		System.out.print("The time was incremented by 7456 seconds\n\n");
		System.out.printf("Total Seconds = %s\n",t.seconds());
		System.out.printf("Hour = %s\n",t.getHour());
		System.out.printf("Minute = %s\n", t.getMinute());
		System.out.printf("Seconds = %s\n",t.getSecond());
		System.out.printf("Universal = %s",t.toUniversalString());
		System.out.printf("Regular = %s\n",t.toString());
		
	} // end problem 3



}