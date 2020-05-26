/**
 * 
 * Tests for linked list in C++
 * Written by Nathan Nesbitt 2020-05-23
 * 
 * */ 

#include <iostream>

#include "errors.h"
#include "linked_list.h"

using namespace std;

/* Main Entry Point for Program */
int main() {

    // Creates a new linked list //
    LinkedList<int> linkList(10);
    linkList.print();

    cout << "\n";

    // Add new value beyond length //
    try{
        linkList.add(12, 22);
    }
    catch(OutOfBounds& error) {
        cout << error.get_error() << "\n";
    }

    linkList.print();

    cout << "\n";

    // Add the value 12 to the end of the link list //
    linkList.addLast(12);
    linkList.print();

    cout << "\n";

    // Add new value between current values //
    linkList.add(11, 1);
    linkList.print();

    cout << "\n";


    // Add another first value //
    linkList.addFirst(9);
    linkList.print();

    cout << "\n";

    // Add another last value //
    linkList.addLast(13);
    linkList.print();
    
    cout << "\n";

    // Removes the first value in the array //
    linkList.remove(0);
    linkList.print();

    // Tries to remove a value outside the scope //
    try {
        linkList.remove(20);
    } catch(OutOfBounds& error) {
        cout << error.get_error() << "\n";
    }

    linkList.print();
    
    cout << "\n";


    // Remove the last value in the linked list //
    linkList.remove(3);
    linkList.print();
    cout << "\n";

    // Gets the first value in the linked list //
    cout << linkList.getFirst() << "\n";
    cout << "\n";

    // Gets the second value in the linked list //
    cout << linkList.get(1) << "\n";
    cout << "\n";

    // Gets the last value in the linked list //
    cout << linkList.getLast() << "\n";
    cout << "\n";

}