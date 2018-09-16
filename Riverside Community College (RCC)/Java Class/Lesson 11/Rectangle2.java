/*
 8.9 Create a more sophisticated Rectangle class than the one you created in Exercise 8.8. (This problem 
is 8.14 in the sixth edition)   This class stores only the Cartesian coordinates of the four corners of 
the rectangle. The constructor calls a set method that accepts four sets of coordinates and verifies that 
each of these is in the first quadrant with no single x- or y-coordinate larger than 20.0. The set method 
also verifies that the supplied coordinates do, in fact, specify a rectangle. Provide methods to calculate 
the length, width, perimeter and area. The length is the larger of the two dimensions. Include a predicate 
method isSquare which determines if the rectangle is a square.
 */
 
public class Rectangle2 
{
	private int x1;
	private int y1;
	private int x2;
	private int y2;
	private int x3;
	private int y3;
	private int x4;
	private int y4;
	
	
	public Rectangle2(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
	{	
		if(setPoints(x1,x2,x3,x4,y1,y2,y3,y4))
		{
			this.x1 = x1;
			this.x2 = x2;
			this.x3 = x3;
			this.x4 = x4;
			this.y1 = y1;
			this.y2 = y2;
			this.y3 = y3;
			this.y4 = y4;	
		}
		else
		{
			this.x1 = 1;
			this.x2 = 1;
			this.x3 = 2;
			this.x4 = 2;
			this.y1 = 2;
			this.y2 = 1;
			this.y3 = 2;
			this.y4 = 1;	
			
			System.out.print("The coordinates entered do not form a rectangle.  Default values used.\n");
		}
	}
	
	public boolean setPoints(int x1,int x2,int x3,int x4,int y1,int y2,int y3,int y4)
	{
		if(x1 == x2 && x3 == x4 && y1 == y3 && y2 == y4 && range(x1) == true && range(x2) == true 
				&& range(x3) == true && range(x4) == true && range(y1) == true && range(y2) == true && 
				range(y3) == true && range(y4) == true)
			return true;
		else
			return false;
	}
	
	public int getLength()
	{
		if((x3 - x1) > (y1 - y2))
			return (x3 - x1);
		else
			return (y1 - y2);	
	}
	
	public int getWidth()
	{
		if((x3 - x1) > (y1 - y2))
			return (y1 - y2);
		else
			return (x3 - x1);	
	}
	
	public int getArea()
	{
		return ((x3 - x1) * (y1 - y2));
	}
	
	public int getPerimeter()
	{
		return (((x3 - x1) * 2) + ((y1 - y2) * 2));
	}
	
	public boolean isSquare()
	{
		if(x3 - x1 == y1 - y2)
			return true;
		else 
			return false;
	}
	
	public boolean range(int i)
	{
		if(i >= 1 && i <= 20)
			return true;
		else
			return false;	
	}
	
	
}
