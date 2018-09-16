//Chapter 3: Program Movie Ticket Sale

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
		//Step 1
    string movieName;
    double adultTicketPrice;
    double childTicketPrice;
    int noOfAdultTicketsSold;
    int noOfChildTicketsSold;
    double percentDonation;
    double grossAmount;
    double amountDonated;
    double netSaleAmount;

    cout << fixed << showpoint << setprecision(2);    //Step 2

    cout << "Enter the movie name: ";        //Step 3
    getline(cin, movieName);                          //Step 4
    cout << endl;

    cout << "Enter the price of an adult ticket: "
         << flush;                                    //Step 5
    cin >> adultTicketPrice;                          //Step 6
    cout << endl;

    cout << "Enter the price of a child ticket: " 
         << flush;                                    //Step 7
    cin >> childTicketPrice;                          //Step 8
    cout << endl;

    cout << "Enter the number of adult tickets sold: " 
         << flush;                                    //Step 9
    cin >> noOfAdultTicketsSold;                      //Step 10
    cout << endl;

    cout << "Enter the number of child tickets sold: " 
         << flush;                                    //Step 11
    cin >> noOfChildTicketsSold;                      //Step 12
    cout << endl;
 
    cout << "Enter the percentage of donation: " 
         << flush;                                    //Step 13
    cin >> percentDonation;                           //Step 14
    cout << endl << endl;
 
                   //Step 15
    grossAmount = adultTicketPrice * noOfAdultTicketsSold +
                  childTicketPrice * noOfChildTicketsSold; 

                   //Step 16
    amountDonated = grossAmount * percentDonation / 100; 

    netSaleAmount = grossAmount - amountDonated;      //Step 17

           //Step 18: Output results
    cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"
         << "-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
    cout << setfill('.') << left << setw(35) << "Movie Name: "
         << right << " " << movieName << endl;
    cout << left << setw(35) << "Number of Tickets Sold: "
         << setfill(' ') << right << setw(10)
         << noOfAdultTicketsSold + noOfChildTicketsSold
         << endl;
    cout << setfill('.') << left << setw(35)
		 << "Gross Amount: "
         << setfill(' ') << right << " $"
         << setw(8) << grossAmount << endl;
    cout << setfill('.') << left << setw(35)
         << "Percentage of Gross Amount Donated: "
         << setfill(' ') << right
         << setw(9) << percentDonation << '%' << endl;
    cout << setfill('.') << left << setw(35) 
         << "Amount Donated: "
         << setfill(' ') << right << " $"
         << setw(8) << amountDonated << endl;
    cout << setfill('.') << left << setw(35) << "Net Sale: "
         << setfill(' ') << right << " $"
         << setw(8) << netSaleAmount << endl;

    return 0;
}