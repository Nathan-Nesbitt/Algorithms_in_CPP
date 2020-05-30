#ifndef ListNode_H
#define ListNode_H

/**
 * 
 * A simple implementation of a LinkedList Node for objects in C++
 * Written by Nathan Nesbitt 2020-05-23
 * 
 * */ 

#include "node.h"

/* Node Class for LinkedLists */
template <class T> 
class ListNode : public Node<T> {
    // Inherits the 
    using Node<T>::Node;
    public:
        ListNode<T> *next; // The next node //
};

#endif