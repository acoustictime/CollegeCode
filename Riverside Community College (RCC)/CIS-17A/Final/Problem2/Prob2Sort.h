// Prob2Sort.h: interface for the Prob2Sort class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PROB2SORT_H__3D185F48_16E7_4006_87DC_7468B0C6641F__INCLUDED_)
#define AFX_PROB2SORT_H__3D185F48_16E7_4006_87DC_7468B0C6641F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <iostream>

using namespace std;

template<class T>
class Prob2Sort
{
	private:
		int *index;                                 //Index that is utilized in the sort
	public:
		Prob2Sort(){index=NULL;};                   //Constructor
		~Prob2Sort(){delete []index;};              //Destructor
		T * sortArray(const T*,int,bool);           //Sorts a single column array
		T * sortArray(const T*,int,int,int,bool);   //Sorts a 2 dimensional array
};

template <class T>
T * Prob2Sort<T>::sortArray(const T* ch2p, int r, int c, int s, bool a)
{
	T *ch2new=new T[10 * 16];
	T *ch2pnew=const_cast<char*>(ch2p);

	T *sort = new T[r * c];
	int index3;
	int s2 = s - 1;
	
	bool swap;

	
	if (a)
	{
	
	do
	{
		swap = false;

		for (int count = 0; count < 144; count = count + 16)
		{
			if (ch2pnew[s2 + count] > ch2pnew[s2 + count + 16])
			{
				for (index3 = count; index3 < (count + 16); index3++)
				{
					sort[index3] = ch2pnew[index3];
				}

				for (index3 = count; index3 < (count + 16); index3++)
				{
					ch2pnew[index3] = ch2pnew[index3 + 16];
				}

				for (index3 = count + 16; index3 < (count + 32); index3++)
				{
					ch2pnew[index3] = sort[index3 - 16];
				}

				swap = true;	
			}
		}
	} while(swap);

	}
	else
	{
	
	do
	{
		swap = false;

		for (int count = 0; count < 144; count = count + 16)
		{
			if (ch2pnew[s2 + count] < ch2pnew[s2 + count + 16])
			{
				for (index3 = count; index3 < (count + 16); index3++)
				{
					sort[index3] = ch2pnew[index3];
				}

				for (index3 = count; index3 < (count + 16); index3++)
				{
					ch2pnew[index3] = ch2pnew[index3 + 16];
				}

				for (index3 = count + 16; index3 < (count + 32); index3++)
				{
					ch2pnew[index3] = sort[index3 - 16];
				}

				swap = true;	
			}
		}
	} while(swap);
	
	}

	cout << endl;

return ch2pnew;

	delete [] ch2pnew;
}

template <class T>
T * Prob2Sort<T>::sortArray(const T*,int,bool)
{
	// Couldn't find a use for this function
}


#endif // !defined(AFX_PROB2SORT_H__3D185F48_16E7_4006_87DC_7468B0C6641F__INCLUDED_)
