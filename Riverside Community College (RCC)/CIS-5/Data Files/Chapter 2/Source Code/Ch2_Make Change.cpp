#include<iostream>
using namespace std;

int main()
{ 
  char string[30] , c;
  cout <<" 1.Testing cin.get with 2 arguments 
"<< endl;
  cout <<" Enter a name (first and last): " << endl;
  cin.get(string,30);
  cout << string << "  from get 2-args"<< endl;

//  Run without this line first.:  
//  cin.ignore(1,'\n'); // ignores one character or the endl. 
//  cin.get or cin.getline leaves the '\n' character in the input
//  stream.    

  cout <<" 2. Testing loop to build string
"<< endl;
  cout <<" Enter a name (first and last): " << endl;  
  int i = 0; 
  while (( c= cin.get()) != char (EOF))
    {
       string[i] = c; 
       i++;
    }
  string[i] = char (NULL);
  cout << string << "  from get 0-args" << endl;

//  Run  without this line first:
//  cin.clear(); // clears the input stream
// cin.get or cin.getline leaves the EOF at a true state unless you
// flush the input stream with .clear(). 

   cout <<" 3. Testing cin.getline
"<< endl;
  cout <<" Enter a name (first and last): " << endl;   
 cin.getline(string,30,'\n');
  cout << string << "  from getline '\\n' as delimiter" << endl;
 
    cout <<" 4. Testing cin with >>
"<< endl;
  cout <<" Enter a name (first and last): " << endl;  
  cin >> string;
  cout << string << "  with << operator" << endl;  
  
  return 0;
}