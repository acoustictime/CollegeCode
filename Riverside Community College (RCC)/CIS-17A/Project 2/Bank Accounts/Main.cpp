// **********************************************************************
// * James Small														*
// * Cis-17a															*
// * 12-8-06															*
// *																	*
// * This program simulates a bank account.  You have a savings and     *
// * checking account.  You can withdraw, deposit, and transfer from the*
// * accounts.  The account information is aved in a file and can be    *
// * called back later on to continue.									*
// **********************************************************************

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include "Checking.h"
#include "Savings.h"
#include "Menu.h"

using namespace std;

Menu menu; // Menu object
const int openingbalance = 100; // int for minimum opening balance

void menu1(Checking *check, Savings *save);
void menu2(Checking *check, Savings *save);
void menu3(Checking *check, Savings *save);
void menu4(Checking *check, Savings *save);
void menu5(Checking *check, Savings *save);
void menu6(Checking *check, Savings *save);
bool validbalance(double balance);
int getN();

int main(int argv,char *argc[])
{
	double savebalance;
	double checkbalance;
	char lname[namesize];
	char fname[namesize];
	int checkacctnum;
	int saveacctnum;
	int acctstatus;
	int deposits;
	int withdraws;
	double withtotal;
	double deptotal;
	double interestearned;
	int months;
	double serviceCharges;
	int transactions;
	int inN;
	Checking *check;
	Savings *save;
	fstream savesave;
	fstream checksave;

	cout << fixed << setprecision(2);

	menu.newaccount(); // Displays the new account menu
	inN = getN();

	while (inN > 2 || inN < 1) // Gets user input
	{
		system("cls");
		menu.newaccount();
		inN = getN();
	}

	if (inN == 1) // Used if you already have an account
	{
		check = new Checking(); // Dynamic Checking object
		save = new Savings(); // Dynamic Savings object

		savesave.open("savings.txt", ios::in); // Opens savings file and reads in values to temp variables
		savesave >> lname;
		savesave >> fname;
		savesave >> saveacctnum;
		savesave >> acctstatus;
		savesave >> savebalance;
		savesave >> deposits;
		savesave >> deptotal;
		savesave >> interestearned;
		savesave >> months;
		savesave >> serviceCharges;
		savesave >> withdraws;
		savesave >> withtotal;
		savesave >> transactions;

		save->getlname(lname);
		save->getfname(fname);
		save->getacctnum(saveacctnum);
		
		if(acctstatus == 1) // Converts 1 to true
		{
			save->getacctstatus(true);
		}
		else if (acctstatus == 2) // Converts 0 to false
		{
			save->getacctstatus(false);
		}
		
		save->getacctbalance(savebalance);// Sets the class member variables to the temp values
		save->getdeposits(deposits);
		save->getdeptotal(deptotal);
		save->getinterest(interestearned);
		save->getmonths(months);
		save->getscharges(serviceCharges);
		save->getwith(withdraws);
		save->getwithtotal(withtotal);
		save->gettrans(transactions);

		savesave.close();

		checksave.open("checking.txt", ios::in); // Opens checking file and reads values to temp variables
	
		checksave >> lname;
		checksave >> fname;
		checksave >> checkacctnum;
		checksave >> acctstatus;
		checksave >> checkbalance;
		checksave >> deposits;
		checksave >> deptotal;
		checksave >> interestearned;
		checksave >> months;
		checksave >> serviceCharges;
		checksave >> withdraws;
		checksave >> withtotal;
		checksave >> transactions;

		check->getlname(lname);
		check->getfname(fname);
		check->getacctnum(checkacctnum);
		
		if(acctstatus == 1) // Converts 1 to true
		{
			check->getacctstatus(true);
		}
		else if (acctstatus == 2) // Converts 0 to false
		{
			check->getacctstatus(false);
		}
		
		check->getacctbalance(checkbalance);
		check->getdeposits(deposits);
		check->getdeptotal(deptotal);
		check->getinterest(interestearned);
		check->getmonths(months);
		check->getscharges(serviceCharges);
		check->getwith(withdraws);
		check->getwithtotal(withtotal);
		check->gettrans(transactions);
	
		checksave.close();

	}
	else if (inN == 2) // Used if you don't have an account
	{
		system("cls");
		cout << "What is your Last Name: ";
		cin.ignore();
		cin.getline(lname, namesize); // Gets last name

		while (strlen(lname) == 0) // Loops until you enter something for your name
		{
			cout << "\nPlease enter a valid last name: ";
			cin.getline(lname, namesize);
			cout << endl;
		}
		
		cout << "\nWhat is your First Name: ";
		cin.getline(fname, namesize); // Gets first name

		while (strlen(fname) == 0) // Loops until you enter something for your name
		{
			cout << "\nPlease enter a valid first name: ";
			cin.getline(fname, namesize);
			cout << endl;
		}
	
		system("cls");
		
		cout << "What do you want your checking account number to be: ";
		cin >> checkacctnum; // Gets checking account number

		while (checkacctnum < 1000) // Loops until checking account number is 5 digits
		{
			cout << "\nYour account number must be at least 5 digits.";
			cout << "\n\nWhat do you want your checking account number to be: ";
			cin >> checkacctnum;
		}

		cout << "\nPlease enter the checking account opening balance: ";
		cin >> checkbalance; // Gets checking opening balance
	
		while (!validbalance(checkbalance)) // Loops until balance is greater than 100
		{
			cout << "\nYour opening balance must be at least " << openingbalance;
			cout << "\n\nPlease enter the savings account opening balance: ";
			cin >> checkbalance;
		}

		system("cls");
		
		cout << "What do you want your savings account number to be: ";
		cin >> saveacctnum; // Gets savings account number

		while (saveacctnum < 1000) // Loops until savings account number is at least 5 digits
		{
			cout << "\nYour account number must be at least 5 digits.";
			cout << "\n\nWhat do you want your save account number to be: ";
			cin >> saveacctnum;
		}

		cout << "\nPlease enter the savings account opening balance: ";
		cin >> savebalance; // Get savings account balance
	
		while (!validbalance(savebalance)) // Loops until balance is at least 100
		{
			cout << "\nYour opening balance must be at least " << openingbalance;
			cout << "\n\nPlease enter the savings account opening balance: ";
			cin >> savebalance;
		}

		check = new Checking(checkbalance, lname, fname, checkacctnum); // Dynamic checking object
		save = new Savings(savebalance, lname, fname, saveacctnum); // Dynamic savings object
	}
	
    do{ // Main menu loop
		system("cls");
	    menu.mainmenu(); // Displays main menu
        inN = getN(); // Gets input
        
		switch(inN){ // Switch for menu selection
        case 1:    menu1(check, save);break; // Calls menu1 function
       	case 2:    menu2(check,save);break;  // Calls menu2 function
        case 3:    menu3(check, save);break; // Calls menu3 function
        case 4:    menu4(check, save);break; // Calls menu4 function
		case 5:	   menu5(check, save); break;   // Calls menu5 function
		case 6:	   menu6(check, save); return 1;break;   // Calls menu6 function
        default:   ;}
        }while(inN<6);
return 1;
}

