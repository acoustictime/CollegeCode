// **********************************************************************
// * James Small														*
// * Cis-17a															*
// *																	*
// *																	*
// * This is the midterm program.  It allows the user to run any one of *
// * 6 different programs.												*
// **********************************************************************

#include <iostream>
#include <iomanip>
#include "Problem1.h"
#include "Problem2.h"
#include "Problem4.h"

using namespace std;

struct stats // Struct used for Problem 3
{
	float avg;
	float median;
	int *mode;
	int nModes;
};

stats *avgMedMode(int *, int); // Function used for Problem 3

void Menu();
int getN();
void def(int);
void problem1();
void problem2();
void problem3();
void problem4();
void problem5();
void problem6();

int main(int argv,char *argc[])
{
	int inN;
        do{
         Menu();
         inN=getN();
         switch(inN){
          case 1:    problem1();break;
          case 2:    problem2();break;
          case 3:    problem3();break;
          case 4:    problem4();break;
          case 5:    problem5();break;
          case 6:    problem6();break;
          default:   def(inN);}
        }while(inN<7);
        return 1;
    }
 void Menu()
 {
	cout<<"1. Bank Overdrawn"<<endl;
    cout<<"2. Gross Pay"<<endl;
    cout<<"3. Pointer to structure"<<endl;
    cout<<"4. Encrypt / Decrypt"<<endl;
    cout<<"5. Factorials"<<endl;
    cout<<"6. Conversions"<<endl;
    cout<<"7. Exit\n"<<endl;
    }
    int getN()
    {
           int inN;
		   cin>>inN;
           return inN;
    }
    
	
// **********************************************************************
// * Definition of the function: problem1							    *
// * This function ask the user for an account number and beginning     *
// * account balance.  It stores these values in a struct as a temporary*
// * storage place.  It then passes them to the Problem1 class.  It also*
// * asks for the amount of deposits and checks and loops through until *
// * you're done.  It then displays a monthly statement with the amounts*
// * used through out.													*
// **********************************************************************
	
	void problem1()
    {
		int choice = 0;
		
		struct storage // Struct used for temporary storage of the variables before being passed into the class for perminate storage
		{
			int acctnumber;
			double balance;
			double checks;
			double deposits;
		};

		storage bankaccount;
		Problem1 account; // Problem1 class object
		
		cout << "\nPlease enter your account #: ";
		cin >> bankaccount.acctnumber;

		while (!account.accountupdate((bankaccount.acctnumber))) // Loops until account number is 5 digits
		{
			cout << "\nYour account number must be between 10000 and 99999";
			cout << "\n\nPlease enter your account # ";
			cin >> bankaccount.acctnumber;
		}

		cout << "\nEnter the beginning balance: ";
		cin >> bankaccount.balance;

		while (!account.balanceupdate((bankaccount.balance))) // Loops until balance is at least 0
		{
			cout << "\nYour account balance must be at least 0";
			cout << "\n\nEnter the beginning balance: ";
			cin >> bankaccount.balance;
		}

		do // Loop used to enter check amounts.  When the user is done with checks, they can move on.
		{		
			cout << "\nWhat would you like to do\n\n";
			cout << "1. Enter check amount\n";
			cout << "2. Move on to deposits\n";
			cout << "Your choice is: ";
			cin >> choice;
					
			if (choice == 1) // Used if the menuchoice entered is 1
			{			
				cout << "\nEnter the check amount: ";
				cin >> bankaccount.checks;
			
				while (!account.checksupdate(bankaccount.checks)) // Loop until check value is greater than 0
				{
					cout << "\nThe check amount must be greater than 0";
					cout << "\n\nEnter the check amount: ";
					cin >> bankaccount.checks;
				}
			}
			else if (choice == 2) // Used if user is done with check entering
			{
				continue;
			}
			else // Used if user doesn't select 1 or 2
			{
				choice = 1;
			}
		
		}while (choice == 1); // While checks if menu choice is 1

		do // Loop used to enter deposit amounts.  When the user is done with deposits, they can move on.
		{		
			cout << "\nWhat would you like to do\n\n";
			cout << "1. Enter deposit amount\n";
			cout << "2. View final balance\n";
			cout << "Your choice is: ";
			cin >> choice;
					
			if (choice == 1) // Used if the menuchoice entered is 1
			{			
				cout << "\nEnter the deposit amount: ";
				cin >> bankaccount.deposits;
			
				while (!account.despositsupdate(bankaccount.deposits)) // Loop until deposit value is greater than 0
				{
					cout << "\nThe check amount must be greater than 0";
					cout << "\n\nEnter the deposit amount: ";
					cin >> bankaccount.deposits;
				}
			}
			else if (choice == 2) // Used if user is done with deposit entering
			{
				continue;
			}
			else // Used if user doesn't select 1 or 2
			{
				choice = 1;
			}
		
		}while (choice == 1); // While checks if menu choice is 1


		account.results(); // Displays results

		cout << "***********************************************************\n\n";
	}
    
