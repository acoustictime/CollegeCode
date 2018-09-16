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

  int choice = 0;

  cout << "What would you like to do?\n";
  cout << "\n1. Add Username and Password";
  cout << "\n2. Check Password for a User";
  cout << "\n3. Update Password for a User";
  cout << "\n4. Delete Username and Password\n";
  cout << "Enter Choice 1-4: ";

  cin >> choice;

  while(choice > 4 || choice < 1)
  {
    cout << "Enter Choice 1-4: ";
    cin >> choice;
  }

  string user, password;

  switch(choice)
  {
    case 1:
      cout << "Enter a user name: ";
      cin >> user;
      cout << "Enter a password for the user " << user << ": ";
      cin >> password; 
      passfile.addpw(UserPw(user,password));
      break;
    case 2:
      cout << "Enter a user name: ";
      cin >> user;
      cout << "Enter a password for the user " << user << ": ";
      cin >> password; 
      if(passfile.checkpw(user,password))
      {
        cout << "\nCredentials are valid\n\n";
      }
      else
      {
        cout << "\nCredentials are invalid\n\n";
      }
      break;
    case 3:
      cout << "Enter a user name: ";
      cin >> user;
      cout << "Enter a password for the user " << user << ": ";
      cin >> password; 
      passfile.updatepw(UserPw(user,password));
      break;
   case 4:
      cout << "Enter a user name: ";
      cin >> user;
      cout << "Enter a password for the user " << user << ": ";
      cin >> password; 
      passfile.deletepw(UserPw(user,password));
      break;
   default:
      break;
  }

  vector<UserPw> test2 = passfile.getFile();

  for(int i = 0; i < test2.size();i++)
  {
    cout << test2[i].GetUser() << " " << test2[i].GetPassword() << endl;
  }
  
  cout << endl;

 
}
