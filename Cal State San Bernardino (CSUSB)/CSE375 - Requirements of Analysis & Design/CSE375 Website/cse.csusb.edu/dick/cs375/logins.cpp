/* Example of code for a partial design for handing logins
	Ignores business rule: all passwords to be encrypted!
   RJBotting Started TDD
	Wed Feb 22 10:36:05 PST 2012
   Lunch...
   RJB did all but testing Administrator::remove(id)
	Wed Feb 22 13:08:23 PST 2012
   RJB Reviewed code and noticed an unprotected subscript.  "return people[i]"
	Thu Feb 23 06:55:30 PST 2012
   Done Thu Feb 23 07:01:54 PST 2012
   In class implemented Admin::remove()
   RJB noticed it did not match the design...  Fri Feb 24 07:28:58 PST 2012
*/
#include <iostream>
#include <string>
#include <map>
#include <cassert>

using namespace std;

class Person
{ public:
	Person(string i, string p);
	static Person * find(string i);
	static void insert(string i, Person * p);
	static void del(string i);// delete is a reserved word
	static Person * login(string i, string p);

	virtual void change(string p);
	virtual void del(); // delete is a reserved word in C++
	virtual Person * authenticate(string p);
  private: 
	string id;
	string pwd;
	static map<string,Person*> people;
};
class Administrator:public Person
{
  public:
	Administrator(string i, string p):Person(i,p){};

	virtual void add(string i, string p);
	virtual void remove(string i);

};

map<string,Person*> Person::people; // static inside Person.

Person::Person(string i, string p):id(i),pwd(p)
{
	insert(id,this);
}
Person * Person::find(string i)
{
	map<string,Person*>::iterator pi=people.find(i);
	if(pi==people.end())
		return NULL;
	else
		return people[i];
}
Person * Person::login(string i, string pw)
{
	Person * p = find(i);
        if(p)
		return p->authenticate(pw);
	else
		return NULL;
}
void Person::insert(string i, Person* p)
{
	Person::people[i]=p;
}
void Person::del(string i)
{
	people.erase(i);
}

void Person::change(string p)
{
	pwd=p;
}
void Person::del()
{
	del(id);
}
Person * Person::authenticate(string p)
{
	return (pwd==p?this:NULL);
}
//-------------
void Administrator::add(string i, string p)
{
	Person* old=find(i);
	if(! old)
	{
	   Person* newbie = new Person(i,p);
	   insert(i, newbie);
	}
}
void Administrator::remove(string i)
{
	Person* old=find(i);
	if( old)
	{
	   old->del();
	}
}
int main()//Unit tests
{
    const string myId = "rjb";
    Administrator * me = new Administrator(myId, "test");

    assert(Person::find(myId) == me );
    assert(me->authenticate("test") == me );
    assert(me->authenticate("toast") == NULL );

    assert(Person::find("who") == NULL);

    me->add("who","tardis");
    assert(Person::find("who"));

   //TO BE DONE tests of removal of who...  me->remove("who") ...
    me->remove("who");
    assert(Person::find("who")==NULL);

    assert(Person::login(myId, "Toast") == NULL);
    assert(Person::login("who", "tardis") == NULL);

    Administrator * miniMe = (Administrator *)Person::login(myId, "test");
    assert(me == miniMe);

    cout << "Success\n";
    return 0;
}

