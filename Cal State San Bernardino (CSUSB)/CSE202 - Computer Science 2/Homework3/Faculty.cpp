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
  reset(name,address,telephone,email);
}
    
string Faculty::getRank() const
{
  return rank;
}

string Faculty::getStatus() const
{
  return status;
}

string Faculty::whatami() const
{
return "Faculty";
}
