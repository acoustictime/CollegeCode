#include <iostream>
#include "UserPw.h"
#include "PasswordFile.h"

using namespace std;

int main()
{
  PasswordFile passfile("password.txt");
  passfile.addpw(UserPw("dbotting","123qwe"));
  passfile.addpw(UserPw("egomez","qwerty"));
  passfile.addpw(UserPw("tongyu","liberty"));


  vector<UserPw> test = passfile.getFile();

  for(int i = 0; i < test.size();i++)
  {
    cout << test[i].GetUser() << " " << test[i].GetPassword() << endl;
  }
  
  cout << endl;

  string user, password;

  cout << "Enter a user name: ";
  cin >> user;
  cout << "Enter a password for the user " << user << ": ";
  cin >> password;

  if(passfile.checkpw(user,password))
  {
    cout << "Valid Login Credentials\n";
  }
  else
  {
    cout << "Invalid Valid Login Credentials\n";
  }
}
