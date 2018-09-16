// LArman 2004 Page 415 Figure 25.1 Polymorphism...
#ifndef FIG251CPP
#define FIG251CPP
#include <list>
using namespace std;

#include "Sale.cpp"
#include "TaxLineItems.cpp"

class ITaxCalculatorAdapter // <<interface>>
{
   public:
	virtual list<TaxLineItems*> getTaxes (Sale *)=0;
};

/**** Normally in a separte file.... ****/
class TaxMasterAdapter: public ITaxCalculatorAdapter
{

   public:
	list<TaxLineItems*> getTaxes (Sale *) //stub
	{
		list <TaxLineItems*>empty;
		return empty;
	}

};

class GoodAsGoldTaxPro: public ITaxCalculatorAdapter
{

   public:
	list<TaxLineItems*> getTaxes (Sale *) //stub
	{
		list <TaxLineItems*>empty;
		return empty;
	}

};
#endif
