// Postfix Calculator  

#include <iostream>
#include <iomanip>
#include <fstream>
#include "mystack.h"

using namespace std;

void evaluate(ofstream& out,stackType<double>& stack,
			  char& ch,bool& expressionOk);
void discard(ifstream& in, ofstream& out, char& ch);

int main()
{
    double num, result;  
    bool expressionOk;
    char ch;
    stackType<double> stack(100);
    ifstream infile;
    ofstream outfile;
 
    infile.open("a:\\RpnData.txt");

    if(!infile)
    {
        cout << "Cannot open the input file. "
             << "Program terminates!" << endl;
        return 1;
    }

    outfile.open("a:\\RpnOutput.txt");

    outfile << fixed << showpoint;
    outfile << setprecision(2); 

    infile >> ch;
    while(infile)
    {
        stack.initializeStack();
        expressionOk = true;
        outfile << ch;

        while (ch != '=')
        {
            switch (ch)
            {
            case '#': infile >> num;
                      outfile << num << " ";
                      if (!stack.isFullStack())
                          stack.push(num);
                      else
                      {
                          cout << "Stack overflow. "
                               << "Program terminates!" 
                               << endl;
                          return 1;
                      }

                      break;
            default: evaluate(outfile, stack, ch, expressionOk);

            }//end switch

            if (expressionOk) //if no error
            {
                infile >> ch;
                outfile << ch;

                if (ch != '#')
                    outfile << " ";
            }
            else
                discard(infile, outfile, ch);
        }//end while (!= '=')

        if (expressionOk) //if no error, print the result
        {
            if (!stack.isEmptyStack())
            {
                result = stack.top();
                stack.pop();

                if (stack.isEmptyStack())
                    outfile << result << endl;
                else
                    outfile << " (Error: Too many operands)"
                            << endl;
            }//end if
            else
                outfile << " (Error in the expression)" << endl;
        }
        else
            outfile << " (Error in the expression)" << endl;

        outfile << "_________________________________" 
                << endl << endl;

        infile >> ch; //begin processing the next expression
    }//end while 

    infile.close();
    outfile.close();

    return 0;

}//end main

void evaluate(ofstream& out, stackType<double>& stack,
              char& ch, bool& expressionOk)
{
    double op1, op2;

    if (stack.isEmptyStack())
    {
        out << " (Not enough operands)";
        expressionOk = false;
    }
    else
    {
        op2 = stack.top();
        stack.pop();

        if (stack.isEmptyStack())
        {
            out << " (Not enough operands)";
            expressionOk = false;
        }
        else
        {
            op1 = stack.top();
            stack.pop();

            switch (ch)
            {
            case '+': stack.push(op1 + op2);
                      break;
            case '-': stack.push(op1 - op2);
                      break;
            case '*': stack.push(op1 * op2);
                      break;
            case '/': if (op2 != 0)
                          stack.push(op1 / op2);
                      else
                      {
                          out << " (Division by 0)";
                          expressionOk = false;
                      }
                      break;
            default:  out << " (Illegal operator)";
                      expressionOk = false;
            }//end switch
        }//end else
    }//end else
}//end evaluate

void discard(ifstream& in, ofstream& out, char& ch)
{
   while(ch != '=')
   {
	     in.get(ch);
	     out << ch;
   }
}//end discard
