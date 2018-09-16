
public class Employee 
{
	private String firstName;
	private String lastName;
	private double social;
	
	public Employee(String f,String l, double s)
	{
		setFirstName(f);
		setLastName(l);
		setSocial(s);
	}
	
	public void setFirstName(String f)
	{
		firstName = f;
	}
	
	public void setLastName(String l)
	{
		lastName = l;
	}
	
	public void setSocial(double s)
	{
		social = s;
	}
	
	public String getFirstName()
	{
		return firstName;
	}
	
	public String getLastName()
	{
		return lastName;
	}
	
	public double getSocial()
	{
		return social;
	}
	
}
