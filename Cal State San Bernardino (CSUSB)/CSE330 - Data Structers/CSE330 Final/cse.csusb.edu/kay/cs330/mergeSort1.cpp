/********************************************
K Zemoudeh
6/2/08
mergeSort1.cpp

Merge Sort: uses inplace_merge() from STL.
*********************************************/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <class Itr>
void m_sort(Itr start, unsigned int low, unsigned int high)
{
	if (low + 1 < high) {
		unsigned int center = (low + high) / 2;
		m_sort(start, low, center);
		m_sort(start, center, high);
		inplace_merge(start+low, start+center, start+high);
	}
} // m_sort

template <class T>
void mergeSort(vector<T> & s)
{
	m_sort(s.begin(), 0, s.size());
} // mergeSort

main()
{
	vector<int> v;
	int temp;

	while (cin >> temp)
		v.push_back(temp);

	mergeSort(v);

	for (int i = 0; i < v.size(); i++)
		cout << v[i] << ' ';
	cout << endl;
} // main
