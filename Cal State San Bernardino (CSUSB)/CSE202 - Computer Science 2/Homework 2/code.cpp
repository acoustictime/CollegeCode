/**
 @file Code.cpp
 @author James Small
 @date 2011-10-23
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Code
{
public:
    
    Code();  // Default constructor - loads and uses morse code
    
    Code(vector<int> codewords);  // constructor loading customized code
    
    string encode(vector<char> message);  // encodes a message consisting of A-Z
    
    string decode(vector<string> message);  // decodes a message 
    
private:
    
    vector<string> codewords; // this is a codeword vector parallel to A-Z
    
    vector<char> alpha; // this is the vector A-Z
    
    vector<char>  alphacode(); // function returns vector - A B C etc.
    
    vector<string>  morsecode(); // function returns vector containing morse code
    
    string encoder(char x); //returns the codeword for the character x
    
    string decoder(string c); //returns the character for the codeword c.
    
};

Code::Code() // Default constructor
{
    alpha = alphacode(); // returns alphacode vector and stores in alpha vector
    codewords = morsecode(); // returns morsecode vector and stores in morse vector
}

Code::Code(vector<int> codewords) // Used only if wanting to define on codeset
{
}

//Public encode function that takes a vector<char> as argument containing message to encode

string Code::encode(vector<char> message)
{
    string temp; // temp variable used when returning encoded character
    string final; // stores final encoded message
    
    for(int i = 0; i < message.size(); i++) // process through vector
    {
        temp = encoder(message[i]); // pass [i] element to encoder function
        final.append(temp); // append to final message string
        final.append(" "); // add space after every character
    }
    
    return final; 
}

//Public decode vector function that takes a vector<string> as argument containing message to decode

string Code::decode(vector<string> message)
{
    string temp; // temp variable used when returning decoded string
    string final; // stores final decoded messge
    
    for(int i = 0; i < message.size(); i++) // process through vector
    {
        temp = decoder(message[i]); // pass [i] element to decoder function
        final.append(temp); // append to final message string
    }
    
    return final;
    
}

// This returns a vector containing the alphabet a-z and " "

vector<char> Code::alphacode()
{
    vector<char> temp; // vector of chars
    
    for (char c='A'; c<='Z'; c++) //loop through to add A-Z to vector
    {    
        temp.push_back(c);
    }
    
    temp.push_back(' '); // add space to vector
    temp.push_back('.'); // add . to vector
    
    return temp;
}

// This function returns a vector containing the morse code

vector<string> Code::morsecode()
{ 
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

//Encoder function that takes a char and returns a corresponding match from parallel vector

string Code::encoder(char x)
{
    string temp; // temp variable

    for(int i = 0; i < alpha.size(); i++) // loop through alpha vector looking for match
    {
        if(alpha[i] == x) // if found match to x
        {
            temp = codewords[i]; // parallel vector item for matching char
            return temp; // return match
        }     
    }
}

//Decoder function that takes a string and returns a corresponding match from the parallel vector

string Code::decoder(string c)
{
    string temp; // temp variable
    
    for(int i = 0; i < codewords.size(); i++) // loop through codewords vector looking for match
    {
        if(codewords[i] == c) // if found match for c
        {
            temp = alpha[i]; // parallel vector item for matching string
            return temp; // return match
        }     
    }
}

// Main Program

int main()
{
    string in; // used to read in string for morsecode message
    char in2; // used to read in char for alpha message
    vector<string> message; // vector containing morsecode message read in from file
    vector<char>message2; // vector containing alpha message read in from file
    
    Code input; // object file

    cin >> in2; // read in first character to determine if file contains morse or alpha
    
    cin.putback(in2); // puts the read in character back into the stream before reading in full file
    
    if(in2 == '.' || in2 == '-') //if first character is from morsecode
    {
        cin >> in; // read in first string
    
        while(cin.good()) // while good
        {
            message.push_back(in); // add read in string to vector
            cin >> in; // read in next string
        }
    
        // pass vector containing message to input object decode function and output string with deocded message
        
        cout << endl << input.decode(message); 
    }
    else // if first character is from alpha message
    {
        cin >> noskipws >> in2; // read in first char, but don't skip spaces between words
        
        while(cin.good()) // while input is good
        {
            message2.push_back(in2); // add read in char to vector
            cin >> noskipws >> in2; // read in next char not skipping spaces between words
        }
        
        // pass vector containing message to input object encode function and output string with encoded message
        
        cout << endl << input.encode(message2);
    }
    
  return 0;
}
