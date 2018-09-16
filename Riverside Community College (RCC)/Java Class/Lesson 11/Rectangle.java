/*
 8.8 Create a class Rectangle. (6th edition, this is 8.4)  The class has attributes length and width, 
each of which defaults to 1. It has methods that calculate the perimeter and the area of the rectangle. 
It has set and get methods for both length and width. The set methods should verify that length and 
width are each floating-point numbers larger than 0.0 and less than 20.0.
 */

public class Rectangle 
{
	private float length;
	private float width;

	public Rectangle(float length, float width)
	{
		setLength(length);
		setWidth(width);
	}
	
	public float checkLength(float length)
	{
		if(length < 0.0 || length > 20.0)
		{
			System.out.printf("Length entered %.2f is invalid, defaulting to 1\n",length);
			return 1;
		}
		else
			return length;		
	}
	
	public float checkWidth(float width)
	{
		if(width < 0.0 || width > 20.0)
		{	
			System.out.printf("Width entered %.2f is invalid, defaulting to 1\n",width);
			return 1;
		}
		else
			return width;		
	}
	
	public void setLength(float length)
	{
		this.length = checkLength(length);
	}
	
	public void setWidth(float width)
	{
		this.width = checkWidth(width);
	}
	
	public float getLength()
	{
		return length;
	}
	
	public float getWidth()
	{
		return width;
	}
	
	public float area()
	{
		return length * width;
	}
	
	public float permieter()
	{
		return (length + width) * 2;
	}
}
