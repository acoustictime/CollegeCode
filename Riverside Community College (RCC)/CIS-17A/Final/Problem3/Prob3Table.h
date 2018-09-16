// Prob3Table.h: interface for the Prob3Table class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PROB3TABLE_H__5E1A5138_B5CE_4CC6_8531_38589E903DFE__INCLUDED_)
#define AFX_PROB3TABLE_H__5E1A5138_B5CE_4CC6_8531_38589E903DFE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <iostream>
#include <fstream>

using namespace std;

template<class T>
class Prob3Table
{
	protected:
		int rows;                                 //Number of rows in the table
		int cols;                                 //Number of cols in the table
		T *rowSum;                                //RowSum array
		T *colSum;                                //ColSum array
		T *table;                                 //Table array
		T grandTotal;                             //Grand total
		void calcTable(void);                     //Calculate all the sums
	public:
		Prob3Table(char *,int,int);               //Constructor then Destructor
		~Prob3Table(){delete [] table;delete [] rowSum;delete [] colSum;};
		const T *getTable(void){return table;};
		const T *getRowSum(void){return rowSum;};
		const T *getColSum(void){return colSum;};
		T getGrandTotal(void){return grandTotal;};
};

template <class T>
void Prob3Table<T>::calcTable()
{

	rowSum = new T[cols];
	colSum = new T[rows];

	int index = 0;
	int index2 = 0;
	int index3 = 0;
	int temp = 0;
	

	for (index = 0; index < rows; index++)
	{
		for (index3 = 0; index3 < cols; index3++)
		{
			temp = temp + table[index2 + index3];
		}

		rowSum[index] = temp;
		index2 = index2 + cols;
		temp = 0;
	}

	index2 = 0;
	
	
	
	for (index = 0; index < cols; index++)
	{
		for (index3 = 0; index3 < rows; index3++)
		{
			temp = temp + table[index2 + index3];
		}

		colSum[index] = temp;
		index2 = index2 + rows;
		temp = 0;
	}

	temp = 0;
		
	for (index = 0; index < cols; index++)
	{
		temp = temp + colSum[index];
	}

	grandTotal = temp;
	
	
	
	
	
	table[cols + 1] = rowSum[0];
	
	
	system("pause");








}




template <class T>
Prob3Table<T>::Prob3Table(char * a,int r,int c)
{
	rows = r;
	cols = c;
	int temp;
	int index = 0;
	T *table2;

	table2 = new int[r*c];

	ifstream infile;

	infile.open(a, ios::in);
	
	while (infile)
	{
		
	
		infile >> temp;
		table2[index] = temp;
		index++;
		
	}
	
	infile.close();

	int index2 = 0;

	for (index = 0; index < (r*c); index++)
	{
		for (int i = 0; i < 6; i++)
		{
			table[index] = table2[index2];
			index2++;
		}
		index2++;
	}



	Prob3Table::calcTable();
}

#endif // !defined(AFX_PROB3TABLE_H__5E1A5138_B5CE_4CC6_8531_38589E903DFE__INCLUDED_)
