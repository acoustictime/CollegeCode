/******************************************************
K Zemoudeh
2/10/10
mergeSort2.cpp

Merge Sort: uses inplaceMerge() by Budd with correction.
*******************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

template <class Itr>
void inplaceMerge(Itr start, Itr center, Itr stop)
{
	int dist = stop - start;
	vector<typename iterator_traits<Itr>::value_type> temp(dist);
	merge(start, center, center, stop, temp.begin());
	copy(temp.begin(), temp.end(), start);
}

template <class Itr>
void m_sort(Itr start, unsigned int low, unsigned int high)
{
	if (low + 1 < high) {
		unsigned int center = (low + high) / 2;
		m_sort(start, low, center);
		m_sort(start, center, high);
		inplaceMerge(start+low, start+center, start+high);
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
