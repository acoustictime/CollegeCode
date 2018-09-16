/*
 
Implement the Shape hierarchy shown in Fig. 9.3 . Each TwoDimensionalShape should 
contain method getArea to calculate the area of the two-dimensional shape. Each 
ThreeDimensionalShape should have methods getArea and getVolume to calculate the 
surface area and volume, respectively, of the three-dimensional shape, respectively. 
Create a program that uses an array of Shape references to objects of each concrete 
class in the hierarchy. The program should print the object to which each array 
element refers. Also, in the loop that processes all the shapes in the array, 
determine whether each shape is a TwoDimensionalShape or a ThreeDimensionalShape. 
If a shape is a TwoDimensionalShape, display its area. If a shape is a 
ThreeDimensionalShape, display its area and volume.

			James Small
			Lesson 14
 */


public class Lesson14 
{
	public static void main(String args[])
	{
		Shape shapes[] = new Shape[6];
		circle c = new circle(5.0);
		square s = new square(5.0);
		triangle t = new triangle(5.0,5.0);
		sphere sp = new sphere(5.0);
		cube cu = new cube(5.0);
		tetrahedron te = new tetrahedron(5.0);

		shapes[0] = c;
		shapes[1] = s;
		shapes[2] = t;
		shapes[3] = sp;
		shapes[4] = cu;
		shapes[5] = te;
		
		for (Shape currentShape : shapes)
		{
			if(currentShape instanceof twoDimensionalShape)
			{
				System.out.printf("%s area = %.2f\n\n",currentShape.getClass().getName(),currentShape.getArea());
			}
			
			if(currentShape instanceof threeDimensionalShape)
			{
				System.out.printf("%s surface area = %.2f\n",currentShape.getClass().getName(),currentShape.getArea());
				System.out.printf("%s volume = %.2f\n\n",currentShape.getClass().getName(),currentShape.getArea());
			}
		}
		
		

		
		
	}
}
