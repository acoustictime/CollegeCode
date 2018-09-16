#include "Person.h"
#include "Employee.h"
#include <string>
    
using namespace std; 

Employee::Employee()
{
  office = "";
  salary = 0;
  dateHired = "";
} 

Employee::Employee(string name, string address, string telephone, string email, string office, int salary, string dateHired) : Person(name,address,telephone,email)
{
  this->office = office;
  this->salary = salary;
  this->dateHired = dateHired;
}
      
string Employee::getOffice() const
{
  return office;
}

int Employee::getSalary() const
{
  return salary;
}

string Employee::getDateHired() const
{
  return dateHired;
}

string Employee::whatami() const
{
return "Employee";
}


