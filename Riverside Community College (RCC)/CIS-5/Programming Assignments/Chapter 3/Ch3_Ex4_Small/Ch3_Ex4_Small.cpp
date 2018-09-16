// James Small

// Ch3_Ex4_Small

// 3-10-06

// This program prompts the user for the assessed value of the property.
// It then outputs the assessed value, along with the taxable amount
// and the property tax amount to a file.

#include <iostream>
#include <iomanip>
#include <fstream>


using namespace std;

int main()
{

	ofstream outfile;
	
	double assessedvalue;
	double taxableamount;
	double propertytax;
	double taxrate = 1.05;

	outfile.open("Ch3_Ex4_Small.out");
	
	outfile << fixed << showpoint << setprecision(2);
	
	cout << "Enter Assessed Value: " << flush;
	cin >> assessedvalue;
	cout << endl;

	taxableamount = assessedvalue * .92;
	propertytax = taxableamount / 100 * taxrate;

	outfile << left << setw(30) << "Assessed Value: " << right << setw(9) << assessedvalue << endl;
	outfile << left << setw(30) << "Taxable Amount: " << right << setw(9) << taxableamount << endl;
	outfile << left << setw(30) << "Tax Rate for each $100.00: " << right << setw(9) << taxrate << endl;
	outfile << left << setw(30) << "Property Tax: " << right << setw(9) << propertytax << endl;

    outfile.close();


	return 0;

}