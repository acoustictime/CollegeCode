/********************************************************************************
 James Small
 Date Start: 3-5-12 Date End: 3-11-12
 Filename: Set.h
 Description: This is the template class for my own Set Class.  The functions
 used were based on the Set_test.cpp file that was given to us.  This
 template class also contains the definition and functions for the
 Node class and the Set_iterator class.  The set is implemented using a binary
 tree to store the individual nodes with pointers between the parent and children
 of the tree.
 *******************************************************************************/

#ifndef SET_H
#define SET_H
#include <iostream>
#include <cassert>

using namespace std;

// Set.h - an implementation of Set using Node and Set_iterator

using namespace std;

template <class T> class Set;
template <class T> class Set_iterator;

template <class T>
class Node {
public:
    Node(): value(0), parent(0), leftChild(0), rightChild(0) { }
    Node(const T & x, Node * p, Node * lc, Node * rc): 
	value(x), parent(p), leftChild(lc), rightChild(rc) { }
    void insert(Node<T> * newNode); // this is a helper func for Set::insert()
    Node * find(const T & x);
    Node * merge(Node<T> * left, Node<T> * right);
protected:
	T value;
	Node * parent;
	Node * leftChild;
	Node * rightChild;

friend class Set<T>;
friend class Set_iterator<T>;
};

/**************************************************************************
 Function Name: insert(Node<T> * newNode)
 Description: Inserts the passed in Node into the binary tree.  It does this
              using recursion and finding the location in the binary tree
              where the node belongs.  
 **************************************************************************/

template <class T>
void Node<T>::insert(Node<T> * newNode) {
    if (newNode -> value <= value) {
        if (leftChild != 0)
            leftChild -> insert(newNode);
        else {
            newNode -> parent = this;
            leftChild = newNode;
        }
    }
    else {
        if (rightChild != 0)
            rightChild -> insert(newNode);
        else {
            newNode -> parent = this;
            rightChild = newNode;
        }
    }
}

/**************************************************************************
 Function Name: find(const T & x)
 Description: Searches through the binary tree looking for the passed in
              value.  If it finds it, returns a pointer to the node, if
              it doesn't, returns a null pointer.  Uses recursion.
 **************************************************************************/

template <class T>
Node<T> * Node<T>::find(const T & x) {

    if (value == x)
        return this;
    
    else if (x < value) 
        if (leftChild != 0) 
            return leftChild -> find(x);
    
    else if (x > value) 
        if (rightChild != 0)
            return rightChild -> find(x);

    return 0; 
}

/**************************************************************************
 Function Name: merge(Node<T> * left, Node<T> * right)
 Description: Merges two trees together into one.
 **************************************************************************/

template <class T>
Node<T> * Node<T>::merge(Node<T> * left, Node<T> * right) {

    if (left == 0) 
        return right;
    if (right == 0) 
        return left;
    
    Node<T> * child = merge(left, right -> leftChild);
    child -> parent = right;
    right -> leftChild = child;
    return right;
}

/**************************************************************************
 Class Name: Set
 **************************************************************************/


template <class T>
class Set {
public:
    typedef Set_iterator<T> iterator;

    Set(): root(0), my_size(0) { }
    bool empty() const { return root == 0; }
    unsigned int size() const { return my_size; }
    void insert(const T & x);
    void erase(iterator & it);
    void erase(const T & x) { root = remove(root, x); }
    unsigned int count(const T & x) const; // returns 1 or 0 because this is a set, not a multi-set
    iterator find(const T & x) const;
    iterator begin() const; // for in-order traversal
    iterator end() const { return iterator(0); }
protected:
    Node<T> * root;
    unsigned int my_size;
    Node<T> * remove(Node<T> *, const T &);
};

/**************************************************************************
 Function Name: insert(const T & x)
 Description: Set insert function that uses the Node insert function to place
              the passed in value into the binary tree.  
 **************************************************************************/

template <class T>
void Set<T>::insert(const T & x) {
    if(count(x) > 0)
        return;

    Node<T> * newNode = new Node<T>(x,0,0,0);

    if (root == 0)
       root = newNode;
    else
       root -> insert(newNode);

    my_size++;
}

