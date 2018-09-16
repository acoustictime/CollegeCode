#include <iostream>
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

template<class T> //creates the list with a firstinline entry
Mlist<T>::Mlist(T firstinline)
{
    mlist.push_back(firstinline);
}


template<class T>//returns the front of the list and moves every entry up one position;
T Mlist<T>::next()
{
    T x; 
    if (mlist.size() > 0) 
    {
        x= mlist[0]; 
        
        for (int i=0; i<mlist.size()-1; i++) 
        {
            mlist[i]=mlist[i+1]; 
        }
        mlist.pop_back(); 
    } 
    return x;
}

template<class T> //searches the list and removes the entry with value n
void Mlist<T>::remove(T n)
{
    if(mlist.size() > 0)
    {
        for(int i =0;i < mlist.size()-1;i++)
        {
            if(mlist[i] == n)
            {
                for(int j = i;j < mlist.size()-1;j++)
                {
                    mlist[j] = mlist[j+1];
                }
                mlist.pop_back();
            }
        }
    }
}


int main()
{
    Mlist<int> test1(10);
    
    test1.add(5);
    test1.add(7);
    test1.add(4);
    
    test1.remove(7);
    
    cout << test1.next()<< endl;
    cout << test1.next()<< endl;
    cout << test1.next()<< endl;
   
    Mlist<string> test2("John");
    
    test2.add("Paul");
    test2.add("Mary");
    test2.add("Kate");
    test2.remove("Paul");
   
    cout << test2.next()<< endl;
    cout << test2.next()<< endl;
    cout << test2.next()<< endl;
}