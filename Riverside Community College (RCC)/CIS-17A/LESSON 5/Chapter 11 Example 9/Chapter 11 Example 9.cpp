// **********************************************************************
// * James Small														*
// * Cis-17a															*
// * 10-4-06															*
// *																	*
// * This program simulates a soda machine. It displays a list of sodas *
// * in the machine. The user then selects which one they want, it then *
// * prompts the user for the amount of money to pay for the drink.  It *
// * then dispenses the soda and starts the process over again.  Once   *
// * the user decides they don't want another drink, it displays the    *
// * amount of drinks dispenses and the total money made.				*
// **********************************************************************

#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

const int size = 5;
const int length = 11;
const int sodaamounts = 20;

struct sodalist // Struct that defines the type of drinks in the machine
	{
		char drinktype[length];
		double price;
		int amount;
	};

void menu();
void getinput(int &choice, sodalist sodas[]);
void moneyentered(int menuchoice, double &totalmoney, sodalist sodas[]);
void sodasubtract(int menuchoice, int &totalsodas, sodalist sodas[]);
void printresults(double totalmoney, int totalsodas, sodalist sodas[]);

int main()
{
	int menuchoice = 0;
	double totalmoney = 0;
	int totalsodas = 0;
	sodalist sodas[size] = {{"Cola", .75, sodaamounts},			// defines an array of structs and initializes it
							{"Root Beer", .75, sodaamounts},
							{"Lemon-Lime", .75, sodaamounts},
							{"Grape Soda", .80, sodaamounts},
							{"Cream Soda", .80, sodaamounts}};

	while (menuchoice != 6) // Loop that controls when the entire thing
	{
		cout << fixed << setprecision(2);
		
		menu();
		getinput(menuchoice, sodas);

		if (menuchoice == 6) // Exits the loop if the menuchoice is 6
		{
			continue;
		}

		moneyentered(menuchoice, totalmoney, sodas);
		sodasubtract(menuchoice, totalsodas, sodas);
	}

	printresults(totalmoney, totalsodas, sodas);

return 0;
}

// **********************************************************************
// * Definition of the function: getinput								*
// * This function takes is it's arguements, the user's drink choice,   *
// * and the soda function.  It then prompts the user for their drink   *
// * choice and confirms it is an acceptable choice, and that their     *
// * choice isn't sold out.  It then passes their choice back with a    *
// * reference parameter.											    *
// **********************************************************************

void getinput(int &choice, sodalist sodas[])
{
	bool good = false; // Used to tell when the user's input is acceptable
	
	while (good == false) // Loops through asking for the user's choice until it's valid
	{
		cout << "\n\n       Your Choice Is: ";
		cin >> choice;
		
		if (choice > 6 || choice < 1) // Loop used to determine the user's input is between 1 and 6
		{
			cout << "\nEnter a choice between 1 and 6\n";
			menu();
			continue;
		}
		
		if (sodas[choice - 1].amount == 0) // Loop used to determine if drink choice is sold out
		{
			cout << "\nThe machine is sold out of " << sodas[choice - 1].drinktype << ", sorry.";
			cout << "\n\nPlease select another drink\n";
			menu();
			continue;
		}
		
		good = true;
	}
}

// **********************************************************************
// * Definition of the function: moneyentered						    *
// * This function takes as it's arguements, the user's menuchoice, a   *
// * reference parameter that stores the total money in the machine, and*
// * the soda array.  It prompts the user for the amount of money to pay*
// * for the drink.  It confirms the amount entered is between 0 and 1, *
// * once the amount is valid.  It then loops through this process until*
// * the amount of money entered is more than the drink costs.  It then *
// * dispenses the drink and if there's change, it displays the amount. *
// **********************************************************************

void moneyentered(int menuchoice, double &totalmoney, sodalist sodas[])
{
	double moneyentered = 0;
	double total = 0;

	cout << endl << sodas[menuchoice - 1].drinktype << " costs " << sodas[menuchoice - 1].price << " cents\n";
	
	while (total < sodas[menuchoice - 1].price) // Loops until money entered is greater than or equal to the purchase price
	{
		cout << "\nPlease enter the amount of money to put into the machine: ";
		cin >> moneyentered;

		while (moneyentered > 1 || moneyentered < 0) // Loops until money entered is between 0 and 1 dollar
		{
			cout << "\nThe amount put into the machine must be between 0 and 1 dollars\n\n";
			cout << "Please enter the amount of money to put into the machine: ";
			cin >> moneyentered;
		}

		total = total + moneyentered;

		if (total < sodas[menuchoice - 1].price) // If the machine still needs more money, it informs the user how much they still owe
		{
			cout << "\nYou still are short " << sodas[menuchoice - 1].price - total << " cents.\n";
		}

	}

	cout << "\nHere's your drink";
	cout << "\n      _____";
	cout << "\n     |     |";
	cout << "\n     |  S  |";
	cout << "\n     |  O  |";
	cout << "\n     |  D  |";
	cout << "\n     |  A  |";
	cout << "\n     |_____|\n";
	
	if (total > sodas[menuchoice - 1].price) // If there is change, it will display the amount
	{
		cout << "\nYou get " << total - sodas[menuchoice - 1].price << " in change.\n";
	}
	
	totalmoney = totalmoney + sodas[menuchoice - 1].price;

	cout << endl;
}

// **********************************************************************
// * Definition of the function: sodasubtract						    *
// * This function takes as it's arguements, the user's menuchoice, and *
// * a reference parameter for the total number of soda's sold, and the *
// * the soda array.  It then increases the total number of sodas sold, *
// * and subtracts one from the remaining sodas availiable for that type*
// **********************************************************************

void sodasubtract(int menuchoice, int &totalsodas, sodalist sodas[])
{
	totalsodas++;
	sodas[menuchoice - 1].amount = sodas[menuchoice - 1].amount - 1;
}

// **********************************************************************
// * Definition of the function: menu								    *
// * This function displays the menu of drinks availiable in the machine*
// **********************************************************************

void menu()
{
	cout << "_______________________________\n";
	cout << "|                             |\n";
	cout << "| *** Make Your Selection *** |\n";
	cout << "|                             |\n";
	cout << "| 1. Cola          .75 cents  |\n";
	cout << "| 2. Root Beer     .75 cents  |\n";
	cout << "| 3. Lemon-Lime    .75 cents  |\n";
	cout << "| 4. Grape Soda    .80 cents  |\n";
	cout << "| 5. Cream Soda    .80 cents  |\n";
	cout << "| 6. Not Thirsty              |\n";
	cout << "|_____________________________|";
}

// **********************************************************************
// * Definition of the function: printresults						    *
// * This function takes as it's arguements, the total amount of money  *
// * put into the machine, the total number of sodas sold, and the soda *
// * array.	It then outputs the amount of each type of soda sold, and   *
// * total number of sodas sold, along with the money made.			    *
// **********************************************************************

void printresults(double totalmoney, int totalsodas, sodalist sodas[])
{
	cout << "\n*** Sodas Sold ***\n\n";
	
	for (int index = 0; index < size; index++) // Loop used to output the amount of each type of soda sold
	{
		cout << left << setw(12) << sodas[index].drinktype << setw(3) << "=" << setw(5) << sodaamounts - sodas[index].amount << endl;
	}
	
	cout << "\nA total of " << totalsodas << " sodas were bought totaling " << totalmoney;
	
	if (totalmoney >= 1) // Loop used to determine if the total amount of money put into the machine is less than or greater than a dollar
	{
		cout << " dollars.\n\n";
	}
	else
	{
		cout << " cents.\n\n";
	}
}