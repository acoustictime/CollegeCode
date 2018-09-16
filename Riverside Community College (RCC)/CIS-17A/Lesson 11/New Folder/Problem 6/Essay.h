// Essay.h: interface for the Essay class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ESSAY_H__7351FAD1_517C_4C11_AA54_1C94AFC51068__INCLUDED_)
#define AFX_ESSAY_H__7351FAD1_517C_4C11_AA54_1C94AFC51068__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "GradedActivity.h"

class Essay : public GradedActivity
{
	protected:
		GradedActivity Grammer, Spelling, Length, Content;
		double score;

	public:
		Essay(double g, double s, double l, double c);
		void calcgrade();
		char getLetterGrade();
		double getgrammer();
		double getspelling();
		double getlength();
		double getcontent();
		double gettotalscore();
		void checkvalid();
};

#endif // !defined(AFX_ESSAY_H__7351FAD1_517C_4C11_AA54_1C94AFC51068__INCLUDED_)
