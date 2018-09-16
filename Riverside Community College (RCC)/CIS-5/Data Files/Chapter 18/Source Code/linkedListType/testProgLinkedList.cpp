//This program tests various operation of a linked list
 
#include <iostream>
#include "linkedList.h"

using namespace std;

int main()
{
	linkedListType<int> list1, list2;				//Line 1
	int num;										//Line 2

	cout<<"Line 3: Enter numbers ending with -999"
		<<endl;										//Line 3
	cin>>num;										//Line 4

	while(num != -999)								//Line 5
	{
		list1.insertLast(num);						//Line 6
		cin>>num;									//Line 7
	}

	cout<<endl;										//Line 8

	cout<<"Line 9: List 1: ";						//Line 9
	list1.print();									//Line 10
	cout<<endl;										//Line 11
	cout<<"Line 12: Length List 1: "<<list1.length()
		<<endl;										//Line 12

	list2 = list1;	   //test the assignment operator Line 13

	cout<<"Line 16: List 2: ";						//Line 14
	list2.print();									//Line 15
	cout<<endl;										//Line 16
	cout<<"Line 17: Length List 2: "<<list2.length()
		<<endl;										//Line 17

	cout<<"Line 18: Enter the number to be "
		<<"deleted: ";								//Line 18
	cin>>num;										//Line 19
	cout<<endl;										//Line 20

	list2.deleteNode(num);							//Line 21
	
	cout<<"Line 22: After deleting the node, "
		<<"List 2: "<<endl;							//Line 22
	list2.print();									//Line 23
	cout<<endl;										//Line 24

	cout<<"Line 25: Length List 2: "<<list2.length()
		<<endl;										//Line 25

	return 0;					
}



