/***********************************************************************
* Header:
*    LIST
* Summary:
*    An implementation of the std::list class
* Author
*    Nathan Bench, Jed Billman, Jeremy Chandler, Justin Chandler
************************************************************************/

#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <cassert>


// forward declarations
template <class T>            // 49
class Node;

template <class T>
class ListIterator;           // 199

template <class T>
class ListConstIterator;

/****************************************************
* LIST
* A class that holds things in a list
*****************************************************/
template <class T >
class List
{
public:
	List(): pHead(NULL), pTail(NULL), numItems(0) {};
	List(List & rhs) {};
	~List() {};
   
   // std container interfaces
	bool empty()         { return !pHead && !pTail && (numItems == 0); }
	int size()           { return numItems;                            }
	void clear();
   
   // list specific
	void push_back(T & item) throw (const char *);
	void push_front(T & item) throw (const char *);
	void remove(ListIterator & it) throw (const char *);
	T front() throw (const char *);
	T back(); throw (const char *);
   
   // iterators
	ListIterator insert(T & item) throw (const char *);
	
	ListIterator begin()    { return ListIterator(pHead->data); }
	ListIterator rbegin()   { return ListIterator(pTail->data); }
	ListIterator end()      { return ListIterator(pHead->pNext->data); }
	ListIterator rend()     { return ListIterator(pHead->pPrev->data); }

private:
   Node <T> * pHead;
   Node <T> * pTail;
   int numItems;
};

/***********************************************
 * Node
 * A node to be used in a linked list
 **********************************************/
template <class T>
class Node
{
   public:
      // constructors
      Node(): pNext(NULL), pPrev(NULL) {}
      Node(const T & t): data(t), pNext(NULL), pPrev(NULL) {}
      
      // members
      Node <T> * pNext, * pPrev;
      T data;
};

/***********************************************
* COPY
* Copy a linked­list. Takes a pointer to a Node as a parameter and returns a newly
* created linked­list containing a copy of all the nodes below the list represented by the
* parameter. This should be a non­member function.
***********************************************/
template <class T>
Node <T> * Node <T> :: copy(const Node <T> * pSource) throw (const char *)
{
   // trivial case
   if (NULL == pSource)
      return NULL;
   
   try
   {
      // allocate a new head
      Node <T> * pDestination = new Node <T> (pSource->data);
      Node <T> * pCurrent = pDestination;

      // loop through the rest of the source linked list
      while (pSource->pNext)
      {
         pSource = pSource->pNext;
         pCurrent->pNext = new Node <T> (pSource->data);
         pCurrent = pCurrent->pNext;
      }

      return pDestination;
   }
   catch(std::bad_alloc)
   {
      throw "ERROR: Failed to allocate memory for list\n";
   }
}

/***********************************************
* INSERT
* Insert a new Node into the current linked­list. The first parameter is the value to
* be placed in the new Node. The second parameter is the Node preceding the new Node in the
* list. An optional third parameter is set to true if the new item is to be at the head of the
* list. Please return a pointer to the newly created Node. This should be a non­member function.
***********************************************/
template <class T>
Node <T> * Node <T> :: insert(const T & t, Node <T> * &pCurrent, bool isHead = false)
{  
   try
   {
      Node <T> * pNew = new Node <T>(t);
      // IF NULL
      if (pCurrent == NULL)
      {
         pCurrent = pNew;
         pCurrent->pNext = NULL;
         return pNew;
      }
      
      // IF isHead
      if (pCurrent != NULL && isHead)
      {
         pNew->pNext = pCurrent;
         pCurrent = pNew;
         return pCurrent;
      }
      
      // IF !isHead
      if (pCurrent != NULL && !isHead)
      {
         pNew->pNext = pCurrent->pNext;
         pCurrent->pNext = pNew;
         return pNew;
      }
   }
   catch(std::bad_alloc)
   {
      throw "ERROR: bad_alloc";
   }

}

/***********************************************
* FIND
* Find the Node corresponding to a given passed value from a given linked­list. The
* first parameter is a pointer to the front of the list, the second is the value to be found. The
* return value is a pointer to the found node if one exists. This should be a non­member
* function.
***********************************************/
template <class T>
Node <T> * Node <T> :: find(Node <T> * pHead, const T & t)
{
 for (Node<T> * p = pHead; p; p=p->pNext)
 {
   if (p->data == t)
    return p;
 }  
 return NULL;
}

/***********************************************
* EXTRACTION OPERATOR <<
* Display the contents of a given linked list.
***********************************************/
template <class T>
std::ostream & Node <T> :: operator << (std::ostream & out, Node <T> * pHead)
{
   for (Node <T> * p = pHead; p; p = p->pNext)
   {
      out << p->data;
    if (p->pNext != NULL)
     out << ", ";
   }
   
   return out;
}

/***********************************************
* FREE DATA
* Release all the memory contained in a given linked­list. The one parameter is a
* pointer to the head of the list. This should be a non­member function.
***********************************************/
template <class T>
void Node <T> :: freeData(Node <T> * &pHead)
{   
    while (pHead != NULL)
   {
     Node <T> * p = pHead;
     pHead = pHead->pNext;
     delete p;
   }
 
}



/************************************************
* LIST ITERATOR
* An iterator through List
*************************************************/
template <class T>
class ListIterator
{
public:
	// default constructor
	ListIterator() : p(NULL) {}
	// point to some item "p"
	ListIterator(T * p) : p(p){};
	// copy constructor
	ListIterator(const ListIterator & rhs) { *this = rhs; }
	//assignment operator
	ListIterator & operator = (const ListIterator & rhs)
	{
		this->p = rhs.p;
		return *this;
	}
	//prefix increment
	ListIterator <T> & operator ++ ()
	{
		p++;
		return *this;
	}
	//postfix increment 
	ListIterator <T> & operator++(int postfix)
	{
		ListIterator temp(*this);
		p++;
		return temp;
	}

private:
	T * p
};

template<class T>
void List<T> :: clear()
{

}

template<class T>
void List<T> :: push_back(T & item) throw(const char *)
{
	l_size++;
}

template<class T>
void List<T>::push_front(T & item) throw(const char *)
{

}

template<class T>
void List<T>::remove(ListIterator<T>& it) throw(const char *)
{

}

template<class T>
T List<T>::front() throw(const char *)
{
	return T();
}

template<class T>
T List<T>::back() throw(const char *)
{
	return T();
}

template<class T>
ListIterator<T> List<T>::insert(T & item, ListIterator it) throw(const char *)
{
	return ListIterator<T>();
}

#endif // LIST_H
