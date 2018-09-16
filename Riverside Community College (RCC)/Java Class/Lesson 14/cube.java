
public class cube extends threeDimensionalShape
{
	private double side;
	
	public cube(double s)
	{
		side = s;
	}
	
	public double getArea()
	{
		return (side * side * 6);
	}
	
	public double getVolume()
	{
		return (side * side * side);
	}
}
