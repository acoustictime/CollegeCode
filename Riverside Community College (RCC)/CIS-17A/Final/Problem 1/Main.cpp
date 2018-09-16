
#include <iostream>
#include <cstring>
#include "Prob1Random.h"

using namespace std;

int main()
{
	char n=5;
	char rndseq[]={16,34,57,79,121};
	int ntimes=100000;
	
	Prob1Random a(n,rndseq);
	
	for(int i=1;i<=ntimes;i++)
	{
		a.randFromSet();
	}
	
	int *x=a.getFreq();
	char *y=a.getSet();
	
	for(i=0;i<n;i++)
	{
		cout<<int(y[i])<<" occured "<<x[i]<<" times"<<endl;
	}
	
	cout<<"The total number of random numbers is "<<a.getNumRand()<<endl;


return 0;
}