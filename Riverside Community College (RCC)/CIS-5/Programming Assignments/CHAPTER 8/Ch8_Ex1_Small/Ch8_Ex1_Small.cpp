// James Small

// Ch8_Ex1_Small

// 4-22-06

// This program prompts a user for 3 sides of a triangle and outputs
// the type of triangle: scalene, isosceles, equilateral, or notriangle.

#include <iostream>

using namespace std;

enum triangletype {scalene, isosceles, equilateral, notriangle};

triangletype triangleShape(int side1, int side2, int side3);
void printEnum(triangletype shape);

int main()
{

	int side1, side2, side3;

	cout << "Enter the lengths of three sides of a triangle" << endl;
	cin >> side1 >> side2 >> side3;
	cout << endl;
	cout << "The shape of the triangle is: ";
	printEnum(triangleShape(side1, side2, side3));
	cout << endl;
	
return 0;
}

triangletype triangleShape(int side1, int side2, int side3)
{
	triangletype shape;

	if(side1 == side2 && side2 == side3 && side1 == side3)
	{
		shape = equilateral;
	}
	else if (side1 + side2 < side3 || side2 + side3 < side1 || side1 + side3 < side2)
	{
		shape = notriangle;
	}
	else if (side1 == side2 || side2 == side3 || side1 == side3)
	{
		shape = isosceles;
	}
	else if (side1 != side2 && side2 != side3 && side1 != side3)
	{
		shape = scalene;
	}

	return shape;
}

void printEnum(triangletype shape)
{
	switch (shape)
	{
	case scalene: cout << "scalene";
		break;
	case isosceles: cout << "isosceles" << endl;
		break;
	case equilateral: cout << "equilateral" << endl;
		break;
	case notriangle: cout << "notriangle" << endl;
		break;
	}
}