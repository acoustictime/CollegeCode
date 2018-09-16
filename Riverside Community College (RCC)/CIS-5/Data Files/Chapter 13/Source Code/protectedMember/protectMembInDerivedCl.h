
#ifndef H_protectMembInDerivedCl
#define H_protectMembInDerivedCl

#include "protectMembClass.h"

class dClass: public bClass
{
public:
	void setData(char, double, int);
	void print() const;

private:
	int dA;
}; 

#endif