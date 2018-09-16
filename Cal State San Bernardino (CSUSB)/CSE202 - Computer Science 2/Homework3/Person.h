 #ifndef PERSON_H
 #define PERSON_H
 
 #include <string>
    
 using namespace std; 

    class Person
    {
    public:
      Person();
      Person(string name, string address, string telephone, string email);
      string getName() const;
      string getAddress() const;
      string getTelephone() const;
      string getEmail() const;
      void reset(string name, string address, string telephone, string email);
      virtual string whatami() const;


    private:
      string name;
      string address;
      string telephone;
      string email;   
    }; 
    #endif

