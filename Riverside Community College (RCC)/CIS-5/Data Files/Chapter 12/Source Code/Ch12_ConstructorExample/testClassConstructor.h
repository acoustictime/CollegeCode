//Constructor with default Parameters

class testClass
{
public:
	void print() const;				//Line a

	testClass();					//Line b
	testClass(int, int);			//Line c
	testClass(int, int, double);	//Line d
	testClass(double, char);		//Line e

private:
	int x;
	int y;
	double z;
	char ch;
};


