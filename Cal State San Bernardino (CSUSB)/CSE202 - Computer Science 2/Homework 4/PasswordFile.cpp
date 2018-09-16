#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include "UserPw.h"
#include "PasswordFile.h"

using namespace std;

PasswordFile::PasswordFile(string filename)
{
  this->filename = filename;

  ifstream infile;
  
  infile.open(filename.c_str());

  if(infile.good())
  {
    string n, p;

    infile >> n >> p;

    while(infile.good())
    {
      entry.push_back(UserPw(n,p));
      
      infile >> n >> p;
    }
  
    infile.close();
  }
  else
  {
    ofstream outfile;

    outfile.open(filename.c_str());
    outfile.close();
  }
}

vector<UserPw> PasswordFile::getFile()
{
  return entry;
}

void PasswordFile::addpw(UserPw newentry)
{
  entry.push_back(newentry);

  this->writeToFile(); 
}

bool PasswordFile::checkpw(string user, string passwd)
{
  for(int i = 0;i < entry.size();i++)
  {
    if(entry[i].GetUser() == user)
    {
      if(entry[i].Checkpw(user,passwd))
      {
        return true;
      }
    }  
  }
  return false;
}

void PasswordFile::updatepw(UserPw updateentry)
{
  for(int i = 0;i < entry.size();i++)
  {
    if(entry[i].GetUser() == updateentry.GetUser())
    {
      entry[i] = updateentry;
    }
  }

  this->writeToFile(); 
}

void PasswordFile::writeToFile()
{
  ofstream of;
  
  of.open(filename.c_str());

  for (int i = 0; i < entry.size();i++)
  {
    of << entry[i].GetUser() << " " << entry[i].GetPassword() << endl;
  }

  of.close();
}

    
void PasswordFile::deletepw(UserPw deleteentry)
{
  vector<UserPw>::iterator it;
  
  for(it = entry.begin();it != entry.end();it++)
  {
    if(it->GetUser() == deleteentry.GetUser())
    {
      entry.erase(it);
    } 
  }

  this->writeToFile(); 
}
