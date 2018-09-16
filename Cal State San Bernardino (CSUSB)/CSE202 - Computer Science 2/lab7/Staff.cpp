 #include "Employee.h" 
#include "Staff.h"
 #include <string>
    
 using namespace std; 

Staff::Staff()
{
  position = "";
}

Staff::Staff(string name, string address, string telephone, string email, string office, int salary, string dateHired, string position):Employee(name,address,telephone,email,office,salary,dateHired)
{
  this->position = position;
}
      
string Staff::getPosition()
{
  return position;
}