// **********************************************************************
// * Definition of the function: getN								    *
// * This function gets the users' input							    *
// **********************************************************************

int getN()
{
	int inN;
	cin>>inN;
return inN;
}

// **********************************************************************
// * Definition of the function: menu1								    *
// * This function takes as it's arguements, a pointer to the Checking  *
// * and savings objects.  It then displays a menu and allows you to    *
// * withdraw money from either accounts.							    *
// **********************************************************************

void menu1(Checking *check, Savings *save)
{
	system("cls");
	int inN;
	double amount;
	
	do{ // Loops for withdraw menu
	system("cls");
	menu.withdraw(); // Displays withdraw menu
	inN = getN(); // Gets input
	
	switch(inN){ // Switch for withdraw menu
	case 1: // If select checking
	{
		if (check->status()) // Used if the account status is active
		{
		
			system("cls");
			cout << "How much would you like to withdraw?";
			cout << "\n\nYour current balance is $" << check->getbalance();
			cout << "\n\nPlease select an amount greater than 0 but less than " << check->getbalance();
			cout << "\n\nAmount: ";
			cin >> amount;
				
			while (amount < 0) // Loops until valid amount is entered
			{
				cout << "\nYou entered an invalid amount, please enter a new amount";
				cout << "\n\nAmount: ";
				cin >> amount;
			}

			check->WithDraw(amount); // Passes amount to checking withdraw function
		}
		else // Used if account status is inactive
		{
			system("cls");
			cout << "Your checking account is inactive right now";
			cout << "\n\nPlease make a deposit to bring your balance up\n\n";
			system("pause");
		}

	};break;
	
	case 2: // If savings is selected
	{
		if (save->status()) // Used if account status is active
		{
			system("cls");
			cout << "How much would you like to withdraw?";
			cout << "\n\nYour current balance is $" << save->getbalance();
			cout << "\n\nPlease select an amount greater than 0 but less than " << save->getbalance();
			cout << "\n\nAmount: ";
			cin >> amount;

			while (amount < 0) // Loops until amount entered is valid
			{
				cout << "\nYou entered an invalid amount, please enter a new amount";
				cout << "\n\nAmount: ";
				cin >> amount;
			}

			save->WithDraw(amount); // Passes amount to savings withdraw function
		}
		else // Used if account is inactive
		{
			system("cls");
			cout << "Your savings account is inactive right now";
			cout << "\n\nPlease make a deposit to bring your balance up\n\n";
			system("pause");
		}
				  
	};break;
          
	case 3:{};break;
          
	default: inN = 1;}
	}while(inN<3);
}

