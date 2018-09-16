/****************************************************************************
 * K Zemoudeh
 * 1/30/11
 * variance1.cpp
 *
 * Problem: to compute the variance of set of numbers in a file.
 *
 * Algorithm: input the numbers in an array until EOF, compute variance using
 *            (sum from i=0 to n-1 of (pow(d[i]-avg, 2))) / (n-1)
 *            Maximum number of elements in the array is 100.
 *
 * Time complexity O(n), space complexity O(n)
 ****************************************************************************/

#include <iostream>

using namespace std;

// first computes average then variance based on the above formula
double variance(double *d, int n)
{
	int i;
	double sum, avg;

	if (n <= 1) return 0;

	sum = 0;
	for (i = 0; i < n; i++)
		sum += d[i];
	avg = sum/n;

	sum = 0;
	for (i = 0; i < n; i++)
		sum += (d[i]-avg)*(d[i]-avg);

	return sum/(n-1);
} // variance

// inputs the numbers until end-of-file, then calls variance
// maximum number of elements in the array is 100.
main()
{
	double a[100];
	int n;

	n = 0;
	while (cin >> a[n]) {
		n++;
		if (n == 100) break;
	}

	cout << "Variance = " << variance(a, n) << endl;
} // main
