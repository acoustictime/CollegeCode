#ifndef STAFF_H
#define STAFF_H
 
#include "Employee.h"
#include <string>
    
using namespace std; 

class Staff : public Employee
    {
    public:
      Staff();
      Staff(string name, string address, string telephone, string email, string office, int salary, string dateHired, string position);
      string getPosition() const;
      string whatami() const;


    private:
      string position;
    }; 
#endif