// **********************************************************************
// * Definition of the function: menu2								    *
// * This function takes as its arguements a pointer to the checking and*
// * savings objects.  It then asks you to select which account you want*
// * deposit money into.											    *
// **********************************************************************

void menu2(Checking *check, Savings *save)
{
	system("cls");
	int inN;
	double amount;
	
	do{ // Deposit menu loop
	system("cls");
	menu.deposit(); // Displays deposit menu
	inN = getN(); // Gets input

	switch(inN){ // Deposit switch
	case 1: // If checking
	{
		system("cls");
		cout << "How much would you like to deposit?";
		cout << "\n\nYour current balance is $" << check->getbalance();
		cout << "\n\nPlease select an amount greater than 0";
		cout << "\n\nAmount: ";
		cin >> amount;
		
		while (amount < 0) // Loops until valid amount entered
		{
			cout << "\nYou entered an invalid amount, please enter a new amount";
			cout << "\n\nAmount: ";
			cin >> amount;
		}

		check->Deposit(amount); // Passes amount ot checking deposit function
				  
	};break;

	case 2: // If savings
	{
	  	system("cls");
		cout << "How much would you like to deposit?";
		cout << "\n\nYour current balance is $" << save->getbalance();
		cout << "\n\nPlease select an amount greater than 0";
		cout << "\n\nAmount: ";
		cin >> amount;
				
		while (amount < 0) // Loops until valid amount entered
		{
			cout << "\nYou entered an invalid amount, please enter a new amount";
			cout << "\n\nAmount: ";
			cin >> amount;
		}

		save->Deposit(amount); // Passes amount to savings deposit function
				  
	};break;

	case 3:{};break;
    
	default: inN = 1;}
    }while(inN<3);
}

// **********************************************************************
// * Definition of the function: menu3								    *
// * This function takes as it's agruements a pointer to the checking   *
// * and savings objects.  It then allows you to transfer from one      *
// * account to another.											    *
// **********************************************************************

