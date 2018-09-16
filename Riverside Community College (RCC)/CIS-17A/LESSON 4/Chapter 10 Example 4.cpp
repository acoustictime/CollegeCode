#include <iostream.h>

double factorial (double n);

int main (void) {
   double x;

      cout << "Enter an integer value> ";
   cin >> x;
   cout << "The factorial of " << x << " is " << factorial(x) << endl;
   return (0);
}

double factorial (double n) {
   int i;
   double f = 1.0;

   for (i = 1; i<=n; i++)
   f = f*i;
   return f;
}