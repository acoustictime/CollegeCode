// **********************************************************************
// * James Small														*
// * Cis-17a															*
// * 11-1-06															*
// *																	*
// * This program keeps track of inventory.  It uses a structure for    *
// * each part and writes and reads these records to a binary data file.*
// * You can read and write new data to the file.  You can also change  *
// * a specific record in the exisiting file.							*
// **********************************************************************

#include <iostream>
#include <fstream>

using namespace std;

const int DESC_SIZE = 31;

struct InventoryItem
{
	char desc[DESC_SIZE];
	int qty;
	double wcost;
	double rcost;
	int month;
	int day;
	int year;
};

void menu();
void menu1(InventoryItem &record);
void menu2(InventoryItem &record);
void menu3(InventoryItem &record);

int main()
{	
	InventoryItem record;

	int menuchoice;

	do // Main menu loop
	{
		system("cls");

		menu();
		cin >> menuchoice;

		switch (menuchoice)
		{
		case 1: menu1(record);
			break;
		case 2: menu2(record);
			break;
		case 3: menu3(record);
			break;
		case 4:
			break;
		default: cout << "\n\nInvalid Menu Choice, Try Again\n\n";
		};
	}
	while (menuchoice != 4);

return 0;
}

// **********************************************************************
// * Definition of the function: menu								    *
// * This function displays the main user menu.						    *
// **********************************************************************

void menu()
{
	cout << "*** Inventory Program Menu ***\n\n";
	cout << "1. View Records in the file\n";
	cout << "2. Add New Records to the file\n";
	cout << "3. Modify a Record in the file\n";
	cout << "4. Quit the program\n\n";
	cout << "Your Choice Is: ";
}

// **********************************************************************
// * Definition of the function: menu1								    *
// * This function takes as it's arguements a reference parameter for   *
// * the inventory item structure variable.  It then opens the data     *
// * file for input.  It asks the user which record they would like to  *
// * view, and will display the contents of the record.				    *
// **********************************************************************

void menu1(InventoryItem &record)
{
	fstream inventory("Inventory.dat", ios::in | ios::binary); // Opens the file up for input in binary mode
	
	int recnum;

	cout << "\nEnter the record number of the inventory item you would like to view: ";
	cin >> recnum;

	while (recnum < 1) // Loops while record is less than 1
	{
		cout << "\nInvalid Record Number.  The records begin at record # 1.\n\n";
		cout << "Enter the record number of the inventory item you would like to view: ";
		cin >> recnum;
	}

	inventory.seekg((recnum - 1) * sizeof(record), ios::beg); // Seeks the position of the record number you selected
	inventory.read(reinterpret_cast<char *>(&record), sizeof(record)); // Reads the item from the position you selected
	
	cout << "\nDescription: ";
	cout << record.desc << endl;
	cout << "Qty on Hand: ";
	cout << record.qty << endl;
	cout << "Whole Sale Cost: $";
	cout << record.rcost << endl;
	cout << "Retail Cost: $";
	cout << record.wcost << endl;
	cout << "Inv. Date: ";
	cout << record.month << "/" << record.day << "/" << record.year << endl;
	cout << endl << endl;

	system("pause");

	inventory.close();
}

// **********************************************************************
// * Definition of the function: menu2								    *
// * This function takes as it's arguements a reference parameter for   *
// * the inventory item structure variable.  It then opens the data     *
// * file for output.  It allows the user to add another record to the  *
// * end of the file.												    *
// **********************************************************************

