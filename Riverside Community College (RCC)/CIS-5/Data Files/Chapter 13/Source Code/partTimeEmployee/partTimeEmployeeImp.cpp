#include <iostream>
#include <string>
#include "partTimeEmployee.h"

using namespace std;

void partTimeEmployee::print() const
{
      personType::print();      //print the name of the employee
      cout << " wages are: $" << calculatePay() << endl;
}

double partTimeEmployee::calculatePay() const
{
      return (payRate * hoursWorked);
}

void partTimeEmployee::setNameRateHours(string first, 
                string last, double rate, double hours)
{
      personType::setName(first, last);
      payRate = rate;
      hoursWorked = hours;
}

      //constructor 
partTimeEmployee::partTimeEmployee(string first, string last,
                                   double rate, double hours)

      : personType(first, last) 
{
      payRate = rate;
      hoursWorked = hours;
} 
