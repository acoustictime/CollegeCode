#include <iostream>

using namespace std;


int seqOrderedSearch(const int list[], int listLength, int searchItem);

int main()
{
    cout << "See Programming Exercise 1 at the end of this chapter. "  
		 << endl;                        

	return 0;                                             
}


int seqOrderedSearch(const int list[], int listLength, int searchItem)
{
   	int loc;									//Line 1
   	bool found = false;							//Line 2

 	for (loc = 0; loc < listLength; loc++)		//Line 3
	    if (list[loc] >= searchItem)		    //Line 4
		{
		    found = true;						//Line 5
		    break;								//Line 6
		}
 
   	if (found)									//Line 7
   	    if (list[loc] == searchItem)			//Line 8
		    return loc;							//Line 9
   	    else									//Line 10
		    return -1;							//Line 11
	else										//Line 12
		return -1;								//Line 13
}
