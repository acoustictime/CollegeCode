 #include "Employee.h" 
#include "Faculty.h"
 #include <string>
    
 using namespace std; 

 Faculty::Faculty()
{
  rank = "";
  status = "";
}

 Faculty::Faculty(string name, string address, string telephone, string email, string office, int salary, string dateHired, string rank, string status) : Employee(name,address,telephone,email,office,salary,dateHired)
{
  this->rank = rank;
  this->status = status;
}
    
string Faculty::getRank()
{
  return rank;
}

string Faculty::getStatus()
{
  return status;
}