// **********************************************************************
// * Definition of the function: problem2							    *
// * This function allows the user to determine the gross pay of any    *
// * number of employees.  It asks the user for the amount of employees.*
// * It then asks for the hours worked and their pay rate along with    *
// * their name.  It will then display a check with the employee's name *
// * and gross pay.  The pay, hours, name, and rate are are all passed  *
// * to the Problem2 class and stored until they are displayed by a     *
// * member function of the class.  Pay is calculated as: under 20 hours*
// * is straight time, between 20 and 40 hours is double time, and all  *
// * hours over 40 is triple time.										*
// **********************************************************************
	
	void problem2()
    {
		const int namesize = 20;

		double ratetemp, hourstemp, paytemp;
		int index = 1, choice = 1, times = 0;

		char nametemp[namesize]; // Temp storage for employee name
					
		Problem2 employee;

		cout << "\nEnter the # of employees you would like to enter information for: ";
		cin >> times;

		while (times < 1) // Loops until number of employees is at least 1
		{
			cout << "The amount of employees must be at least 1.\n";
			cout << "Enter the # of employees you would like to enter information for: ";
			cin >> times;
		}
				
		for (index = 0; index < times; index++) // Loops for amount of employees you wish to enter
		{
			cout << "\nEnter employee name for employee number " << index + 1 << ": ";
			cin.ignore(); // Ignores last input
			cin.getline(nametemp, namesize); // Gets employee name

			employee.inputname(nametemp);

			cout << "\nEnter employee number " << index + 1 << "'s hourly rate: ";
			cin >> ratetemp;

			while(!employee.inputrate(ratetemp)) // Loop used to make sure rate is greater than 0
			{
				cout << "\nThe employee's rate must be greater than 0\n";
				cout << "\nEnter employee number " << index + 1 << "'s hourly rate: ";
				cin >> ratetemp;
				cout << endl;
			}

			cout << "Enter employee number " << index + 1 << "'s hours worked: ";
			cin >> hourstemp;

			while(!employee.inputhours(hourstemp)) // Loop used to make sure hours entered is between 0 and 60
			{
				cout << "\nThe amount of hours can't be between 0 and 60\n";
				cout << "\nEnter employee number " << index + 1 << "'s hours worked: ";
				cin >> hourstemp;
				cout << endl;
			}
			
			employee.retreive(hourstemp, ratetemp, paytemp);

			cout << "\n*** Here is your Check ***\n\n";
			cout << "Pay to the Order of " << employee.getname() << "\t\t" << "$" << paytemp << endl;
		}	

		cout << endl << "***********************************************************\n\n";
		
    }

// **********************************************************************
// * Definition of the function: problem3							    *
// * This function passes an int array pointer along with the array's   *
// * size to another of function.  This other function returns a pointer*
// * of type struct stats. It then displays the the median, mode, and   *
// * average of the original function that was calculated and stored in *
// * a dynamically created struct.										*
// **********************************************************************

	void problem3()
    {
        int size;
		int num;
		
		cout << "\nPlease enter the size of the array you would like to use: ";
		cin >> size;

		while (size < 1) // Confirms the array size is at least 1
		{
			cout << "\n\nPlease enter the size of the array you would like to use: ";
			cin >> size;
		}

		int *ptr;

		ptr = new int [size]; // Dynamically allocated array for numbers

		for (int index = 0; index < size; index++) // Loop used to input numbers into the array
		{
			cout << "Enter number " << index + 1 << " into the array: ";
			cin >> num;
			ptr[index] = num;
		}
		
		stats *sptr; // Pointer variable of type stats

		sptr = avgMedMode(ptr, size); // Sets the pointe to the address of the array that contains the median, avgerage, and mode

		cout << fixed << setprecision(2); 

		cout << "\n\n*** Here are the Results ***\n\n";
		cout << "From the original list of numbers:\n\n{";

		for (int count = 0; count < size; count++) // Displays original values of the array
		{
			cout << *(ptr + count);

			if (count == size - 1)
			{
				cout << "} ";
			}
			else
			{
				cout << ",";
			}
		}
			
		cout << "\n\nThe average of the array is " << sptr->avg << ".\n";
		cout << "The median of the array is " << sptr->median << ".\n";
		cout << "The mode of the array is " << "{";
		
		for (count = 0; count < sptr->nModes; count ++) // Displays the mode values of the array
		{
			cout << *(sptr->mode + count);
			
			if (count == (sptr->nModes - 1))
			{
				cout << "}.";
			}
			else
			{
				cout << ",";
			}
		}
		
		delete [] sptr->mode; // Deletes mode array in dynamically allocated struct
	
	cout << "\n\n***********************************************************\n\n";
	}
    
