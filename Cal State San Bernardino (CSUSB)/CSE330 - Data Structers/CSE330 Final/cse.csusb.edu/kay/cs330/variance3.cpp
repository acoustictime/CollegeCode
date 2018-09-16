/****************************************************************************
 * K Zemoudeh
 * 1/30/11
 * variance3.cpp
 *
 * Problem: to compute the variance of set of numbers in a file.
 *
 * Algorithm: input the numbers in a vector until EOF, compute variance using
 *            (sum from i=0 to n-1 of (pow(d[i]-avg, 2))) / (n-1)
 *
 * Time complexity O(n), space complexity O(n)
 ****************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

// first computes average then variance based on the above formula
double variance(const vector<double> & d)
{
	int i, n;
	double sum, avg;

	n = d.size();
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
main()
{
	vector<double> v;
	double num;

	while (cin >> num)
		v.push_back(num);

	cout << "Variance = " << variance(v) << endl;
} // main
