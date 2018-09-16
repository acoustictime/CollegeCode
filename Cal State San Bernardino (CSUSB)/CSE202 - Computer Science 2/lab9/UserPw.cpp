#include <string>
#include "UserPw.h"

using namespace std;

UserPw::UserPw(string user, string password)
{
  this->user = user;
  this->password = password;
}

string UserPw::GetUser()
{
  return user;
}

string UserPw::GetPassword()
{
  return password;
}

bool UserPw::Checkpw(string user, string passwd)
{
  if(this->user == user && this->password == passwd)
  {
    return true;
  }

  return false;
}
