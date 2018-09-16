
public class square extends twoDimensionalShape
{
	double side;
	
	public square(double s)
	{
		side = s;
	}
	
	public double getArea()
	{
		return (side * side);
	}

	@Override
	public double getVolume() {
		return 0;
	}
}
