#ifndef _Mlist_h
#define _Mlist_h

#include <vector>

using namespace std;

template<class T>
class Mlist
{
public:
    Mlist(T firstinline);//creates the list with a firstinline entry
    void add(T entry) {mlist.push_back(entry);}//add entry to the back of the list
    T next();//returns the front of the list and moves every entry up one position;
    bool empty() { return mlist.size() == 0; }// returns true if the list is empty
    void remove(T n);//searches the list and removes the entry with value n
private:
    vector<T> mlist;
}; // Mlist



#endif
