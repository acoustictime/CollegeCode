// James Small

// Ch4_Ex8_Small

// 3-18-06

// This program mimics a calculator.  It prompts for two integers and 
// an operator.  It uses these integers and operator to produce a result.  

#include <iostream>

using namespace std;

int main()
{
	
	int   num1, num2, result;
	char  calctype;					

	cout << "Enter two integers: ";					
	cin >>  num1 >> num2;								
	cout << endl;		

	cout << "Enter operator: + <addition>, - <subtraction>, * <multiplication>, / <division>: ";						
	cin >> calctype;							
	cout << endl;

	switch (calctype)
	{
	
	case '+': result = num1 + num2;
		cout << num1 << " " << calctype << " " << num2 << " " << "=" << " " << result << endl;
		break;
	
	case '-': result = num1 - num2;
		cout << num1 << " " << calctype << " " << num2 << " " << "=" << " " << result << endl;
		break;

	case '*': result = num1 * num2;
		cout << num1 << " " << calctype << " " << num2 << " " << "=" << " " << result << endl;
		break;

	case '/': 
		if (num2 == 0)
		{	cout << num1 << " " << calctype << " " << num2 << " " << "=" << " " << "Can't Divide By Zero" << endl;
			break;
		}
		else 
		{	result = num1 / num2;
			cout << num1 << " " << calctype << " " << num2 << " " << "=" << " " << result << endl;
		}

		break;
	
	default: cout << num1 << " " << calctype << " " << num2 << " " << "=" << " " << "Illegal Operation" << endl;

}
	return 0;
}
