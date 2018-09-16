#include <string>
#ifndef USERPW_H
#define USERPW_H

using namespace std;

class UserPw
{
  public:
    UserPw(string user, string password);   //Constructor
    string GetUser(); // returns the user
    string GetPassword();
    bool Checkpw(string user, string passwd); // returns true is user and password both match
 
  private :
    string user;
    string password;
};
#endif

double calculatePay(double rate, double hours);

double hourlyRate = 23.00;
double hoursWorked = 45.75;

Employee employee;

double pay = employee.calculatePay(hourlyRate, hoursWorked);

