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
      
 string Person::getName()
 {
   return name;
 }

 string Person::getAddress()
 {
   return address;
 }

 string Person::getTelephone()
 {
   return telephone;
 }

string Person::getEmail()
 {
   return email;
 }
