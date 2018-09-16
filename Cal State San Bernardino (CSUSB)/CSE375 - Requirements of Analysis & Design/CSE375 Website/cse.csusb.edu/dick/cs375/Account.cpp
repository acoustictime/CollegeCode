// A class based on the ATM example in Deitel and Deitel

class Account
{
   private: 
	int accountNumber;
	int pin;
	double availableBalance;
	double totalBalance;
   public:
	Account ( int a, int p, double ab, double tb)
	{
		accountNumber=a;
		pin=p;
		availableBalance=ab;
		totalBalance=tb;
	}
};
