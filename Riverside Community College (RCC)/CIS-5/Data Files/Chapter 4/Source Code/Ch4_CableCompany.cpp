#include <iostream>
#include <iomanip>
using namespace std;

	//Named constants - residential customers
const double rBillProcessingFee = 4.50;
const double rBasicServiceCost = 20.50;
const double rCostOfaPremiumChannel = 7.50;

	//Named constants - business customers
const double bBillProcessingFee = 15.00;
const double bBasicServiceCost = 75.00;
const double bBasicConnectionCost = 5.00;
const double bCostOfaPremiumChannel = 50.00;

int main()
{
		//Variable declaration
	int   accountNumber;
	char  customerType;
	int   numberOfPremiumChannels;
	int   noOfBasicServiceConnections;
	double amountDue;

	cout << fixed << showpoint;							//Step 1
	cout << setprecision(2);							//Step 1

	cout << "This program computes a cable bill." << endl;

	cout << "Enter account number: ";					//Step 2
	cin >>  accountNumber;								//Step 3
	cout << endl;		

	cout << "Enter customer type: R or r (Residential), "
		 << "B or b(Business):  ";						//Step 4
	cin >>  customerType;								//Step 5
	cout << endl;

	switch (customerType)
	{
    case 'r':											//Step 6
    case 'R': cout << "Enter the number"
     			   << " of premium channels: "; 		//Step 6a
			  cin >> numberOfPremiumChannels;			//Step 6b
			  cout << endl;

			  amountDue = rBillProcessingFee +   		//Step 6c
						  rBasicServiceCost +
 						  numberOfPremiumChannels * 
                          rCostOfaPremiumChannel;	
			  
			  cout << "Account number = " << accountNumber
				   << endl; 							//Step 6d
			  cout << "Amount due = $" << amountDue
				   << endl;	 							//Step 6d
			  break;
    case 'b':											//Step 7
    case 'B': cout << "Enter the number of basic "
    		       << "service connections: ";			//Step 7a
			  cin >> noOfBasicServiceConnections;		//Step 7b
			  cout << endl;
			  cout << "Enter the number"
    			   << " of premium channels: ";			//Step 7c
			  cin >> numberOfPremiumChannels;			//Step 7d
			  cout << endl;
 
			  if (noOfBasicServiceConnections <= 10)	//Step 7e
				  amountDue =  bBillProcessingFee + 
			 				 bBasicServiceCost +
 							 numberOfPremiumChannels *
 							 bCostOfaPremiumChannel;
			  else
				  amountDue =  bBillProcessingFee + 
							 bBasicServiceCost +
			 				 (noOfBasicServiceConnections -10)
							  * bBasicConnectionCost +
 							 numberOfPremiumChannels * 
 							 bCostOfaPremiumChannel;

			  cout << "Account number = " 
    		       << accountNumber << endl; 			//Step 7f
			  cout << "Amount due = $" << amountDue
				   << endl;								//Step 7f
		      break;
    default: cout << "Invalid customer type."  << endl; //Step 8
	}//end switch

	return 0;
}
