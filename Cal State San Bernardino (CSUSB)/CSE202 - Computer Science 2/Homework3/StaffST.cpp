#include "Person.h" 
#include "Student.h"
#include "Staff.h"
#include "Employee.h"
#include "StaffST.h"
#include <string>
    
using namespace std; 

StaffST::StaffST()
{
    creditHours = 0;
} 


StaffST::StaffST(string name, string address, string telephone, string email, string office, int salary, string dateHired, string position, string status, int creditHours) : Staff(name,address,telephone,email,office,salary,dateHired,position), Student(name,address,telephone,email,status)
{
    this->creditHours = creditHours;
    reset(name,address,telephone,email);
}

int StaffST::getCreditHours() const
{
    return creditHours;
}

string StaffST::whatami() const
{
return "StaffST";
}

