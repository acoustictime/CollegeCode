 #ifndef FACULTY_H
 #define FACULTY_H
 #include <string>
    
 using namespace std; 

    class Faculty : public Employee
    {
    public:
      Faculty();
      Faculty(string name, string address, string telephone, string email, string office, int salary, string dateHired, string rank, string status);
      string getRank();
      string getStatus();

    private:
      string rank;
      string status;
    }; 
    #endif

