 #ifndef PERSON_H
    #define PERSON_H
    #include <string>
    using namespace std; 

    class Person
    {
    public:
        Person();
        Person(string fname, string lname, string cname);
        string getFirstName();
        string getName();
        string getLastName();
        string getCompany();
    private:
        string firstname;
        string lastname;
        string company; 
    }; // Person
    #endif
