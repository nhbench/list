/***********************************************************************
 * Header:
 *    NODE
 * Summary:
 *    This will contain the definition and implementation of the Node class
 * Author
 *    Nathan Bench, Jed Billman, Jeremy Chandler, Justin Chandler
 ************************************************************************/
 
/***********************************************
 * TODO
 * WRITE function definitions
 * REPLACE comment descriptions
 **********************************************/
 
#ifndef NODE_H
#define NODE_H

#include "node.h"
#include <iostream>

/***********************************************
 * Node
 * A node to be used in a linked list
 **********************************************/
template <class T>
class Node
{
   public:
      // constructors
      Node(): pNext(NULL) {}
      Node(const T & t): data(t), pNext(NULL) {}
      
      // members
      Node <T> * pNext;
	  Node <T> * pPrevious;
      T data;
};




#endif // NODE_H
