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
      
string Employee::getOffice()
{
  return office;
}

int Employee::getSalary()
{
  return salary;
}

string Employee::getDateHired()
{
  return dateHired;
}


