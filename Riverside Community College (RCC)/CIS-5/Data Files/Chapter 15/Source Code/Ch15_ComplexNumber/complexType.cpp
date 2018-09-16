
//Implementation file complexType.cpp

#include <iostream>
using namespace std;

#include "complexType.h"

ostream& operator<<(ostream& osObject, const complexType& complex)
{
	osObject << "(" << complex.realPart << ", "
		     << complex.imaginaryPart << ")";
	return osObject;
}

istream& operator>>(istream& isObject, complexType& complex)
{
	char ch;

	isObject >> ch;                     //read and discard (
	isObject >> complex.realPart;       // get the real part
	isObject >> ch;                     // read and discard,
	isObject >> complex.imaginaryPart;  // get the imaginary part
	isObject >> ch;                     // read and discard)

	return isObject;
}

bool complexType::operator==(const complexType& otherComplex) const
{
	return(realPart == otherComplex.realPart && 
		   imaginaryPart == otherComplex.imaginaryPart);
}


//constructor with parameter
complexType::complexType(double real, double imag)
{
	realPart = real;
	imaginaryPart = imag;
}

//Function to set the complex number after the object has been declared.

void complexType::setComplex(const double& real, const double& imag)
{
	realPart = real;
	imaginaryPart = imag;
}

void complexType::getComplex(double& real, double& imag) const
{
    real = realPart;
    imag = imaginaryPart;
}

	//overload the operator +
complexType complexType::operator+
 			   (const complexType& otherComplex) const
{
	complexType temp;

	temp.realPart = realPart + otherComplex.realPart;
	temp.imaginaryPart = imaginaryPart 
                         + otherComplex.imaginaryPart;

	return temp;
}

	//overload the operator *
complexType complexType::operator*
 				(const complexType& otherComplex) const
{
   complexType temp;

   temp.realPart = (realPart * otherComplex.realPart) -
                   (imaginaryPart * otherComplex.imaginaryPart);
   temp.imaginaryPart = (realPart * otherComplex.imaginaryPart) +
                      (imaginaryPart * otherComplex.realPart);
   return temp;
}