void menu3(Checking *check, Savings *save)
{
	system("cls");
	int inN;
	double amount;
	
	do{ // Transfer loop
	system("cls");
	menu.transfer(); // Transfer menu
	inN = getN(); // Gets input

	switch(inN){ // Transfer loop

	case 1: // For checking to savings
	{
		if (check->status()) // Used if account status is active
		{
		
			system("cls");
				
			cout << "How much money would you like to transfer? ";
			cout << "\n\nYou have $" << check->getbalance() << " in your checking.";
			cout << "\n\nYou have $" << save->getbalance() << " in your savings. ";
			cout << "\n\nPlease select an amount greater than 0 but less than " << check->getbalance();
			cout << "\n\nAmount: ";
			cin >> amount;

			while (amount < 0) // Loops until amount entered is valid
			{
				cout << "\nYou entered an invalid amount, please enter a new amount";
				cout << "\n\nAmount: ";
				cin >> amount;
			}

			check->WithDraw(amount); // Withdraws from checking
			save->Deposit(amount); // Deposits to savings
		}
		else // Used if account is inactive
		{

			system("cls");
			cout << "Your checking account is inactive right now";
			cout << "\n\nPlease make a deposit to bring your balance up\n\n";
			system("pause");
		}
								  
	};break;

	case 2: // From savings to checking
	{
		if(save->status()) // Used if savings account is active
		{
		
			system("cls");
					
			cout << "How much money would you like to transfer? ";
			cout << "\n\nYou have $" << save->getbalance() << " in your savings.";
			cout << "\nYou have $" << check->getbalance() << " in your checking. ";
			cout << "\nPlease select an amount greater than 0 but less than " << save->getbalance();
			cout << "\n\nAmount: ";
			cin >> amount;

			while (amount < 0) // Loops until amount entered is valid
			{
				cout << "\n\nYou entered an invalid amount, please enter a new amount";
				cout << "\n\nAmount: ";
				cin >> amount;
			}

			check->Deposit(amount); // Deposits from checking
			save->WithDraw(amount); // Withdraws from savings
		}
		else // Used if account is inactive
		{
			system("cls");
			cout << "Your savings account is inactive right now";
			cout << "\n\nPlease make a deposit to bring your balance up\n\n";
			system("pause");
		}
				  
	};break;
	
	case 3:{};break;
	default: inN = 1;}
	}while(inN<3);
}

// **********************************************************************
// * Definition of the function: menu4								    *
// * This function takes as it's arguements a pointer to the checking   *
// * and savings object.  It then allows you to run the end of the month*
// * processes.														    *
// **********************************************************************

void menu4(Checking *check, Savings *save)
{
	system("cls");
	int inN;
	
	do{ // Month end loop
	system ("cls");
	menu.endmonth(); // Displays month end menu
	inN = getN(); // Gets input

	switch(inN){ // Month end switch
 
	case 1: // Month end proces
	{
		check->monthlyProc(); // Runs checking month end
		save->monthlyProc(); // Runs savings month end
		inN = 2;
	};break;

	case 2:{};break;

	default: inN = 1;}
	}while(inN<2);
}

// **********************************************************************
// * Definition of the function: menu5								    *
// * This function takes as it's arguements a pointer to the checking   *
// * and savings objects.  It will then display the transactions for    *
// * the account you select.										    *
// **********************************************************************

void menu5(Checking *check, Savings *save)
{
	system("cls");
	int inN;
	
	do{ // Transactions loop
	system ("cls");
	menu.transactions(); // Transactions menu
	inN = getN(); // Gets input

	switch(inN){ // Transactions switch
	
	case 1: // View checking transactions
	{
		check->transactions();			  
	};break;

	case 2: // View savings transactions
	{
	 save->transactions();
	};break;

	case 3:{}break;

    default: inN = 1;}
	}while(inN<3);
}

// **********************************************************************
// * Definition of the function: menu6								    *
// * This function takes as it's arguements a pointer to the checking   *
// * and savings objects.  It then calls the savings and checking save  *
// * file functions.  Lastly deletes the check and save objects.	    *
// **********************************************************************

void menu6(Checking *check, Savings *save)
{
	save->savefile();
	check->savefile();

	delete check; // Deletes check object
	delete save; // Deletes save object

}


// **********************************************************************
// * Definition of the function: validbalance						    *
// * This function takes as it's arguements a double for the balance.   *
// * It then returns true if the balance is greater than the opening    *
// * balance.														    *
// **********************************************************************

bool validbalance(double balance)
{
	bool status;

	if (balance < openingbalance) // If amount entered is greater than opening balance
	{
		status = false;
	}
	else // If amount entered is less than the opening balance
	{
		status = true;
	}
return status;
}
