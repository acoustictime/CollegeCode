#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "Person.h"
#include <string>
    
using namespace std; 

class Employee : virtual public Person
{
    public:
      Employee();
      Employee(string name, string address, string telephone, string email, string office, int salary, string dateHired);
      string getOffice() const;
      int getSalary() const;
      string getDateHired() const;
      virtual string whatami() const;

    private:
      string office;
      int salary;
      string dateHired;
    }; 
    #endif

