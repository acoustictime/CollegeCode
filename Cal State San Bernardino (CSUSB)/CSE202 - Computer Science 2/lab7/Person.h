 #ifndef PERSON_H
 #define PERSON_H
 
 #include <string>
    
 using namespace std; 

    class Person
    {
    public:
      Person();
      Person(string name, string address, string telephone, string email);
      string getName();
      string getAddress();
      string getTelephone();
      string getEmail();

    private:
      string name;
      string address;
      string telephone;
      string email;   
    }; 
    #endif

