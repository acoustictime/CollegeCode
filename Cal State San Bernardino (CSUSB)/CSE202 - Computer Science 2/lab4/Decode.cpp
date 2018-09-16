#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Code
{
public:
  
  Code();  // Default constructor - loads and uses morse code

  vector<string> decode(vector<string> message);  // decodes a message 



private:

  vector<string> codewords; // this is a codeword vector parallel to A-Z
  
  vector<char> alpha; // this is the vector for A-Z

  vector<char>  alphacode(); // function returns vector - A B C etc.

  vector<string>  morsecode(); // function returns vector containing morse code

  string decode(string c);

};



vector<char> Code::alphacode()
{// This returns a vector containing the alphabet a-z and " "
  vector<char> temp;
  
  for (char c='A'; c<='Z'; c++)
  {    
    temp.push_back(c);
   
  }
   temp.push_back(' ');
    temp.push_back('.');
  return temp;
}

vector<string> Code::morsecode()
{ // This function returns a vector containing the morse code
  vector<string> temp(28);
  temp[0] =".-";
  temp[1] ="-...";
  temp[2] ="-.-.";
  temp[3] ="-..";
  temp[4] =".";
  temp[5] ="..-.";
  temp[6] ="--.";
  temp[7] ="....";
  temp[8] ="..";
  temp[9] =".---";
  temp[10] ="-.-";
  temp[11] =".-..";
  temp[12] ="--";
  temp[13] ="-.";
  temp[14] ="---";
  temp[15] =".--.";
  temp[16] ="--.--";
  temp[17] =".-.";
  temp[18] ="...";
  temp[19] ="-";
  temp[20] ="..-";
  temp[21] ="...-";
  temp[22] =".--";
  temp[23] ="-..-";
  temp[24] ="-.--";
  temp[25] ="--..";
  temp[26] =".......";
  temp[27] ="x";
  return temp;
}



string Code::decode(string c)
{
  string temp;

  for (int i = 0; i < codewords.size(); i++)
  {
    if(c == codewords[i])
    {
      temp = alpha[i];
      return temp;
    }
  }
}

vector<string> Code::decode(vector<string> message)
{
  string temp;

  for(int i = 0; i < message.size(); i++)
  {
    temp = decode(message[i]);
    message[i] = temp;
  }

  return message;
  
}

Code::Code()
{
  alpha = alphacode();
  codewords = morsecode();

}

// main

int main()
{
   
  string temp;
  Code message;
  vector<string> encoded;
  vector<string> tempVector;


  cin >> temp;

  while (cin.good())
  {
    encoded.push_back(temp);

    cin >> temp;
  }

tempVector = message.decode(encoded);

for(int i = 0; i < tempVector.size(); i++)
  {
    cout << tempVector[i];
  }


}


