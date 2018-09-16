// Problem4.h: interface for the Problem4 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PROBLEM4_H__7C2F0873_38E8_4365_AF8E_63D1DA5AC3C9__INCLUDED_)
#define AFX_PROBLEM4_H__7C2F0873_38E8_4365_AF8E_63D1DA5AC3C9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

const int size = 4;

class Problem4  
{
	private:
		 
		int num[size];
		bool valid(int num);
			
	public:
		Problem4();
		void encrypt();
		void decrypt();
		bool enternum(int i, char a);
};

#endif // !defined(AFX_PROBLEM4_H__7C2F0873_38E8_4365_AF8E_63D1DA5AC3C9__INCLUDED_)
