#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "courseType.h"

using namespace std;

void courseType::setCourseInfo(string cName, string cNo,
							   int credits)
{
	courseName = cName;
	courseNo = cNo;
	courseCredits = credits;
}

void courseType::print(ostream& outF)
{
	outF << left;								//Step 1
	outF << setw(8) << courseNo << "   ";		//Step 2
	outF << setw(15) << courseName;				//Step 3		
	outF << right; 								//Step 4
	outF << setw(3) << courseCredits << "   ";	//Step 5
}

courseType::courseType(string cName, string cNo, int credits)
{
	courseName = cName;
	courseNo =  cNo;
	courseCredits = credits;
}

int courseType::getCredits()
{
	return courseCredits;
}


string courseType::getCourseNumber()
{
	return courseNo;
}

string courseType::getCourseName()
{
	return courseName;
}