 #ifndef EMPLOYEE_H
 #define EMPLOYEE_H

#include <string>
    
 using namespace std; 

    class Employee : public Person
    {
    public:
      Employee();
      Employee(string name, string address, string telephone, string email, string office, int salary, string dateHired);
      string getOffice();
      int getSalary();
      string getDateHired();

    private:
      string office;
      int salary;
      string dateHired;
    }; 
    #endif

