// ******************************************************************************
// * James Small																*
// * Cis-17a																	*
// * 9-7-06																		*
// *																			*
// * This program takes as it's input a wavelength in exponential form, 1e-10   *
// * and outputs the where the wavelength lands on the electromagnetic spectrum *
// ******************************************************************************


#include <iostream>

using namespace std;

int main()
{
	double wavelength = 0;

	cout << "What is the wavelength of the electromagnetic wave" << endl;
	cout << "(Type the wavelength in the following format: 1e-10" << endl;
	cin >> wavelength;

	if (wavelength >= 1E-2)
		cout << "This is a Radio Wave";
	else if (wavelength >= 1E-3 && wavelength < 1E-2)
		cout << "This is a Microwave";
	else if (wavelength >= 7E-7 && wavelength < 1E-3)
		cout << "This is an Infared Wave";
	else if (wavelength >= 4E-7 && wavelength < 7E-7)
		cout << "This is Visible Light";
	else if (wavelength >= 1E-8 && wavelength < 4E-7)
		cout << "This is an UltraViolet Wave";
	else if (wavelength >= 1E-11 && wavelength < 1E-8)
		cout << "This is a X-Ray Wave";
	if (wavelength < 1E-11)
		cout << "This is a Gamma Ray Wave";

	cout << endl;
	
return 0;
}
