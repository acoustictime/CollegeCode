 #ifndef STUDENT_H
 #define STUDENT_H
 
 #include <string>
    
 using namespace std; 

    class Student : public Person
    {
    public:
      Student();
      Student(string name, string address, string telephone, string email, string status);
      string getStatus();

    private:
      string status;   
    }; 
    #endif

