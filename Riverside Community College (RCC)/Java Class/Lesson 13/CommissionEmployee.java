
public class CommissionEmployee extends Employee
{
	private int commissionRate;
	private double grossSales;
	
	public CommissionEmployee(String f, String l, int s, double gs, int cr) 
	{
		super(f, l, s);
		setCommissionRate(cr);
		setGrossSales(gs);
	}
	
	public void setCommissionRate(int cr)
	{
		commissionRate = cr;
	}
	
	public void setGrossSales(double gs)
	{
		grossSales = gs;
	}
	
	public int getCommissionRate()
	{
		return commissionRate;
	}
	
	public double getGrossSales()
	{
		return grossSales;
	}

}
