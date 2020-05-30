#ifndef LinkedList_H
#define LinkedList_H

/**
 * 
 * A simple implementation of a linked list in C++
 * Written by Nathan Nesbitt 2020-05-23
 * 
 * */ 

#include <string>

// Inlcude the headers for the node and linked_list object
#include "errors.h"
#include "list_node.h"

/* LinkedList data structure */
template <class T>
class LinkedList {
    public:
        // Constructor //
        LinkedList<T>();
        LinkedList<T>(T value);
        bool isEmpty();
        int getLength();

        // Add functions //
        void add(T value, int position);
        void addFirst(T value);
        void addLast(T value);
        
        // Get Functions //
        T get(int position);
        T getFirst();
        T getLast();

        // Delete Function //
        void remove(int position);
        
        // Printer //
        void print();

        // Destructor //
        ~LinkedList();
        
    private:
        struct ListNode<T>* startNode;
        int size;

};

// Constructors //

/* Creates an empty link list object */
template <class T> 
LinkedList<T>::LinkedList() {
    startNode = nullptr;
    size = 0;
}

/* Creates a link list object with one value in it */
template <class T> 
LinkedList<T>::LinkedList(T value) {
    ListNode<T>* node = new ListNode<T>();
    node->value = value;
    node->next = nullptr;
    startNode = node;
    size = 1;
}

using namespace std;

/* Gets the length of the linked list */
template <class T> 
int LinkedList<T>::getLength() {
    return size;
}

/* Checks to see if the linked list is empty */
template <class T> 
bool LinkedList<T>::isEmpty() {
    if(size < 1)
        return true;
    return false; 
}

// Functions for generic LinkedList //

/* Adds a generic value into the LinkedList */
template <class T> 
void LinkedList<T>::add(T value, int position) {
    
    ListNode<T> *node = new ListNode<T>(value);
    
    // If the linked list is empty, we just throw it in //
    if(size == 0) {
        node->next = nullptr;
        startNode = node;
    }
    // Else if we tried to push a value beyond n+1 for the current size
    // we return false
    if(position >= size)
        throw OutOfBounds("Index out of bounds when adding " + to_string(position));
    else {
        ListNode<T> *currentNode = startNode;
        
        // Loop through until we have the node before the position //
        while(position != 1) {
            currentNode = currentNode->next;
            position--;
            cout << currentNode->value;
        }

        // Insert the value between the two existing nodes //
        node->next = currentNode->next;
        currentNode->next = node;
    }

    // Finally let's increment the size by 1 //
    size++;
}

/* Adds to the head of the LinkedList */
template <class T>
void LinkedList<T>::addFirst(T value) {
    
    // Create new node with pointer to head as next //
    ListNode<T> *node = new ListNode<T>(value);
    node->next = startNode;
    
    // Reassign //
    startNode = node;
    size++;
}

/* Adds to the tail of the LinkedList */
template <class T>
void LinkedList<T>::addLast(T value) {
    
    // Create the node with null next pointer //
    ListNode<T> *node = new ListNode<T>(value);
    node->next = nullptr;

    // Loop through and set the node until you are at the end //
    ListNode<T> *tempnode = startNode;
    while(tempnode->next) {
        tempnode = tempnode->next;
    }

    // Point to the new node //
    tempnode->next = node;

    size++;
}

/* Gets the n-1th value in the linked list */
template <class T>
T LinkedList<T>::get(int position) {

    // Check to see if the position is greater than the length //
    if(position >= size)
        throw OutOfBounds("Index out of bounds when getting at position " + to_string(position));

    ListNode<T> *currentNode = startNode;

    while(position != 0) {
        currentNode = currentNode->next;
        position--;
    }

    return currentNode->value;

}

/* Gets the head value in the linked list */
template <class T>
T LinkedList<T>::getFirst() {
    return startNode->value;
}

/* Gets the tail value in the linked list */
template <class T>
T LinkedList<T>::getLast() {

    ListNode<T> *currentNode = startNode;

    while(currentNode->next)
        currentNode = currentNode->next;

    return currentNode->value;
}


/* Removes the n-1th node from the linkedlist (starts at 0) */
template <class T>
void LinkedList<T>::remove(int position) {

    // throws error if trying to delete a non-existant node //
    if(position >= size)
        throw OutOfBounds("Index out of bounds when removing at position " + to_string(position));
    
    ListNode<T> *currentNode = startNode;

    // If we are deleting the head we need to remap //
    if(position == 0) {
        startNode = currentNode->next;
        delete currentNode;
    }
    else {
        // Loop through until you get to the n-1th element //  
        while(position != 1) {
            currentNode = currentNode->next;
            position--;
        }
        
        // Delete node and swap with next // 
        ListNode<T>* next_node;
        if(currentNode->next->next)
            next_node = currentNode->next->next;
        else
            next_node = nullptr;
        delete currentNode->next;  
        currentNode->next = next_node; 
    }

    size--;
}

/* Prints out all elements inside of the LinkedList */
template <class T> 
void LinkedList<T>::print() {
    ListNode<T>* node = startNode;

    // While the node isn't null print //
    while(node) {
        cout << node->value << "\n";
        node = node->next;
    } 
};

/* Destructor for the LinkedList */
template <class T> 
LinkedList<T>::~LinkedList() {
    // Create holding classes for nodes //
    ListNode<T>* node = startNode;
    ListNode<T>* node_next;
    // Loop through all of the nodes //
    while(node != nullptr) {
        node_next = node->next;
        delete node;
        node = node_next;
    }
}

#endif