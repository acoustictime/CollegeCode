/* Test Larman Fig 25.1.... */

#include <iostream>
#include <cassert>
using namespace std;

#include "fig25_25_1.cpp"

int main()
{
	ITaxCalculatorAdapter * taxCalculator;

	taxCalculator = new TaxMasterAdapter;

	Sale * dummy;

	list<TaxLineItems*> foo;

	foo = taxCalculator->getTaxes(dummy);

	taxCalculator = new GoodAsGoldTaxPro;

	list<TaxLineItems*> foobar;

	foobar = taxCalculator->getTaxes(dummy);

	assert( foo == foobar );

	cerr << "OK!\n";

	return 0;
}
