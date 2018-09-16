#include "Person.h"
#include <string>
    
using namespace std; 

 Person::Person()
 {
   name = "";
   address = "";
   telephone = "";
   email = "";
 }

 Person::Person(string name, string address, string telephone, string email)
 { 
   this->name = name;
   this->address = address;
   this->telephone = telephone;
   this->email = email;
}

void Person::reset(string name, string address, string telephone, string email)
{ 
    this->name = name;
    this->address = address;
    this->telephone = telephone;
    this->email = email;
}

string Person::whatami() const
{
return "Person";
}

      
 string Person::getName() const
 {
   return name;
 }

 string Person::getAddress() const
 {
   return address;
 }

 string Person::getTelephone() const
 {
   return telephone;
 }

string Person::getEmail() const
 {
   return email;
 }
