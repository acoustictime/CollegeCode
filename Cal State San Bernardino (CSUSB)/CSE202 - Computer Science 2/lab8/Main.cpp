#include "Data.h"
#include <iostream>

using namespace std;

int main()
{
  Data d1, d2, d3;
  d1.addData(10);
  d1.addData(20);
  d1.addData(30);
  d2.addData(10);
  d2.addData(20);
  d2.addData(30);
  d3.addData(10);
  d3.addData(25);
  d3.addData(30);
  
  if (d1 == d2) cout << "d1=d2" << endl;
  
  if (d2 == d3) cout << "d2=d3" << endl;
  else cout << "d2 != d3" << endl;
  
  cout << "d1 benchmark " << d1.getbenchmark() <<endl;
  cout << "d2 benchmark " << d2.getbenchmark() <<endl;
  cout << "d3 benchmark " << d3.getbenchmark() <<endl;
  
  d1.changebenchmark(100);
  
  cout << "new d1 benchmark " << d1.getbenchmark() <<endl;
  cout << "new d2 benchmark " << d2.getbenchmark() <<endl;
  cout << "new d3 benchmark " << d3.getbenchmark() <<endl;


  d1.deleteData(20);

  vector<int> temp = d1.getData();

  for (int i = 0;i < temp.size();i++)
  {
    cout << endl << temp[i] << endl;
  }

return 1;
}