/**************************************************************************
 Function Name: erase(iterator & it)
 Description: Erase function that erases the value at the passed in iterator
              location.  Checks if exists before hand.
 **************************************************************************/

template <class T>
void Set<T>::erase(iterator & it) {
  
    if (it.n != 0) // check if iterator is valid
        root = remove(root, *it);
}

/**************************************************************************
 Function Name: count(const T & x)
 Description: Counts number of occurances of passed in value.  Since just
              set and not multiset, just returns 1 if found, 0 if not.
 **************************************************************************/

template <class T>
unsigned int Set<T>::count(const T & x) const {
    
    Node<T> * temp = root;
    
    while (temp) {
        
        if (temp -> value == x)
            return 1;
        
        else if (x < temp -> value) 
            if (temp -> leftChild != 0) 
                temp = temp -> leftChild;
            else
                temp = 0;
        
        else if (x > temp -> value) 
                if (temp -> rightChild != 0)
                    temp = temp -> rightChild;  
                else
                    temp = 0;
    }
    return 0;
}

/**************************************************************************
 Function Name: find(const T & x)
 Description: Checks if root is value that you are looking for, if not,
              calls the find function from the Node Class and returns
              an iterator.
 **************************************************************************/

template <class T>
typename Set<T>::iterator Set<T>::find(const T & x) const { 

    if (root -> value == x) {
        return iterator(root);
    }
    
    return iterator(root -> find(x));
}

/**************************************************************************
 Function Name: begin()
 Description: Returns an iterator to the bottom left leaf in the tree.
 **************************************************************************/

template <class T>
typename Set<T>::iterator Set<T>::begin() const {
    Node<T> * n = root;
    
    while(n && n->leftChild)
        n = n->leftChild; 
    
    return iterator(n);
}

/**************************************************************************
 Function Name: remove(Node<T> * current, const T & testElement)
 Description: Using recursion starting from the passed in node pointer,
              removes all instanaces of the test element found in the tree
 **************************************************************************/

template <class T>
Node<T> * Set<T>::remove(Node<T> * current, const T & testElement) {
    
    if (current != 0) {
        Node<T> * pa = current -> parent;
        if (testElement < current -> value) 
            current -> leftChild = remove(current -> leftChild, testElement);
        else if (current -> value < testElement)
            current -> rightChild = remove(current -> rightChild, testElement);
        else {
            Node<T> * result = current->merge(remove(current->leftChild, testElement), current->rightChild);
            current->leftChild = current->rightChild = 0;
            delete current;
            
            if (my_size > 0) {
                my_size--;
            }
            if (result)
                result->parent = pa;
            return result;
        }              
    }    
    return current;
}

/**************************************************************************
 Class Name: Set_iterator
 **************************************************************************/

template <class T>
class Set_iterator {
public:
    Set_iterator(): n(0) { }
    Set_iterator(Node<T> * newNode): n(newNode) { }

    bool operator==(Set_iterator it) const { return n == it.n; }
    bool operator!=(Set_iterator it) const { return n != it.n; }
    Set_iterator & operator++(); // inorder traversal, pre-increment
    Set_iterator operator++(int); // inorder traversal, post-increment
    T & operator*() { return n->value; }
    Set_iterator & operator=(Set_iterator<T> it) { n = it.n; return *this; }
protected:
    Node<T> * n;

friend class Set<T>;
};

/**************************************************************************
 Function Name: operator++
 Description: advances iterator by one in LNR traversal order.  Pre increment
 **************************************************************************/

template <class T>
Set_iterator<T> & Set_iterator<T>::operator++() {
   
    if (n -> rightChild) {

        n = n -> rightChild;
        while (n && n -> leftChild)
            n = n -> leftChild;
    }
    else {

        Node<T> * child = n;
        n = n -> parent;
        while (n && n -> rightChild == child) {
            child = n;
            n = n -> parent;
        }
    }
    return *this;
}

/**************************************************************************
 Function Name: operator++(int)
 Description: advances iterator by one in LNR traversal order. Post increment
 **************************************************************************/

template <class T>
Set_iterator<T> Set_iterator<T>::operator++(int) {
    Set_iterator<T> temp(*this);
    operator++();
    return temp;
}

#endif
