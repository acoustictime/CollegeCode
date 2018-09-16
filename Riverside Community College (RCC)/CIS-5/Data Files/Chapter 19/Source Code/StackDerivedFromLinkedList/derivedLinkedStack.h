//Header file derivedLinkedStack.h

#ifndef H_derivedLinkedStack
#define H_derivedLinkedStack

#include <iostream>
#include "linkedList.h"

using namespace std;

template<class Type>
class linkedStackType: public linkedListType<Type>
{
public:
	void initializeStack();
	bool isEmptyStack() const;
	bool isFullStack() const;
	void push(const Type& newItem);
    Type top() const;
	void pop();
	void destroyStack();
};

template<class Type>
void linkedStackType<Type>::initializeStack()
{
    linkedListType<Type>::initializeList();
}

template<class Type>
bool linkedStackType<Type>::isEmptyStack() const
{
	return linkedListType<Type>::isEmptyList();
}

template<class Type>
bool linkedStackType<Type>::isFullStack() const
{
	return false;
}

template<class Type>
void linkedStackType<Type>::destroyStack()
{
	linkedListType<Type>::destroyList();
}

template<class Type>
void linkedStackType<Type>::push(const Type& newElement)
{
	linkedListType<Type>::insertFirst(newElement);
}

template<class Type>
Type linkedStackType<Type>::top() const
{
    return linkedListType<Type>::front();	
}

template<class Type>
void linkedStackType<Type>::pop()
{
    nodeType<Type> *temp;

    temp = first;
    first = first->link;
    delete temp;
}

#endif
