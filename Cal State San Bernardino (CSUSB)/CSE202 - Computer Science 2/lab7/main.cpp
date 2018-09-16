#include "Person.h"
#include "Employee.h"
#include "Student.h"
#include "Faculty.h"
#include "Staff.h"
#include <string>
#include <iostream>

using namespace std;

int main()
{
  Person p("Bob","4690 Sierra","369-3095","bob@sierra.com");
  
  cout << p.getName() << endl;
  cout << p.getAddress() << endl;
  cout << p.getTelephone() << endl;
  cout << p.getEmail() << endl;

  Student s("James","1400 Barton","530-1290","james@barton.com","Junior");

  cout << endl << s.getName() << endl;
  cout << s.getAddress() << endl;
  cout << s.getTelephone() << endl;
  cout << s.getEmail() << endl;
  cout << s.getStatus() << endl;


  Employee e("Mark","154 Smith","456-7894","mark@smith.com","CSE Office",50000,"01/16/1982");

  cout << endl << e.getName() << endl;
  cout << e.getAddress() << endl;
  cout << e.getTelephone() << endl;
  cout << e.getEmail() << endl;
  cout << e.getOffice() << endl;
  cout << e.getSalary() << endl;
  cout << e.getDateHired() << endl;


  Faculty f("Anthony","35 David St","456-0151","Anthony@david.com","Accounting Offce",240000,"05/16/2005","Professor","tenure");

  cout << endl << f.getName() << endl;
  cout << f.getAddress() << endl;
  cout << f.getTelephone() << endl;
  cout << f.getEmail() << endl;
  cout << f.getOffice() << endl;
  cout << f.getSalary() << endl;
  cout << f.getDateHired() << endl;
  cout << f.getRank() << endl;
  cout << f.getStatus() << endl;

  Staff st("Jenn","1453 Angel","784-1234","jenn@angel.com","Housing Office ",15000,"07/8/1994","Clerk");

  cout << endl << st.getName() << endl;
  cout << st.getAddress() << endl;
  cout << st.getTelephone() << endl;
  cout << st.getEmail() << endl;
  cout << st.getOffice() << endl;
  cout << st.getSalary() << endl;
  cout << st.getDateHired() << endl;
  cout << st.getPosition() << endl;

  cout << endl << "The end!" << endl;


return 0;
}







