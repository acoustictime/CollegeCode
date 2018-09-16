/* Demonstration code for the Minicalc example.
   See Minicalc.dia or Minicalc.png for design.
   Shows
	A composite pattern and
	a Strategy pattern

   Further work:   Make concrete Operators into singletons

   RJBotting March 2010
*/
#include <iostream>
using namespace std;

//-----------Operator hierarchy------------
class Operator { public: virtual int apply(int l, int r)=0; };
class Addition:public Operator { 
	public: int apply(int l, int r){return l+r;}
};
class Multiplication:public Operator { 
	public: int apply(int l, int r){return l*r;}
};
//-----------Expression hierarchy------------
class Expression { 
  public: virtual int evaluate()const=0; 
};
class Constant: public Expression {
  public: int evaluate()const{return value;}
	Constant (int v):value(v){}
  private: int value;
};
class Operation: public Expression {
  public: 
	Operation (Expression *l0, Operator* op0, Expression *r0)
		: l(l0),r(r0),op(op0){}
	int evaluate()const
	{
		int lv=l->evaluate();
		int rv=r->evaluate();
		return op->apply(lv,rv);
	}
  private: Expression *l;
	   Expression *r;
	   Operator   *op;
};

int main()
{
   Operator* addition = new Addition();
   Operator* multiplication = new Multiplication();
   cout << "2+1=" << addition->apply(1,2) << "\n";
   cout << "2*1=" << multiplication->apply(1,2) << "\n";

   Expression * one = new Constant(1);
   Expression * two = new Constant(2);
   Expression * three = new Constant(3);
   cout << one->evaluate()<<"\n";

   Expression * alpha = new Operation (two, multiplication, three); // 2*3
   cout << alpha->evaluate()<< "\n";
   Expression * beta = new Operation (one, addition, alpha); // 1+2*3
   cout << beta->evaluate()<< "\n";

   return 0;
}

