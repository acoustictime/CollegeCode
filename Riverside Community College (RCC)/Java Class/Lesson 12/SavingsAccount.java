
public class SavingsAccount 
{
	private double savingsBalance = 0;
	private static double annualInterestRate = 0;
	
	public SavingsAccount(double balance)
	{
		setBalance(balance);
	}
	
	public void calculateMonthlyInterest()
	{
		savingsBalance += (savingsBalance * (annualInterestRate / 100.00) / 12.0);
	}
	
	public static void modifyInterestRate(double rate)
	{
		annualInterestRate = rate;
	}
	
	public void setBalance(double balance)
	{
		if (balance <  0)
			savingsBalance = 0;
		else
			savingsBalance = balance;	
	}
	
	public double getBalance()
	{
		return savingsBalance;
	}
	
	public double getInterestRate()
	{
		return annualInterestRate;
	}
}
