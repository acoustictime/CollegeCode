// Prob2Sort.h: interface for the Prob2Sort class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PROB2SORT_H__2ECBF4A4_48F9_43EE_8E15_AB96F5EBE1F3__INCLUDED_)
#define AFX_PROB2SORT_H__2ECBF4A4_48F9_43EE_8E15_AB96F5EBE1F3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

template <class T>
class Prob2Sort  
{
	private:
		T var;

public:
	Prob2Sort(int);
	
};

template <class T>
Prob2Sort<T>::Prob2Sort(int a)
{

	var = a;

}

#endif // !defined(AFX_PROB2SORT_H__2ECBF4A4_48F9_43EE_8E15_AB96F5EBE1F3__INCLUDED_)
