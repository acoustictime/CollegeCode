#include <iostream>
#include "Mlist.h"
#include <vector>

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




