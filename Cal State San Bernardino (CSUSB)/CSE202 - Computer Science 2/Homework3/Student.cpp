#include "Person.h" 
#include "Student.h"
#include <string>
    
using namespace std; 

Student::Student()
{
  status = "";
} 

Student::Student(string name, string address, string telephone, string email, string status):Person(name,address,telephone,email)
 {
   this->status = status;
 } 
      

string Student::getStatus() const
{
  return status;
}

string Student::whatami() const
{
return "Student";
}
