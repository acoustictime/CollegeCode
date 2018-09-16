
public class circle extends twoDimensionalShape
{
	private double radius;
	
	public circle(double r)
	{
		radius = r;
	}
	
	public double getArea()
	{
		return (Math.PI * radius * radius);
	}

	@Override
	public double getVolume() {
		return 0;
	}

}
