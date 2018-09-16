/**************************************************************************
 James Small
 Date Start: 1-9-12  Date End: 1-14-12
 Filename: InfixPostfix.cpp
 Description: Program that takes as input a infix expression,
 and converts it to a postfix expression.
 **************************************************************************/
 

#include <iostream>
#include <string>
#include <stack>

using namespace std;

int precedence(char c);
bool isOperand(char c);

int main()
{
    string output = "Output: ";
    stack<char> operators;
    char input;
    
    cout << "Enter expression one char at a time, press $ or Ctrl D when expression is done:\n";
    cin >> input;
    
    while (!cin.eof() && input != '$') {  
        if (isOperand(input)) {   
            output += input;
        } else {
            if (input == '(' ) {
                operators.push(input);       
            } else if (input == ')' ) {
                while (!operators.empty() && operators.top() != '(') {
                    output += operators.top();
                    operators.pop();
                }
                
                if (!operators.empty() ) {
                    operators.pop();
                } else {
                    cout << "\nNo Matching (\n";
                    return 1;
                }
            } else if (operators.empty() || precedence(operators.top()) < precedence(input) ) {
                operators.push(input);
            } else if (precedence(operators.top()) >= precedence(input) ) {
                while (!operators.empty() && precedence(operators.top()) >= precedence(input) ) {          	        
                    output += operators.top();
                    operators.pop();
                }
                operators.push(input);
            } else {
                                                                   
            }
        }
        cin >> input;
    }
    
    while (!operators.empty() ) {
        output += operators.top();
        operators.pop();
    }
    
    cout << endl << output << endl;

} //main

/**************************************************************************
 Function Name: precedence
 Description: precedence takes as it's a argument a char, and returns an int
 representing the value of the char entered.  Controls order of
 prescedence of the operators used.
 **************************************************************************/

int precedence(char c) {
    if (c == '*' || c == '/' ) {
        return 2;
    } else if (c == '+' || c == '-' ) {
        return 1;
    } else {
        return 0;
    }
} //precedence

/**************************************************************************
 Function Name: isOperand
 Description: Fucntion takes as it's argument a char that was inputted by 
 the user, and returns true if it is a valid char in the specified range,
 or false if it is not.
 **************************************************************************/

bool isOperand(char c) {
    if (c >= 'a' && c <= 'z')
        return true;
    
    if (c >= 'A' && c <= 'Z')
        return true;
    
    if (c >= '0' && c <= '9')
        return true;

    return false;
} // isOperand
