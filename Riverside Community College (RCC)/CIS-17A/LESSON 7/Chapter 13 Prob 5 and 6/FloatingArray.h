// FloatingArray.h: interface for the FloatingArray class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_FLOATINGARRAY_H__95E9C2D0_D9D2_419A_AF62_4756F1D2BB80__INCLUDED_)
#define AFX_FLOATINGARRAY_H__95E9C2D0_D9D2_419A_AF62_4756F1D2BB80__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class FloatingArray  
{
	private:
		int *ptr;
		int arraysize;
		bool valid(int);
	
	public:
		FloatingArray(int size);
		~FloatingArray();
		bool enter(int element, int value);
		bool retrieve(int element, int &value);
		double average();
		int highest();
		int lowest();
};

#endif // !defined(AFX_FLOATINGARRAY_H__95E9C2D0_D9D2_419A_AF62_4756F1D2BB80__INCLUDED_)
