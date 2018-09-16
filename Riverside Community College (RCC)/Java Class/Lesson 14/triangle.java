
public class triangle extends twoDimensionalShape
{
	double base;
	double height;
	
	public triangle(double b, double h)
	{
		base = b;
		height = h;
	}
	
	public double getArea()
	{
		return (.5 * base * height);
	}

	@Override
	public double getVolume() {
		return 0;
	}
}
