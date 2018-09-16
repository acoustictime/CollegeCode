#include <iostream>

using namespace std;

int main ()
{
    int studentID, testScore, count = 0;

	cout << "Enter student ID and the test score." << endl;
	cout << "To terminate the program enter -1 for student ID." 
		<< endl;
	cin >> studentID;
	while (studentID != -1)
	{
	    count++;
	    cin >> testScore;
	    cout << "Student ID = " << studentID << ", test score = "
    		 << testScore << ", and grade = ";

	    if (testScore >= 90)
		    cout << "A." << endl;
	    else
	        if (testScore >= 80) 
		        cout << "B." << endl;
	        else
		       if (testScore >= 70) 
                   cout << "C." << endl;
		       else
		           if (testScore >= 60) 
               	       cout << "D." << endl;
		           else
			          cout << "F." << endl;
	   cin >> studentID;
	}//end while  

	cout << "The number of students in class = " 
		 << count << endl;

	return 0;
}
