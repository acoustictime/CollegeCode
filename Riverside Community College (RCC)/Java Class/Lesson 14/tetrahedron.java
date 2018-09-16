
public class tetrahedron extends threeDimensionalShape
{
	private double edge;
	
	public tetrahedron(double e)
	{
		edge = e;
	}
	
	public double getArea()
	{
		return (edge * edge * Math.sqrt(3.0));
	}
	
	public double getVolume()
	{
		return (edge * edge * edge * Math.sqrt(2.0) / 12.0);
	}
}
