 #ifndef FACULTY_H
 #define FACULTY_H

 #include "Employee.h" 
 #include <string>
    
 using namespace std; 

    class Faculty : public Employee
    {
    public:
      Faculty();
      Faculty(string name, string address, string telephone, string email, string office, int salary, string dateHired, string rank, string status);
      string getRank() const;
      string getStatus() const;
      virtual string whatami() const;

    private:
      string rank;
      string status;
    }; 
    #endif

