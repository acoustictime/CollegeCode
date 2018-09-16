// Prob3TableInherited.h: interface for the Prob3TableInherited class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PROB3TABLEINHERITED_H__2D7DE295_1C98_4D06_945E_C1408408547B__INCLUDED_)
#define AFX_PROB3TABLEINHERITED_H__2D7DE295_1C98_4D06_945E_C1408408547B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Prob3Table.h"

template<class T>
class Prob3TableInherited : public Prob3Table<T>
{
	protected:
		T *augTable;                                  //Augmented Table with sums
	public:
		Prob3TableInherited(char *,int,int);          //Constructor
		~Prob3TableInherited(){delete [] augTable;};  //Destructor
		const T *getAugTable(void){return augTable;}; 
};

template <class T>
Prob3TableInherited<T>::Prob3TableInherited(char * a,int r,int c) : Prob3Table<T>(a,r,c)
{
	system("pause");
	augTable = table;
}



#endif // !defined(AFX_PROB3TABLEINHERITED_H__2D7DE295_1C98_4D06_945E_C1408408547B__INCLUDED_)
