/************************************************************************
K Zemoudeh
6/2/08
mergeSort3.cpp

Merge Sort: this version illustrates one implementation of Inplace Merge.
*************************************************************************/

#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

template<class Itr> 
void inplaceMerge(Itr low, Itr mid, Itr high)
{
	// int dist = high - low;
	// the following line works too:
	typename iterator_traits<Itr>::difference_type dist = high - low;
	vector<typename iterator_traits<Itr>::value_type> temp(dist);
	Itr i = low;
	Itr j = mid;
	Itr k = temp.begin();

	while (i < mid && j < high)
		if (*i < *j)
			*k++ = *i++;
		else
			*k++ = *j++;
	while (i < mid)
		*k++ = *i++;
	while (j < high)
		*k++ = *j++;

	for (k = temp.begin(), i = low; k != temp.end(); k++, i++)
		*i = *k;
} // inplaceMerge
		

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
