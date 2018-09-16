//Program to test the various operations on an ordered linked list

#include <iostream>
#include "orderedLinkedList.h"
 
using namespace std;

int main()
{
	orderedLinkedListType<int> list1, list2;		//Line 1
	int num;										//Line 2

	cout<<"Line 3: Enter numbers ending with -999"
		<<endl;										//Line 3
	cin>>num;										//Line 4

	while (num != -999)								//Line 5
	{
		list1.insertNode(num);						//Line 6
		cin>>num;									//Line 7
	}

	cout<<endl;										//Line 8

	cout<<"Line 9: List 1: ";						//Line 9
	list1.print();									//Line 10
	cout<<endl;										//Line 11

	cout<<"Line 12: List 1 in reverse order: "
		<<endl;										//Line 12
	list1.printListReverse();						//Line 13
	cout<<endl;										//Line 14

	list2 = list1;	   //test the assignment operator Line 15

	cout<<"Line 16: List 2: ";						//Line 16
	list2.print();									//Line 17
	cout<<endl;										//Line 18

	cout<<"Line 19: Enter the number to be "
		<<"deleted: ";								//Line 19
	cin>>num;										//Line 20
	cout<<endl;										//Line 21

	list2.deleteNode(num);							//Line 22

	cout<<"Line 23: After deleting the node, "
		<<"List 2: "<<endl;							//Line 23
	list2.print();									//Line 24
	cout<<endl;										//Line 25

	return 0;					
}