// **********************************************************************
// * Definition of the function: problem4							    *
// * This function asks the user if they want to encrypt or decrypt a   *
// * code.  The user can enter in a 4 digit code using the values 0 to 7*
// * If the user enters an invalid code, they will have to enter another*
// * one.  It will then encrypt or decrypt the value and display the    *
// * result.															*
// **********************************************************************
	
	void problem4()
    {
       	const int size = 4;
		bool ok;
		int menuchoice;
		char letter;
		char a[size];
					
		Problem4 data;		

		do // Loops until user decides to quit the program
		{
			cout << "\n*** Encrypt / Decrypt Menu ***\n\n";
			cout << "1. Encrypt a number\n";
			cout << "2. Decrypt a number\n";
			cout << "3. Quit\n";
			cout << "Choice is: ";
			cin >> menuchoice;
			
			
			if (menuchoice == 1 || menuchoice == 2) // Checks if menuchoice is 1 or 2
			{
				ok =  false;

				while(!ok)
				{
					ok = true;
					
					cout << "\nPlease enter a 4 digit number code using the digits 0 to 7: ";
					cin.ignore();
					
					for (int index = 0; index < size; index++) // Loops for all 4 values of the code
					{
						cin.get(letter); // Grabs the current character

						a[index] = letter;
											
						if (!data.enternum(index, a[index])) // Checks if the value entered is valid using the member function enternum
						{
							ok = false;
							
						}
					}
				
					if (!ok)
					{
						cout << "\nInvalid Code Entered!!";
					}
					
					cout << endl;
				}
			}
		
				if (menuchoice == 1) // If menuchoice is 1, it will encrypt the value, otherwise it will decrypt it.
				{
					data.encrypt();
				}
				else if (menuchoice == 2)
				{
					data.decrypt();
				}
			
		}while(menuchoice != 3); // Loops until the user wants to quit with a 3

	cout << "\n\n***********************************************************\n\n";
		
	}
    
// **********************************************************************
// * Definition of the function: problem5							    *
// * This function just displays the highest factorial that will fit    *
// * into the basic data types.											*
// **********************************************************************
	
	void problem5()
    {
		
		cout << "\n*** Highest Factorials ***\n\n";
		cout << "Short is 8!\n";
		cout << "Int is 12!\n";
		cout << "Long is 12!\n";
		cout << "Float is 34!\n";
		cout << "Double is 94!";

		cout << "\n\n***********************************************************\n\n";
	}
    
// **********************************************************************
// * Definition of the function: problem6							    *
// * This function just displays the result of the hand conversions.	*
// **********************************************************************
	
	void problem6()
    {
		cout << "\n\n*** Here Are The Conversions ***\n\n";
		cout << "47.8 Base 10  =  101111.1100 (1100) Base 2\n";
		cout << "47.8 Base 10  =  57.6314 (6314) Base 8\n";
		cout << "47.8 Base 10  =  2F.C (C) Base 16\n\n";

		cout << "31.734375 Base 10  =  11111.101111 Base 2\n";
		cout << "31.734375 Base 10  =  37.57 Base 8\n";
		cout << "31.734375 Base 10  =  1F.BC Base 16\n\n";

		cout << "CD.BC Base 16  =  11001101.101111 Base 2\n";
		cout << "CD.BC Base 16  =  315.57 Base 8\n";
		cout << "CD.BC Base 16  =  205.734375 Base 10\n\n";

		cout << "E.CC Base 16  =  1110.110011 Base 2\n";
		cout << "E.CC Base 16  =  16.63 Base 8\n";
		cout << "E.CC Base 16  =  14.796875  Base 10\n\n";

		cout << "\n***********************************************************\n\n";
    }
    void def(int inN)
    {
           cout<<"You typed "<<inN<<" to exit the program"<<endl;
    }