void menu2(InventoryItem &record)
{
	fstream inventory("Inventory.dat", ios::out | ios::app | ios::binary); // Opens the file for output in binary append mode

	cout << "Enter Description: ";
	cin.ignore();
	cin.getline(record.desc, DESC_SIZE);
	cout << "Enter Quantity: ";
	cin >> record.qty;

	while (record.qty < 1) // Loops while quantity is less than 1
	{
		cout << "\nPlease enter a qty greater than 0: ";
		cin >> record.qty;
	}

	cout << "Enter WholeSale Price: ";
	cin >> record.wcost;

	while (record.wcost < 1.0) // Loops while wholesale cost is less than 1
	{
		cout << "\nPlease enter a wholesale cost greater than 0: ";
		cin >> record.wcost;
	}

	cout << "Enter the Retail Price: ";
	cin >> record.rcost;

	while (record.rcost < 1.0) // Loops while retail cost is less than 1
	{
		cout << "\nPlease enter a retail cost greater than 0: ";
		cin >> record.rcost;
	}

	cout << "Enter Inventory Date in the following format 1/26/1982: ";
	cin >> record.month;
	cin.ignore(1);
	cin >> record.day;
	cin.ignore(1);
	cin >> record.year;

	// Loops while date is invalid
	
	while (record.month < 1 || record.month > 12 || record.day < 1 || record.day > 31 || record.year < 1000 || record.year > 9999)
	{
		cout << "\nInvalid Year.\n\n";
		cout << "Enter Inventory Date in the following format 1/26/1982: ";
		cin >> record.month;
		cin.ignore(1);
		cin >> record.day;
		cin.ignore(1);
		cin >> record.year;
	}

	inventory.write(reinterpret_cast<char *>(&record), sizeof(record)); // Writes the new record to the end of the file

	inventory.close();
}

// **********************************************************************
// * Definition of the function: menu3								    *
// * This function takes as it's arguements a reference parameter for   *
// * the inventory item structure variable.  It then opens the data     *
// * file for input and output.  It asks the user for which record they *
// * would like to change, and then asks for the new information to     *
// * replace at that position.										    *
// **********************************************************************

void menu3(InventoryItem &record)
{
	fstream inventory("Inventory.dat", ios::in | ios::out | ios::binary); // Opens the file for input, and output in binary mode

	int recnum;

	cout << "\nEnter the item # you would like to change: ";
	cin >> recnum;

	while (recnum < 1) // Loops while record number is less than 1
	{
		cout << "\nInvalid Record Number.  The records begin at record # 1.\n\n";
		cout << "Enter the record number of the inventory item you would like to view: ";
		cin >> recnum;
	}

	inventory.seekg((recnum - 1) * sizeof(record), ios::beg); // Seeks the position you selected

	inventory.read(reinterpret_cast<char *>(&record), sizeof(record)); // Reads the data in the position you selected

	cout << "\nEnter the description: ";
	cin.ignore();
	cin.getline(record.desc, DESC_SIZE);
	cout << "Enter Quantity: ";
	cin >> record.qty;
	
	while (record.qty < 1) // Loops while quantity is less than 1
	{
		cout << "\nPlease enter a qty greater than 0: ";
		cin >> record.qty;
	}

	cout << "Enter WholeSale Price: ";
	cin >> record.wcost;

	while (record.wcost < 1.0) // Loops while wholesale cost is less than 1
	{
		cout << "\nPlease enter a wholesale cost greater than 0: ";
		cin >> record.wcost;
	}

	cout << "Enter the Retail Price: ";
	cin >> record.rcost;

	while (record.rcost < 1.0) // Loops while retail cost is less than 1
	{
		cout << "\nPlease enter a retail cost greater than 0: ";
		cin >> record.rcost;
	}

	cout << "Enter Inventory Date in the following format 1/26/1982: ";
	cin >> record.month;
	cin.ignore(1);
	cin >> record.day;
	cin.ignore(1);
	cin >> record.year;

	// Loops while date is invalid
	
	while (record.month < 1 || record.month > 12 || record.day < 1 || record.day > 31 || record.year < 1000 || record.year > 9999)
	{
		cout << "\nInvalid Year.\n\n";
		cout << "Enter Inventory Date in the following format 1/26/1982: ";
		cin >> record.month;
		cin.ignore(1);
		cin >> record.day;
		cin.ignore(1);
		cin >> record.year;
	}

	inventory.seekp((recnum - 1) * sizeof(record), ios::beg); // Seeks the position you selected

	inventory.write(reinterpret_cast<char *>(&record), sizeof(record)); // Writes the newley enetered data in the position specified

	inventory.close();
}
