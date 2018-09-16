//**********************************************************
// Program: Telephone Digits
// This is an example of a sentinel-controlled loop. This 
// program converts uppercase letters to their corresponding
// telephone digits.
//**********************************************************

#include <iostream>

using namespace std;

int main()
{
    char letter;                                        //Line 1

    cout << "Program to convert uppercase letters to their "   
         << "corresponding telephone digits." << endl;  //Line 2

	cout << "To stop the program enter #." 
         << endl;                                       //Line 3

    cout << "Enter a letter: ";                         //Line 4
    cin >> letter;                                      //Line 5
    cout << endl;                                       //Line 6

	while (letter != '#')                               //Line 7
    {
        cout << "The letter you entered is: "
             << letter << endl;                         //Line 8
        cout << "The corresponding telephone "
             << "digit is: ";                           //Line 9

        if (letter >= 'A' && letter <= 'Z')             //Line 10
            switch (letter)                             //Line 11
            {
            case 'A': case 'B': 
            case 'C': cout << "2" <<endl;               //Line 12
                      break;                            //Line 13
            case 'D': case 'E': 
            case 'F': cout << "3" << endl;              //Line 14
                      break;                            //Line 15
            case 'G': case 'H': 
            case 'I': cout << "4" << endl;              //Line 16
                      break;                            //Line 17
            case 'J': case 'K': 
            case 'L': cout << "5" << endl;              //Line 18
                      break;                            //Line 19
            case 'M': case 'N': 
            case 'O': cout << "6" << endl;              //Line 20
                      break;                            //Line 21
            case 'P': case 'Q': case 'R': 
            case 'S': cout << "7" << endl;              //Line 22
                      break;                            //Line 23
            case 'T': case 'U': 
            case 'V': cout << "8" << endl;              //Line 24
                      break;                            //Line 25
            case 'W': case 'X': case 'Y':
            case 'Z': cout << "9" << endl;              //Line 26
            }
        else                                            //Line 27
            cout << "Invalid input." << endl;           //Line 28

        cout << "\nEnter another uppercase letter to find " 
             << "its corresponding telephone digit."
             << endl;                                   //Line 29
		cout << "To stop the program enter #."
             << endl;                                   //Line 30

        cout << "Enter a letter: ";                     //Line 31
        cin >> letter;                                  //Line 32
        cout << endl;                                   //Line 33
    }//end while

    return 0;
}