 #ifndef STUDENT_H
 #define STUDENT_H

 #include "Person.h"
 #include <string>
    
 using namespace std; 

    class Student : virtual public Person
    {
    public:
      Student();
      Student(string name, string address, string telephone, string email, string status);
      string getStatus() const;
      virtual string whatami() const;

    private:
      string status;   
    }; 
    #endif