// **********************************************************************
// * Definition of the function: *avgMedMode						    *
// * This function takes as it's arguements a pointer to an array, and  *
// * the array's size.  It then dynamically creates a stuct of type     *
// * stats.  It then uses a selection sort to sort the values in the    *
// * array.  It then determines the median, average, and mode of the    *
// * array and stores the values in the struct.  It then returns a      *
// * pointer to the dynamically created struct.							*
// **********************************************************************
	
stats *avgMedMode(int *array, int size)
{
	stats *strucptr;

	strucptr = new stats;

//	Sort Array in Ascending Order using a selection sort to help

	int startScan, minIndex;
	int minElem;
	
	for (startScan = 0; startScan < (size - 1); startScan++) // Selection sort
	{
		minIndex = startScan;
		minElem = *(array + startScan);
		
		for (int index = startScan + 1; index < size; index++)
		{
			if (*(array + index) < minElem)
			{
				minElem = *(array + index);
				minIndex = index;
			}
		}
		
		*(array + minIndex) = *(array + startScan);
		*(array + startScan) = minElem;
	}

// Determine if there is an even or odd number of intergers and then determine the median

	if (size % 2 == 0)
	{
		strucptr->median = static_cast<float>(*(array + ((size / 2) - 1)) + *(array +(size / 2))) / 2;  // Static cast to convert the int to float
	}
	else
	{
		strucptr->median = *(array + (size / 2));
	}

// Determines the average of the values by summing them up and dividing by the size
	
	float sum = 0;
	
	for (int index = 0; index < size; index++)
	{
		sum = sum + *(array + index);
	}

	strucptr->avg = sum / static_cast<float>(size);

// Determines the mode of the array values

//	Create two arrays that I will use to find the mode.
//  I also initialized the values in these arrays.

	int *values, *totals;

	values = new int[size];
	totals = new int[size];	

	for (int count = 0; count < size; count++) // Initializes the values
	{
		*(values + count) = 0;
		*(totals + count) = 0;
	}	

//	Using two arrays, I total how many times
//  each number appears in the original array
//  using the subscripts of each array
	
	int current = 0;
	*(values + current) = *(array + current);
	*(totals + current) = 1;
	
	for (count = 1; count < size; count++)				// Checks each value of the array and stores them in the values
	{													// array and using subscripts, stores each number,s total in the 
		if (*(array + count) == *(values + current))	    // totals array
		{
			*(totals + current) = *(totals + current) + 1;
		}
		else
		{
			current++;
			*(values + current) = *(array + count);
			*(totals + current) = *(totals + current) + 1;
		}
	}

//	Find the total for the value that occurs most often

	int highest;
	
	highest = totals[0];
	
	for (count = 1; count < size; count++) // Finds the highest value in the totals array
	{
		if (*(totals + count) > highest)
		{
			highest = *(totals + count);
		}
	}

// 	Determine how many intergers are in the mode,
//  if no number occurs more than once, set mode
//	bool to true.

	int modesize = 0;
	bool ifmode = false;
	
	if (highest >= 2)
	{		
		for (count = 0; count < size; count++) // Determines how many values are in the mode by comparing
		{									   // the values to the highest total number
			if (*(totals + count) == highest)
			{
				modesize++;
			}
		}
	}
	else
	{
		modesize = 1;
		ifmode = true; // Sets bool to true because no number occurs more than once.
	}

//	Create another dynamic new array

	int *mode;

	mode = new int[modesize];	

//	Store the size and mode in new dynamic array.
//  If there is no modev, it uses a bool to set the
//  mode value to -1

	current = 0;
	
	if (ifmode) // Stores the mode into the mode array.
	{
		*(mode) = 0;
	}
	else
	{
		for (count = 0; count < size; count++)
		{
					
			if (*(totals + count) == highest)
			{
				*(mode + current) = *(values + count);
				current++;			
			}
		}
	}
	
	strucptr->mode = mode; // Stores the mode into the mode array in the dynamically created struct
	strucptr->nModes = modesize; // Stores the mode size into the modesize variable in the dynamically created struct
	
// Deletes the dynamically created arrays that aren't needed anymore

	delete [] values;
	delete [] totals;

return strucptr;
}


