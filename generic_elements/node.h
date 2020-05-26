#ifndef NODE_H
#define NODE_H

/**
 * 
 * A simple implementation of a Node for generic objects in C++
 * Written by Nathan Nesbitt 2020-05-23
 * 
 * */ 

// Creates a generic node structure //
template <class T> 
class Node {
    public:
        T value; // The data in the current node //
        Node<T> *next; // The next node //
        Node();
        Node(T new_value);
};

template <class T>
Node<T>::Node() {}

template <class T>
Node<T>::Node(T new_value) {
    value = new_value;
}

#endif