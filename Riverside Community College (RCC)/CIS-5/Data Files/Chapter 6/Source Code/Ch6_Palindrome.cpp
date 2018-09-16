#include <iostream>
#include <cmath>
using namespace std;

bool isNumPalindrome (int num);

int main()
{
	return 0;
}

bool isNumPalindrome(int num)
{
  int pwr = 0;

  if (num < 10)												//Step 1
	 return true;
  else														//Step 2
  {
		
    while (num / static_cast<int>(pow(10,pwr)) >= 10)		//Step 2.a
	pwr++;
	
    while (num >= 10)										//Step 2.b
    {
		if ((num / static_cast<int>(pow(10,pwr))) != (num % 10))
			return false;									//Step 2.b.1		
		else												//Step 2.b.2
		{	
							
			num = num % static_cast<int>(pow(10,pwr));		//Step 2.b.2.1
			num = num / 10;									//Step 2.b.2.1
			pwr = pwr - 2;									//Step 2.b.2.2	
		}
    }//end while

    return true;
  }//end else
}
