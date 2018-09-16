
public class BasePlusCommissionEmployee extends CommissionEmployee 
{
	private double baseSalary;
	
	public BasePlusCommissionEmployee(String f, String l, int s, double gs,int cr, double bs) 
	{
		super(f, l, s, gs, cr);
		setBaseSalary(bs);
	}

	public void setBaseSalary(double bs)
	{
		baseSalary = bs;
	}
	
	public double getBaseSalary()
	{
		return baseSalary;
	}
	
}
