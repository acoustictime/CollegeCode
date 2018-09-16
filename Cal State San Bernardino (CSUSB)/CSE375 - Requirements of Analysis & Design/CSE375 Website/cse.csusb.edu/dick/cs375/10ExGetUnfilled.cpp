/* The Communication diagram for getUnfilled orders would lead to
code like the following functions being placed in their respective
classes.  

Note: this is not working code and would have to be editted into sever
different files before compilation and testing.

We would also need to sort out the type of an iterator<T>.
*/

typedef vector <*SalesOrder> VSO; // short hand.

VSO Depot::getUnfilledOrder()
{
	VSO unfilledOrders;

	for(iterator<Customer> cust = customer.first(); cust!= customer.end(); cust++)
	{
		cust -> addUnfilled(unfilledOrders);
	}
	return unfilledOrders;
}

void Customer::addUnfilled(VSO & unfilledOrders)
{
	for( iterator<Order> sO= salesOrder.first(); sO!=salesOrder.end(); sO++)
		sO->addUnfilled(unfilledOrders);
}

void SalesOrder::addUnfilled(VSO & unfilledOrders)
{
	if(unfilled)
		unfilledOrders.push_back(this);
	
}
