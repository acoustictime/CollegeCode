//Queue derived from the class linkedListType
//Header file: queueLinked.h

#ifndef H_QueueType
#define H_QueueType

#include <iostream>
#include "linkedList.h"

using namespace std;

template<class Type>
class linkedQueueType: public linkedListType<Type>
{
public:
    bool isEmptyQueue() const;
    bool isFullQueue() const;
    void destroyQueue();
    void initializeQueue();
    void addQueue(const Type& newElement);
    Type front() const;
    Type back() const;
    void deleteQueue();
};

template<class Type>
void linkedQueueType<Type>::initializeQueue()
{
      linkedListType<Type>::initializeList();
}

template<class Type>
void linkedQueueType<Type>::destroyQueue()
{
	linkedListType<Type>::destroyList();
}

template<class Type>
bool linkedQueueType<Type>::isEmptyQueue() const
{
	return linkedListType<Type>::isEmptyList();
}

template<class Type>
bool linkedQueueType<Type>::isFullQueue() const
{
	return false;
}

template<class Type>
void linkedQueueType<Type>::addQueue(const Type& newElement)
{
	linkedListType<Type>::insertLast(newElement);
}

template<class Type>
Type linkedQueueType<Type>::front() const
{
   return linkedListType<Type>::front();      
}

template<class Type>
Type linkedQueueType<Type>::back() const
{
   return linkedListType<Type>::back();       
}

template<class Type>
void linkedQueueType<Type>::deleteQueue()
{
   nodeType<Type> *temp;

   if (!isEmptyQueue())
   {
		temp = first;         //make temp point to the first node
   		first = first->link;  //advance first to the next node
   		delete temp;          //delete the first node
   		if (first == NULL)     //if after deletion the queue is empty,
           last = NULL;	    //set last to NULL
   }
   else
		cout << "Cannot remove from an empty queue." << endl;
}


#endif
