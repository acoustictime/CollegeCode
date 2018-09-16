#include <string>
#ifndef USERPW_H
#define USERPW_H

using namespace std;

class UserPw
{
  public:
    UserPw(string user, string password);   //Constructor
    string GetUser(); // returns the user
    string GetPassword();
    bool Checkpw(string user, string passwd); // returns true is user and password both match
 
  private :
    string user;
    string password;
};
#endif
