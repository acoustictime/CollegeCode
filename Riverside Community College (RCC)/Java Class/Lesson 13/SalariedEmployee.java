
public class SalariedEmployee extends Employee
{
	private double weeklySalary;
	
	public SalariedEmployee(String f, String l, int s, double ws) 
	{
		super(f, l, s);
		setWeeklySalary(ws);
	}
	
	public void setWeeklySalary(double ws)
	{
		weeklySalary = ws;
	}

	public double getWeeklySalary()
	{
		return weeklySalary;
	}
}
