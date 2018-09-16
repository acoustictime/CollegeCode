#ifndef STAFFST_H
#define STAFFST_H
 
#include "Student.h"
#include "Staff.h"
#include <string>
    
using namespace std; 

class StaffST : public Staff, public Student
    {
    public:
      StaffST();
      StaffST(string name, string address, string telephone, string email, string office, int salary, string dateHired, string position, string status, int creditHours);
      int getCreditHours() const;
      virtual string whatami() const;

    private:
        int creditHours;
    }; 
#endif

