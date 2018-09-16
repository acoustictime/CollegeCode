//Cable company billing program
#include <iostream>
#include <iomanip>
using namespace std;

	//named constants; residential customers
const double rBillProcessingFee = 4.50;
const double rBasicServiceCost = 20.50;
const double rCostOfAPremiumChannel = 7.50;

	//named constants; business customers
const double bBillProcessingFee = 15.00;
const double bBasicServiceCost = 75.00;
const double bBasicConnectionCost = 5.00;
const double bCostOfAPremiumChannel = 50.00;

double residential();  //Function prototype
double business();     //Function prototype

int main()
{
	//declare variables
   int   accountNumber;
   char  customerType;
   double amountDue;

   cout << fixed << showpoint;						//Step 1
   cout << setprecision(2);							//Step 2

   cout << "This program computes a cable bill."
	    << endl;	
   cout << "Enter account number: ";				//Step 3
   cin >> accountNumber;							//Step 4
   cout << endl;
				
   cout << "Enter customer type: R, r "
	    << "(Residential), B, b (Business): ";		//Step 5
   cin >> customerType;								//Step 6
   cout << endl;

   switch (customerType)							//Step 7
   {
	case 'r':										//Step 7a
	case 'R': amountDue = residential();			//Step 7a.i
		      cout << "Account number = "
				   << accountNumber << endl;  		//Step 7a.ii
		      cout << "Amount due = $"
				   << amountDue << endl;   			//Step 7a.ii
		      break;
	case 'b':										//Step 7b
	case 'B': amountDue = business();				//Step 7b.i
		      cout << "Account number = "
				   << accountNumber << endl;  		//Step 7b.ii
		      cout << "Amount due = $"
 				   << amountDue << endl;   			//Step 7b.ii
		      break;
	default: cout << "Invalid customer type."
				  << endl;							//Step 7c
   }

   return 0;
}
 
double residential()
{
	int   noOfPChannels;	// number of premium channels
	double bAmount;			// billing Amount

	cout << "Enter the number of premium "
	     << "channels used: ";  			
	cin  >>  noOfPChannels;		
	cout << endl;

	bAmount= rBillProcessingFee + 		
   			 rBasicServiceCost +	
			 noOfPChannels * rCostOfAPremiumChannel; 

   return bAmount;
}

double business()
{
   int  noOfBasicServiceConnections;
   int  noOfPChannels;	//number of premium channels
   double bAmount;		//billing Amount

   cout << "Enter the number of basic "
	    << "service connections: ";
   cin >> noOfBasicServiceConnections;
   cout << endl;
	
   cout << "Enter the number of premium "
 	    << "channels used: ";
   cin >> noOfPChannels;
   cout << endl;

   if (noOfBasicServiceConnections <= 10)
	   bAmount = bBillProcessingFee + bBasicServiceCost +
                 noOfPChannels * bCostOfAPremiumChannel;
   else
	   bAmount = bBillProcessingFee + bBasicServiceCost +
	             (noOfBasicServiceConnections - 10) * 
      	         bBasicConnectionCost +
                 noOfPChannels * bCostOfAPremiumChannel;

   return bAmount;
}
