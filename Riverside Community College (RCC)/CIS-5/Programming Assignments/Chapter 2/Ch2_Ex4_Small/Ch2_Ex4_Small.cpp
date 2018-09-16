// James Small

// Ch2_Ex4_Small

// 3-4-06

// This program prompts for the length and
// width of a rectangle and converts uses
// it to display the area and perimeter of
// the rectangle.


#include <iostream>

using namespace std;

int main ()
{

	double width;
	double length;
	double perimiter;
	double area;

	cout << "Enter Lengh, Width of the Rectangle ";
	cin >> length >> width;
	cout << endl;
	
	perimiter = 2 * width + 2 * length;
	area = length * width;

	cout << "Area: " << area << endl;
	cout << "Perimiter: " << perimiter << endl;	

    return 0;

}

		 

