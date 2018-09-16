#include "Data.h"
#include <vector>

using namespace std;  

int Data::benchmark = 10;

Data::Data()
{
}

void Data::addData(int x)
{
  data.push_back(x);
}

bool Data::operator == (Data other) const
{
  vector<int> temp = other.getData();

  if(this->data.size() != temp.size())
  {
    return false;
  }

  for(int i = 0; i < temp.size(); i++)
  {
    if(this->data[i] != temp[i])
    {
      return false;
    }
  }
  return true;
}

void Data::changebenchmark(int newbenchmark)
{
  benchmark = newbenchmark;
}

vector<int> Data::getData() const
{
  return data;
}

int Data::getbenchmark() const
{
  return benchmark;
}

void Data::deleteData(int x)
{
  vector<int>::iterator it;

  for(it = data.begin();it != data.end(); it++)
  {
    if(*it == x)
    {
      data.erase(it);
    }
  }
}


