#include "Person.h"
#include "Employee.h"
#include "Student.h"
#include "Faculty.h"
#include "Staff.h"
#include "StaffST.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;

string classify(Person * p);

int main()
{
   vector<Person*> v;

   v.push_back(new Person("Bob Smith","4690 Sierra","369-3095","bob@sierra.com"));
   v.push_back(new Student("James Small","1400 Barton","530-1290","james@barton.com","Junior"));
   v.push_back(new Staff("Fran Johnson","352 Capri","652-2345","fran@capri.com","English ",50000,"07/8/1981","Teacher"));
   v.push_back(new StaffST("Jenn Small","1453 Angel","784-1234","jenn@angel.com","Housing Office ",15000,"07/8/1994","Clerk","Junior",50));
   v.push_back(new Faculty("Anthony Marks","35 David St","456-0151","Anthony@david.com","Accounting Offce",240000,"05/16/2005","Professor","tenure"));
   v.push_back(new Employee("Nicole Withers","Fontana","135-535-PIZZ","nicole@fontana.com","CSE",25000,"5-21-85"));

   for (int i=0; i < v.size(); i++)
     {
       cout << endl << v[i]->getName() << " is a: " << classify(v[i]) << " class object" << endl;
     }

   cout << endl;

return 0;
}

string classify(Person * p)
{
  return p->whatami();
}





