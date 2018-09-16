//Example find function

#include <iostream>
#include <string>

using namespace std; 

int main()
{
	string 	sentence, str;								//Line 1
	string::size_type position;							//Line 2

	sentence = "Outside it is cloudy and warm."; 		//Line 3
	str = "cloudy";										//Line 4

	cout << "Line 5: sentence = \"" << sentence
		 << "\"" << endl;                               //Line 5

	cout << "Line 6: The position of \"is\" in sentence = " 
		 << static_cast<unsigned int> (sentence.find("is")) 
		 << endl;		                                //Line 6
	 
	cout << "Line 7: The position of \"and\" in sentence = " 
		 << static_cast<unsigned int> (sentence.find("and")) 
		 << endl;                                       //Line 7
	  				
	cout << "Line 8: The position of 's' in sentence = " 
		 << static_cast<unsigned int> (sentence.find('s')) 
		 << endl;		                                //Line 8

	cout << "Line 9: The position of 'o' in sentence = " 
		 << static_cast<unsigned int> (sentence.find('o')) 
		 << endl;		                                //Line 9
									
	cout << "Line 10: The position of \"" << str 
		 << "\" in sentence = " 
		 << static_cast<unsigned int> (sentence.find(str))
		 << endl;					                    //Line 10

	cout << "Line 11: The position of \"the\" in sentence = " 
		 << static_cast<unsigned int> (sentence.find("the")) 
		 << endl; 	                                   //Line 11

	cout << "Line 12: The first occurrence of \'i\' in " 
		 << "sentence after position 6 = " 
		 << static_cast<unsigned int> (sentence.find('i', 6)) 
		 << endl;                                       //Line 12

	position = sentence.find("warm");					//Line 13
	cout << "Line 14: " << "Position = " 
		 << static_cast<unsigned int> (position)
		 << endl; 										//Line 14
	 
	return 0;
}




