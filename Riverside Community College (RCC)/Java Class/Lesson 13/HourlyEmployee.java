
public class HourlyEmployee extends Employee
{
	private double wage;
	private double hours;
	
	public HourlyEmployee(String f, String l, int s, double w, double h) 
	{
		super(f, l, s);
		setWage(w);
		setHours(h);
	}
	
	public void setWage(double w)
	{
		wage = w;
	}
	
	public void setHours(double h)
	{
		hours = h;
	}
	
	public double getWage()
	{
		return wage;
	}
	
	public double getHours()
	{
		return hours;
	}

}
