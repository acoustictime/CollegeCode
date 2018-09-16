// **********************************************************************
// * James Small														*
// * Cis-17a															*
// * 12-16-06															*
// *																	*
// * This is the final.  You can select which problem to run by the     *
// * using the menu.  I finished all the problems except # 3.  I ran out*
// * of time.															*
// **********************************************************************

#include <iostream>
#include <ctime>
#include <fstream>
#include <cstdlib>
#include "SavingsAccount.h"
#include "Prob3TableInherited.h"
#include "Prob2Sort.h"
#include "Employee.h"
#include "Prob1Random.h"
using namespace std;

void Menu();
int getN();
void def(int);
void problem1();
void problem2();
void problem3();
void problem4();
void problem5();

    int main(int argv,char *argc[])
    {
	int inN;
        do{
		system("cls");
         Menu();
         inN=getN();
         switch(inN){
          case 1:    system("cls"); problem1(); system("pause"); break;
          case 2:    system("cls"); problem2(); system("pause"); break;
          case 3:    system("cls"); problem3(); system("pause"); break;
          case 4:    system("cls"); problem4(); system("pause"); system("cls"); break;
          case 5:    system("cls"); problem5(); system("pause"); system("cls"); break;
          default:   def(inN);}
        }while(inN<6);
        return 1;
    }
    void Menu()
    {
           cout<<"Type 1 for problem 1"<<endl;
           cout<<"Type 2 for problem 2"<<endl;
           cout<<"Type 3 for problem 3"<<endl;
           cout<<"Type 4 for problem 4"<<endl;
           cout<<"Type 5 for problem 5"<<endl;
           cout<<"Type 6 to exit \n"<<endl;
    }
    int getN()
    {
           int inN;
		   cin>>inN;
           return inN;
    }
    void problem1()
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

    }
    void problem2()
    {
           	cout<<"The start of Problem 2, the sorting problem"<<endl;
	
	Prob2Sort<char> rc;
	
	bool ascending=true;
	ifstream infile;
	infile.open("Problem2.txt",ios::in);
	
	char *ch2=new char[10*16];
	char *ch2p=ch2;
	
	while(infile.get(*ch2)){cout<<*ch2;ch2++;}
	
	infile.close();
	
	cout<<endl;
	cout<<"Sorting on which column"<<endl;
	
	int column;
	cin>>column;
	
	char *zc=rc.sortArray(ch2p,10,16,column,ascending);
	
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<16;j++)
		{
			cout<<zc[i*16+j];
		}
	}
	
	delete []zc;
	cout<<endl;
    }
    void problem3()
    {
         cout << "I didn't get time to finish this problem.  Thank You for the\n";
		 cout << "extension though, I wouldn't have gotten this far without it.\n";
		 cout << "I commented out the what I did get done on the problem.\n\n";

		
	/*	cout<<"Entering problem number 3"<<endl;
	
		int rows=5;
		int cols=6;
	
		Prob3TableInherited<int> tab("Problem3.txt",rows,cols);
	
		const int *naugT=tab.getTable();
	
		for(int i=0;i<rows;i++)
		{
			for(int j=0;j<cols;j++)
			{
				cout<<naugT[i*cols+j]<<" ";
			}
			cout<<endl;
		}
	
		cout<<endl;
	
		const int *augT=tab.getAugTable();
	
		for(i=0;i<=rows;i++)
		{
			for(int j=0;j<=cols;j++)
			{
				cout<<augT[i*(cols+1)+j]<<" ";
			}
			cout<<endl;
		}
	*/

	}

    void problem4()
    {
           srand(time(NULL));

	SavingsAccount mine(-300);

	for(int i=1;i<=10;i++)
	{
		mine.Transaction((float)(rand()%500)*(rand()%3-1));

	}
	mine.toString();
	cout<<"\nBalance after 7 years given 10% interest = " << mine.Total((float)(0.10),7)<<endl;
	cout<<"Balance after 7 years given 10% interest = " << mine.TotalRecursive((float)(0.10),7) << " Recursive Calculation "<<endl;
    }
    void problem5()
    {
        Employee Mark("Mark","Boss",215.50);
		Mark.setHoursWorked(-3);
		Mark.toString();
		Mark.CalculatePay(Mark.setHourlyRate(20.0),
		Mark.setHoursWorked(25));
		Mark.toString();
		Mark.CalculatePay(Mark.setHourlyRate(40.0),
		Mark.setHoursWorked(25));
		Mark.toString();
		Mark.CalculatePay(Mark.setHourlyRate(60.0),Mark.setHoursWorked(25));
		Mark.toString();

		Employee Mary("Mary","VP",50.0);
		Mary.toString();
		Mary.CalculatePay(Mary.setHourlyRate(50.0),
		Mary.setHoursWorked(40));
		Mary.toString();
		Mary.CalculatePay(Mary.setHourlyRate(50.0),
		Mary.setHoursWorked(50));
		Mary.toString();
		Mary.CalculatePay(Mary.setHourlyRate(50.0),
		Mary.setHoursWorked(60));
		Mary.toString();
    }
    void def(int inN)
    {
           cout<<"You typed "<<inN<<" to exit the program"<<endl;
    }


