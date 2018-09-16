
public class sphere extends threeDimensionalShape
{
	private double radius;
	
	public sphere(double r)
	{
		radius = r;
	}
	
	public double getArea()
	{
		return (4 * Math.PI * radius * radius);
	}
	
	public double getVolume()
	{
		return (4.0 / 3.0 * Math.PI * radius * radius * radius);
	}
}
